#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

enum direction {//enumeration for each different vector
  invalid = -1,
  horizontalLeftToRight,
  horizontalRightToLeft,
  verticalTopToBottom,
  verticalBottomToTop,
  diagonalDownAndRight,
  diagonalDownAndLeft,
  diagonalUpAndRight,
  diagonalUpAndLeft,
};
// print out words for each board
void findViable(vector<string> grid, direction &dir, int height, int width,
                int &posx, int &posy, string word) {
  if (word.length() > height && word.length() > width) {//check if there's enough space to go in x direction
    dir = direction::invalid;//then its invalid
  }
  int wordLength = word.length();//get the width
  for (int x2 = 0; x2 < width; x2++) {//iterate thru the length
    for (int y2 = 0; y2 < height; y2++) {//iterate thru the height
      bool fitsRight = (width - x2) >= word.length();
      bool fitsLeft = x2 >= wordLength;
      bool fitsDown = (height - y2) >= wordLength;
      bool fitsUp = y2 >= wordLength;
      if (fitsRight) { // can we fit this left to right
        bool pass = true;
        for (int k = 0; k < wordLength; k++) {//iterate thru each letter of each word
          if (grid[y2][k + x2] != '*' && grid[y2][k + x2] != word[k]) {//check if the current letter isnt filled with *
            pass = false;
            break;
          }
        }
        if (pass) {
          posx = x2;
          posy = y2;
          dir = horizontalLeftToRight;
          return;
        }
      }
      if (fitsLeft) // check reverse
      {
        bool pass = true;
        for (int k = 0; k < wordLength; k++) {//iterate thru each letter of each word
          if (grid[y2][k] != '*' && grid[y2][k] != word[k]) {//check if the current letter isnt filled with *
            pass = false;
            break;
          }
        }
        if (pass) {
          posx = x2;
          posy = y2;
          dir = horizontalRightToLeft;
          return;
        }
      }
      if (fitsDown) { // check down
        bool pass = true;
        for (int k = 0; k < wordLength; k++) {//iterate thru each letter of each word
          if (grid[y2 + k][x2] != '*' && grid[y2 + k][x2] != word[k]) {//check if the current letter isnt filled with *
            pass = false;
            break;
          }
        }
        if (pass) {
          posx = x2;
          posy = y2;
          dir = verticalTopToBottom;
          return;
        }
      }
      if (fitsUp) {
        bool pass = true;
        for (int k = 0; k < wordLength; k++) {//iterate thru each letter of each word
          if (grid[k][x2] != '*' && grid[k][x2] != word[k]) {//check if the current letter isnt filled with *
            pass = false;
            break;
          }
        }
        if (pass) {
          posx = x2;
          posy = y2;
          dir = verticalBottomToTop;
          return;
        }
      }
      if (fitsRight && fitsDown) { // diag down right
        bool pass = true;
        for (int k = 0; k < wordLength; k++) {//iterate thru each letter of each word
          if (grid[y2 + k][x2 + k] != '*' && grid[y2 + k][x2 + k] != word[k]) {//check if the current letter isnt filled with *
            pass = false;
            break;
          }
        }
        if (pass) {
          posx = x2;
          posy = y2;
          dir = diagonalDownAndRight;
          return;
        }
      }
      if (fitsDown && fitsLeft) { // diag down left
        bool pass = true;
        for (int k = 0; k < wordLength; k++) {//iterate thru each letter of each word
          if (grid[y2 + k][x2 - k] != '*' && grid[y2 + k][x2 - k] != word[k]) {//check if the current letter isnt filled with *
            pass = false;
            break;
          }
        }
        if (pass) {
          posx = x2;
          posy = y2;
          dir = diagonalDownAndLeft;
          return;
        }
      }
      if (fitsUp && fitsRight) { // diag up right
        bool pass = true;
        for (int k = 0; k < wordLength; k++) {//iterate thru each letter of each word
          if (grid[y2 - k][x2 + k] != '*' && grid[y2 - k][x2 + k] != word[k]) {//check if the current letter isnt filled with *
            pass = false;
            break;
          }
        }
        if (pass) {
          posx = x2;
          posy = y2;
          dir = diagonalUpAndRight;
          return;
        }
      }
      if (fitsUp && fitsLeft) { // diag up left
        bool pass = true;
        for (int k = 0; k < wordLength; k++) {//iterate thru each letter of each word
          if (grid[y2 - k][x2 - k] != '*' && grid[y2 - k][x2 - k] != word[k]) {//iterate thru each letter of each word
            pass = false;
            break;
          }
        }
        if (pass) {
          posx = x2;
          posy = y2;
          dir = diagonalUpAndLeft;
          return;
        }
      }
    }
  }
  dir = invalid;
}
void insertWord(vector<string> &grid, direction &dir, int height, int width,
                int &posx, int &posy, string word) {
  for (int k = 0; k < word.length(); k++) {
    // check direction param
    if (dir == horizontalLeftToRight) {
      grid[posy][posx + k] = word[k]; // left to right
    } else if (dir == horizontalRightToLeft) {
      grid[posy][posx - k] = word[k]; // right to left
    } else if (dir == verticalTopToBottom) {//top to bottom
      grid[posy + k][posx] = word[k];
    } else if (dir == verticalBottomToTop) {//bottom to top
      grid[posy - k][posx] = word[k];
    } else if (dir == diagonalDownAndRight) {//diagonal down then right
      // add to y and x
      // x+1,y-1
      grid[posy + k][posx + k] = word[k];
    } else if (dir == diagonalDownAndLeft) {//diagonal down then left
      grid[posy + k][posx - k] = word[k];
    } else if (dir == diagonalUpAndRight) {//diagonal up then right
      grid[posy - k][posx + k] = word[k];
    } else if (dir == diagonalUpAndLeft) {//diagonal up then left
      grid[posy - k][posx - k] = word[k];
    }
  }
}

