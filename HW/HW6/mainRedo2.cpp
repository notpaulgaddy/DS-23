// #include <algorithm>
// #include <fstream>
// #include <iostream>
// #include <stdlib.h>
// #include <vector>
// using namespace std;

// enum direction {
//   invalid = -1,
//   horizontalLeftToRight,
//   horizontalRightToLeft,
//   verticalTopToBottom,
//   verticalBottomToTop,
//   diagonalDownAndRight,
//   diagonalDownAndLeft,
//   diagonalUpAndRight,
//   diagonalUpAndLeft,
// };
// // print out words for each board
// void findViable(vector<string> grid, direction &dir, int height, int width,
//                 int &posx, int &posy, string word) {
//   if (word.length() > height && word.length() > width) {//if the length of the word is greater than the height anf the length of the word is greater than the width
//     dir = direction::invalid;//then the direction is invalid
//   }
//   int wordLength = word.length();
//   for (int y2 = 0; y2 < height; y2++) {
//     for (int x2 = 0; x2 < width; x2++) {
//       if ((width - x2) >= word.length()) { // can we fit this left to right
//         bool pass = true;
//         for (int k = 0; k < wordLength; k++) {
//           if (grid[y2][k + x2] != '*' && grid[y2][k + x2] != word[k]) {
//             pass = false;
//             break;
//           }
//         }
//         if (pass) {
//           posx = x2;
//           posy = y2;
//           dir = horizontalLeftToRight;
//           return;
//         }
//       }
//       if (x2 >= wordLength) // check reverse
//       {
//         bool pass = true;
//         for (int k = 0; k < wordLength; k++) {
//           if (grid[y2][k] != '*' && grid[y2][k] != word[k]) {
//             pass = false;
//             break;
//           }
//         }
//         if (pass) {
//           posx = x2;
//           posy = y2;
//           dir = horizontalRightToLeft;
//           return;
//         }
//       }
//       if ((height - y2) >= wordLength) { // check down
//         bool pass = true;
//         for (int k = 0; k < wordLength; k++) {
//           if (grid[y2 + k][x2] != '*' && grid[y2 + k][x2] != word[k]) {
//             pass = false;
//             break;
//           }
//         }
//         if (pass) {
//           posx = x2;
//           posy = y2;
//           dir = verticalTopToBottom;
//           return;
//         }
//       }
//       if (y2 >= wordLength) {
//         bool pass = true;
//         for (int k = 0; k < wordLength; k++) {
//           if (grid[k][x2] != '*' && grid[k][x2] != word[k]) {
//             pass = false;
//             break;
//           }
//         }
//         if (pass) {
//           posx = x2;
//           posy = y2;
//           dir = verticalBottomToTop;
//           return;
//         }
//       }
//       if ((height - y2) >= wordLength &&
//           (width - x2) >= word.length()) { // diag down right
//         bool pass = true;
//         for (int k = 0; k < wordLength; k++) {
//           if (grid[y2 + k][x2 + k] != '*' && grid[y2 + k][x2 + k] != word[k]) {
//             pass = false;
//             break;
//           }
//         }
//         if (pass) {
//           posx = x2;
//           posy = y2;
//           dir = diagonalDownAndRight;
//           return;
//         }
//       }
//       if ((height - y2) >= wordLength && x2 >= wordLength) { // diag down left
//         bool pass = true;
//         for (int k = 0; k < wordLength; k++) {
//           if (grid[y2 + k][x2 - k] != '*' && grid[y2 + k][x2 - k] != word[k]) {
//             pass = false;
//             break;
//           }
//         }
//         if (pass) {
//           posx = x2;
//           posy = y2;
//           dir = diagonalDownAndLeft;
//           return;
//         }
//       }
//       if (y2 >= wordLength && (width - x2) >= word.length()) { // diag up right
//         bool pass = true;
//         for (int k = 0; k < wordLength; k++) {
//           if (grid[y2 - k][x2 + k] != '*' && grid[y2 - k][x2 + k] != word[k]) {
//             pass = false;
//             break;
//           }
//         }
//         if (pass) {
//           posx = x2;
//           posy = y2;
//           dir = diagonalUpAndRight;
//           return;
//         }
//       }
//       if (y2 >= wordLength && x2 >= wordLength) { // diag up left
//         bool pass = true;
//         for (int k = 0; k < wordLength; k++) {
//           if (grid[y2 - k][x2 - k] != '*' && grid[y2 - k][x2 - k] != word[k]) {
//             pass = false;
//             break;
//           }
//         }
//         if (pass) {
//           posx = x2;
//           posy = y2;
//           dir = diagonalUpAndLeft;
//           return;
//         }
//       }
//     }
//   }
//   dir = invalid;
// }
// void insertWord(vector<string> &grid, direction &dir, int height, int width,
//                 int &posx, int &posy, string word) {
//   for (int k = 0; k < word.length(); k++) {
//     // check direction param
//     if (dir == horizontalLeftToRight) {
//       grid[posy][posx + k] = word[k]; // left to right
//     } else if (dir == horizontalRightToLeft) {
//       grid[posy][posx - k] = word[k]; // right to left
//     } else if (dir == verticalTopToBottom) {
//       grid[posy + k][posx] = word[k];//top to bottom
//     } else if (dir == verticalBottomToTop) {
//       grid[posy - k][posx] = word[k];//bottom to top
//     } else if (dir == diagonalDownAndRight) {
//       // add to y and x
//       // x+1,y-1
//       grid[posy + k][posx + k] = word[k];
//     } else if (dir == diagonalDownAndLeft) {
//       grid[posy + k][posx - k] = word[k];
//     } else if (dir == diagonalUpAndRight) {
//       grid[posy - k][posx + k] = word[k];
//     } else if (dir == diagonalUpAndLeft) {
//       grid[posy - k][posx - k] = word[k];
//     }
//   }
// }

// void gridFill(vector<string> &grid, vector<char> letters, int height,
//               int width) {
//   // fill in holes
//   for (int i = 0; i < width; i++) {
//     for (int j = 0; j < height; j++) {
//       if (grid[j][i] == '*') {
//         int randomIndex = rand() % letters.size() -
//                           1; // get a random letter from the alphabet
//         grid[j][i] = letters[randomIndex]; // assign the random letter to a
//                                            // value in the matrix
//       }
//     }
//   }
// }

// void gridMake(vector<string> &solution, vector<char> letters, int height,
//               int width, vector<string>::iterator plusWords,
//               vector<string>::iterator plusWordEnd) {
//   string word = *plusWords;
//   if (plusWords == plusWordEnd) {
//     return;
//   }
//   int x = 0;
//   int y = 0;
//   direction dir = direction::invalid;
//   findViable(solution, dir, height, width, x, y, word);
//   if (dir != direction::invalid) {
//     // place word.
//     insertWord(solution, dir, height, width, x, y, word);
//     // go to next word
//     gridMake(solution, letters, height, width, plusWords + 1, plusWordEnd);
//   } else {
//     // not all words could be placed
//     // solution.clear();
//   }
// }
// bool gridCheck(vector<string> solution, int height, int width,
//                vector<string>::iterator minuseWords,
//                vector<string>::iterator minuseWordEnd) {
//   if (minuseWords == minuseWordEnd) { // at the end we didn't find any
//     return true;
//   }
//   direction dir = direction::invalid;
//   int x;
//   int y;
//   findViable(solution, dir, height, width, x, y,
//              *minuseWords); // checks for a spot that matchs this word.
//   if (dir == invalid)       // if direction is invalid then keep searching list
//   {
//     return gridCheck(solution, height, width, minuseWords + 1, minuseWordEnd);
//   } else {
//     // found a valid direction that word could go in.
//     return false;
//   }
// }

// int main(int argc, char *argv[]) {
  
// //   std::ifstream inputfile("./puzzle3.txt");//argv[1]);  // input file name
//     std::ifstream inputfile(argv[1]);//argv[1]);  // input file name
//   //std::ifstream outputfile(argv[2]); // output file nam,e
//   string answer = "";//argv[3];           // either one solution or all solutions

//   if (!inputfile.good()) { // check that the first file can be opened
//     std::cerr << "Can't open " << argv[1] << " to read.\n";
//     exit(1);
//   }

//   vector<char> letters;     // vector for each letter of the alphabet
//   vector<string> plusWord;  //+ arts
//   vector<string> minusWord; //- ear
//   int width, height;
//   string word;
//   string sign;
//   inputfile >> width >> height;
//   while (!inputfile.eof()) {
//     inputfile >> sign >> word;
//     if (sign[0] == '+') { // if it starts with a +
//       plusWord.push_back(word);
//     } else if (sign[0] == '-') { // if it starts with a -
//       minusWord.push_back(word);
//     }
//   }
//   for (char lwalpCh = 'a'; lwalpCh <= 'z'; lwalpCh++) {
//     bool validChar = true;
//     for (int i = 0; i < minusWord.size();
//          i++) { // looking for invalid characters that could give a false fail
//       if (minusWord[i].find(lwalpCh) == string::npos) {
//         validChar = false;
//         break;
//       }
//     }
//     if (validChar) {              // if not found, then safe to add
//       letters.push_back(lwalpCh); // add each letter of alphabet to the vector
//     }
//   }
//   if (letters.size() == 0) {
//     letters.push_back('a' );
//   }
//   vector<vector<string> > grids;
//   for (int i = 0; i < plusWord.size(); i++) {
//     vector<string> grid;
//     for (int i = 0; i < width; i++) {
//       string line = "";
//       for (int j = 0; j < height; j++) {
//         line = line + "*";
//       }
//       grid.push_back(line);
//     }
//     gridMake(grid, letters, height, width, plusWord.begin(), plusWord.end());
//     gridFill(grid, letters, height, width);
//     if (gridCheck(grid, height, width, minusWord.begin(), minusWord.end())) {
//       grids.insert(grids.begin(), grid);
//       if (answer == "one_solution") {
//         break;
//       }
//     }
//     rotate(plusWord.begin(), plusWord.begin() + 1, plusWord.end());
//   }
//   // create rotation of all solutions
//   // create mirror of all solutions
//   // remove solutions that
//   cout << grids.size() << " solution(s)" << endl;
//   for (vector<vector<string> >::iterator start = grids.begin();
//        start != grids.end(); start++) {

//     cout << "Board:" << endl;
//     for (vector<string>::iterator grid = start->begin(); grid != start->end();
//          grid++) {
//       cout << "  " << (*grid) << endl;
//     }
//   }
//   // gridMake(letters, width, height, plusWord, minusWord);
//   if (answer == "one_solution") {
      
//   } 
//   else if (answer == "all_solutions") {
//   }
// }