void gridFill(vector<string> &grid, char letter, int height, int width) {//fill the grid with characters
  // fill in holes
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      if (grid[j][i] == '*') {//start making each letter a *
        grid[j][i] = letter; // assign the random letter to a
                             // value in the matrix
      }
    }
  }
}

void gridMake(vector<string> &solution, int height, int width,
              vector<string>::iterator plusWords,
              vector<string>::iterator plusWordEnd) {//start making the grid
  if (plusWords == plusWordEnd) {
    return;
  }
  string word = *plusWords;//pointer to each word that should appear
  int x = 0;
  int y = 0;
  direction dir = direction::invalid;
  findViable(solution, dir, height, width, x, y, word);
  if (dir != direction::invalid) {//if direction isnt invalid
    // place word.
    insertWord(solution, dir, height, width, x, y, word);
    // go to next word
    gridMake(solution, height, width, plusWords + 1, plusWordEnd);
  } else {
    // not all words could be placed
    solution.clear();
  }
}
bool gridCheck(vector<string> solution, int height, int width,
               vector<string>::iterator minuseWords,
               vector<string>::iterator minuseWordEnd) {//check the grid to make sure we have everything
  if (minuseWords == minuseWordEnd) { // at the end we didn't find any
    return true;
  }
  direction dir = direction::invalid;
  int x;
  int y;
  findViable(solution, dir, height, width, x, y,
             *minuseWords); // checks for a spot that matchs this word.
  if (dir == invalid)       // if direction is invalid then keep searching list
  {
    return gridCheck(solution, height, width, minuseWords + 1, minuseWordEnd);//THE RECURSIVE STATEMENT
  } else {
    // found a valid direction that word could go in.
    return false;
  }
}

void gridFlip(vector<string> source, vector<string> &grid, int height,
              int width) {
  std::copy(source.begin(), source.end(), grid.begin());//make a copy
  std::reverse(grid.begin(), grid.end());//then reverse it
}

void gridRotate(vector<string> source, vector<string> &grid, int height,
                int width) {
  for (int i = 0; i < height; i++) {//iterate thru each y coord
    for (int j = 0; j < width; j++) {//iterate thru each x coord
      grid[i][width - j - 1] = source[i][j];//rotate it
    }
  }
}

bool gridNotExist(vector<vector<string> > grids, vector<string> grid) {
  for (vector<vector<string> >::iterator current = grids.begin();
       current != grids.end(); current++) {
    int matchCount = 0;
    for (int i = 0; i < current->size(); i++) {
      if ((*current)[i] == grid[i]) {//check if theres a match
        matchCount++;//increment by 1
      }
    }
    if (matchCount == current->size()) {
      return false;
    }
  }
  return true;
}

void gridMakeFillFlipRotate(vector<vector<string> > &grids, int height,
                            int width, vector<string> plusWord,
                            vector<string> minusWord, string answer,
                            vector<string> grid, char letter) {
  gridFill(grid, letter, height, width);
  if (gridCheck(grid, height, width, minusWord.begin(), minusWord.end())) {
    if (gridNotExist(grids, grid)) {
      grids.insert(grids.begin(), grid);
    }

    if (answer == "one_solution") {//if they want one solution
      return;
    } else {
      vector<string> tempGrid;//make vector of strings called temporary grid
      for (int i = 0; i < height; i++) {
        string line = "";//make a blank string
        for (int j = 0; j < width; j++) {
          line = line + "*";//make the new char *
        }
        tempGrid.push_back(line);//add the * to string
      }
      gridFlip(grid, tempGrid, height, width);
      if (tempGrid.size() != 0 &&
          gridCheck(tempGrid, height, width, minusWord.begin(),
                    minusWord.end()) &&
          gridNotExist(grids, tempGrid)) {
        grids.push_back(tempGrid);
      }
      vector<string> tempGrid2;//make a 2nd grid
      for (int i = 0; i < height; i++) {
        string line = "";//make a blank string
        for (int j = 0; j < width; j++) {
          line = line + "*";//make the new char *
        }
        tempGrid2.push_back(line);
      }
      gridRotate(tempGrid, tempGrid2, height, width);
      if (tempGrid2.size() != 0 &&
          gridCheck(tempGrid2, height, width, minusWord.begin(),
                    minusWord.end()) &&
          gridNotExist(grids, tempGrid2)) {//check if it meets the requiremenents
        grids.push_back(tempGrid2);//add the new grid vector
      }

      tempGrid.clear();
      for (int i = 0; i < height; i++) {
        string line = "";//empty string
        for (int j = 0; j < width; j++) {
          line = line + "*";//make the char *
        }
        tempGrid.push_back(line);
      }
      gridRotate(grid, tempGrid, height, width);//rotate it
      if (tempGrid.size() != 0 &&
          gridCheck(tempGrid, height, width, minusWord.begin(),
                    minusWord.end()) &&
          gridNotExist(grids, tempGrid)) {
        grids.push_back(tempGrid);
      }
      tempGrid2.clear();
      for (int i = 0; i < height; i++) {
        string line = "";
        for (int j = 0; j < width; j++) {
          line = line + "*";
        }
        tempGrid2.push_back(line);
      }
      gridFlip(tempGrid, tempGrid2, height, width);
      if (tempGrid2.size() != 0 &&
          gridCheck(tempGrid2, height, width, minusWord.begin(),
                    minusWord.end()) &&
          gridNotExist(grids, tempGrid2)) {
        grids.push_back(tempGrid2);
      }
    }
  }
}
bool gridNeedsFill(vector<string> grid) {//if the grid needs more letters
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] == '*') {//make it *
        return true;
      }
    }
  }
  return false;
}

void gridMakeFlipRotate(vector<vector<string> > &grids, int height, int width,
                        vector<string> plusWord, vector<string> minusWord,
                        string answer) {
  vector<string> grid;

  for (int i = 0; i < height; i++) {
    string line = "";
    for (int j = 0; j < width; j++) {
      line = line + "*";
    }
    grid.push_back(line);
  }
  gridMake(grid, height, width, plusWord.begin(), plusWord.end());
  if (grid.size() != 0) {
    if (gridNeedsFill(grid)) {
      for (char lwalpCh = 'a'; lwalpCh <= 'z';
           lwalpCh++) { // loop through each letter for fill

        gridMakeFillFlipRotate(grids, height, width, plusWord, minusWord,
                               answer, grid,
                               lwalpCh); // fill empty spots with letter
      }
    } else {
      gridMakeFillFlipRotate(grids, height, width, plusWord, minusWord, answer,
                             grid, 'a'); // no fill needed so just pass 'a'
    }
  }
}
void gridMirror(vector<vector<string> > &grids, vector<string> grid, int height,
                int width, vector<string> minusWord) {
  vector<string> tempGrid;
  for (int i = 0; i < height; i++) {
    string line = "";
    for (int j = 0; j < width; j++) {
      line += grid[j][i];
    }
    tempGrid.push_back(line);
  }
  if (gridCheck(tempGrid, height, width, minusWord.begin(), minusWord.end()) &&
      gridNotExist(grids, tempGrid)) {
    grids.push_back(tempGrid);
  }
}
int main(int argc, char *argv[]) {

  std::ifstream inputfile(argv[1]);  // input file name
  std::ofstream outputfile(argv[2]); // output file nam,e
  string answer = argv[3];           // either one solution or all solutions

  if (!inputfile.good()) { // check that the first file can be opened
    std::cerr << "Can't open " << argv[1] << " to read.\n";
    exit(1);
  }

  vector<char> letters;     // vector for each letter of the alphabet
  vector<string> plusWord;  //+ arts
  vector<string> minusWord; //- ear
  vector<vector<string> > grids;
  int width, height;
  string word;
  string sign;

  inputfile >> width >> height;//get the width then height
  while (!inputfile.eof()) {
    inputfile >> sign >> word;
    if (sign[0] == '+') { // if it starts with a +
      plusWord.push_back(word);
    } else if (sign[0] == '-') { // if it starts with a -
      minusWord.push_back(word);
    }
  }

  for (int count = 0; count < 2; count++) {
    gridMakeFlipRotate(grids, height, width, plusWord, minusWord, answer);

    if (answer != "one_solution" || grids.size() == 0) {
      std::reverse(plusWord.begin(), plusWord.end());
      gridMakeFlipRotate(grids, height, width, plusWord, minusWord, answer);
    }

    if (answer != "one_solution" || grids.size() == 0) {
      std::reverse(plusWord.begin(), plusWord.end());
      vector<string>::iterator it = plusWord.begin();
      for (int i = 0; it != plusWord.end(); it++, i++) {
        if (i % 2 == 0) {
          string temp = plusWord[i];
          reverse(temp.begin(), temp.end());
          plusWord[i] = temp;
        }
      }
      gridMakeFlipRotate(grids, height, width, plusWord, minusWord, answer);
      it = plusWord.begin();
      for (int i = 0; it != plusWord.end(); it++, i++) {
        if (i % 2 == 0) {
          string temp = plusWord[i];
          reverse(temp.begin(), temp.end());
          plusWord[i] = temp;
        }
      }
    }

    if (answer != "one_solution" || grids.size() == 0) {//check if its empty
      gridMakeFlipRotate(grids, height, width, plusWord, minusWord, answer);
    }
    std::rotate(plusWord.begin(), plusWord.begin() + 1, plusWord.begin() + 2);
    std::rotate(plusWord.rbegin(), plusWord.rbegin() + 1,
                plusWord.rbegin() + 2);
    int t = 0;
  }

  vector<vector<string> > finalList;
  if (width == height) {
    for (vector<vector<string> >::iterator it = grids.begin(); it != grids.end();
         it++) {
      gridMirror(finalList, (*it), height, width, minusWord);
      finalList.push_back(*it);
    }
    grids = finalList;
  }

  if (grids.size() == 0) {
    cout << "No Solution";
    exit(1);
  }


  if (answer == "one_solution") {//final one_solution print
    cout << "Board:" << endl;
    outputfile << "Board: " << endl;
    std::vector<std::string> &firstGrid = grids[0]; // get the first grid only
    for (std::vector<std::string>::iterator grid = firstGrid.begin();
         grid != firstGrid.end(); grid++) {
      std::cout << " " << (*grid) << std::endl; // print the first item only
      outputfile << " " << (*grid) << std::endl;
    }
  } else if (answer == "all_solutions") {//final all_solutions print
    cout << grids.size() << " solution(s)" << endl;
    outputfile << grids.size() << " solution(s)" << endl;
    for (vector<vector<string> >::iterator start = grids.begin();
         start != grids.end(); start++) {

      cout << "Board:" << endl;
      outputfile << "Board:" << endl;
      for (vector<string>::iterator grid = start->begin(); grid != start->end();
           grid++) {
        cout << " " << (*grid) << endl;
        outputfile << " " << (*grid) << endl;
      }
    }
  }
}