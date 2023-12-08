#include <string>
// You may add additional typedefs, includes, etc. up here
#include "Fighter.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
// This is the only array you are allowed to have in your program.
const std::string move_names[7] = {"jab",       "forward-tilt",  "up-tilt",
                                   "down-tilt", "forward-smash", "up-smash",
                                   "down-smash"};

// Feel free to put forward declarations here
bool compareGreaterAndAlpa(string a, string b);//boolean to compare the strings if they have the same number, tiebreaker

int main(int argc, char **argv) {
  // Argument parsing
  if (argc != 4) {
    std::cerr << "Proper usage is " << argv[0]
              << " [database file] [input file] [output file]" << std::endl;
    return -1;
  }

  std::ifstream dbfile(argv[1]);
  if (!dbfile) {
    std::cerr << "Failed to open database " << argv[1] << " for reading."
              << std::endl;
  }

  std::ifstream infile(argv[2]);
  if (!infile) {
    std::cerr << "Failed to open input " << argv[2] << " for reading."
              << std::endl;
  }

  std::ofstream outfile(argv[3]);
  if (!outfile) {
    std::cerr << "Failed to open output " << argv[3] << " for writing."
              << std::endl;
  }

  ///////Fill in the rest of main below:

  string characterName;//string for character name
  string stringOne, stringTwo, stringThree, stringFour, stringFive, stringSix,
      stringSeven, stringEight;//strings for first line
  int jabs, forwardTilt, upTilt, downTilt, forwardSmash, upSmash, downSmash;//int for the num of frames per move

  dbfile >> stringOne >> stringTwo >> stringThree >> stringFour >> stringFive >>
      stringSix >> stringSeven >> stringEight; // line one of file
  map<string, Fighter> characterData;       //map called character data with string and fighter class(int)  
  while (!dbfile.eof()) {
    dbfile >> characterName >> jabs >> forwardTilt >> upTilt >> downTilt >>
        forwardSmash >> upSmash >> downSmash;//first line
    // characterData[characterName].insert({"jabs",{jabs}});
    // outfile << characterName << " " << jabs << " " << forwardTilt << " " <<
    // upTilt
    //      << " " << downTilt << " " << forwardSmash << " " << upSmash << " "
    //      << downSmash << endl;
    Fighter character;//make a different class for each fighter
    character.setJab(jabs);//assign num of jabs
    character.setForwardTilt(forwardTilt);//assign num of FT
    character.setUpTilt(upTilt);//assign num of UT
    character.setDownTilt(downTilt);//assign num of DT
    character.setForwardSmash(forwardSmash);//assign num of FS
    character.setUpSmash(upSmash);//assign num of US
    character.setDownSmash(downSmash);//assign num of DS
    characterData[characterName] = character;//assign to char name
  }

  string command, nameMove, numberMove;
  while (!infile.eof()) {
    infile >> command >> nameMove >> numberMove;//read the data from the command file
    if (command == "-q") { // if its q
      map<string, Fighter>::iterator it = characterData.find(nameMove);//iterate thru the names if theyre found
      if (it != characterData
                    .end()) { // if the name is found in the characterData key
        if (numberMove == "all") {//if it says all
          outfile << nameMove << " down-smash"
                  << ": " << it->second.getDownSmash() << endl;//print out the frame for that move
          outfile << nameMove << " down-tilt"
                  << ": " << it->second.getDownTilt() << endl;//print out the frame for that move
          outfile << nameMove << " forward-smash"
                  << ": " << it->second.getForwardSmash() << endl;//print out the frame for that move
          outfile << nameMove << " forward-tilt"
                  << ": " << it->second.getForwardTilt() << endl;//print out the frame for that move
          outfile << nameMove << " jab"
                  << ": " << it->second.getJab() << endl;//print out the frame for that move
          outfile << nameMove << " up-smash"
                  << ": " << it->second.getUpSmash() << endl;//print out the frame for that move
          outfile << nameMove << " up-tilt"
                  << ": " << it->second.getUpTilt() << "\n"//print out the frame for that move
                  << endl;

        } else if (numberMove == "jab") {
          outfile << nameMove << " " << numberMove << ": "//print out the frame for that move
                  << it->second.getJab() << "\n"
                  << endl;
        } else if (numberMove == "forward-tilt") {
          outfile << nameMove << " " << numberMove << ": "//print out the frame for that move
                  << it->second.getForwardTilt() << "\n"
                  << endl;
        } else if (numberMove == "up-tilt") {
          outfile << nameMove << " " << numberMove << ": "//print out the frame for that move
                  << it->second.getUpTilt() << "\n"
                  << endl;
        } else if (numberMove == "down-tilt") {
          outfile << nameMove << " " << numberMove << ": "//print out the frame for that move
                  << it->second.getDownTilt() << "\n"
                  << endl;
        } else if (numberMove == "forward-smash") {
          outfile << nameMove << " " << numberMove << ": "//print out the frame for that move
                  << it->second.getForwardSmash() << "\n"
                  << endl;
        } else if (numberMove == "up-smash") {
          outfile << nameMove << " " << numberMove << ": "//print out the frame for that move
                  << it->second.getUpSmash() << "\n"
                  << endl;
        } else if (numberMove == "down-smash") {
          outfile << nameMove << " " << numberMove << ": "//print out the frame for that move
                  << it->second.getDownSmash() << "\n"
                  << endl;
        } else {
          // print invalid move
          outfile << "Invalid move name: " << numberMove << "\n" << endl;
        }
      } else {
        // output invalid character
        outfile << "Invalid character name: " << nameMove << "\n" << endl;
      }
    } else if (command == "-f") {
      set<string, less<string> > lesserComparison;
      map<string, Fighter>::iterator it = characterData.begin();
      int limit = stoi(numberMove);//convert possible number/string to number
      outfile << "\n"
              << command << " " << nameMove << " " << numberMove << endl;
      for (; it != characterData.end(); it++) {
        string key = "";
        if (nameMove == "jab") {
          key = to_string(it->second.getJab());
        } else if (nameMove == "forward-tilt") {//if its this move
          key = to_string(it->second.getForwardTilt());
        } else if (nameMove == "up-tilt") {//if its this move
          key = to_string(it->second.getUpTilt());
        } else if (nameMove == "down-tilt") {//if its this move
          key = to_string(it->second.getDownTilt());
        } else if (nameMove == "forward-smash") {//if its this move
          key = to_string(it->second.getForwardSmash());
        } else if (nameMove == "up-smash") {
          key = to_string(it->second.getUpSmash());//if its this move
        } else if (nameMove == "down-smash") {//if its this move
          key = to_string(it->second.getDownSmash());
        }
        if (key.size() == 0) {//if empty/not found
          // output invalid move
          cout << "Invalid Move" << endl;
        } else {
          if (key.size() == 1) {
            key = "0" + key;
          }
          key = key + it->first;//print name
          lesserComparison.insert(key);//insert the name
        }
      }
      std::set<string, less<string> >::iterator sit = lesserComparison.begin();
      for (int i = 0; i < limit && sit != lesserComparison.end(); i++) {//iterate thru the lesser comparison
        outfile << sit->substr(2, sit->size() - 2) << " ";
        string spd = sit->substr(0, 2);//iterate thru the first few letters
        if (spd[0] == '0') {
          outfile << spd[1] << endl;
        } else {
          outfile << spd << endl;
        }
        sit++;//keep looping
      }
    } else if (command == "-d") {
      map<string, Fighter>::iterator it = characterData.begin();
      int limit = stoi(numberMove);
      outfile << "\n"
              << command << " " << nameMove << " " << numberMove << endl;
      for (; it != characterData.end(); it++) {
        if (nameMove == "jab") {
          if (it->second.getJab() == limit) {//if its this move equals the limit
            outfile << it->first << endl;
          }
        } else if (nameMove == "forward-tilt") {
          if (it->second.getForwardTilt() == limit) {//if its this move equals the limit
            outfile << it->first << endl;
          }
        } else if (nameMove == "up-tilt") {
          if (it->second.getUpTilt() == limit) {//if its this move equals the limit
            outfile << it->first << endl;
          }
        } else if (nameMove == "down-tilt") {
          if (it->second.getDownTilt() == limit) {//if its this move equals the limit
            outfile << it->first << endl;
          }
        } else if (nameMove == "forward-smash") {
          if (it->second.getForwardSmash() == limit) {//if its this move equals the limit
            outfile << it->first << endl;
          }
        } else if (nameMove == "up-smash") {
          if (it->second.getUpSmash() == limit) {//if its this move equals the limit
            outfile << it->first << endl;
          }
        } else if (nameMove == "down-smash") {
          if (it->second.getDownSmash() == limit) {//if its this move equals the limit
            outfile << it->first << endl;
          }
        }
      }
    } else if (command == "-s") {
      // function pointer to comparer
      bool (*fn_pt)(string, string) = compareGreaterAndAlpa;
      // this refrences the function pointer
      std::set<string, bool (*)(string, string)> greaterComparison(fn_pt);

      map<string, Fighter>::iterator it = characterData.begin();
      int limit = stoi(numberMove);
      outfile << "\n"
              << command << " " << nameMove << " " << numberMove << endl;
      for (; it != characterData.end(); it++) {
        string key = "";
        if (nameMove == "jab") {
          key = to_string(it->second.getJab());//convert to string
        } else if (nameMove == "forward-tilt") {
          key = to_string(it->second.getForwardTilt());//convert to string
        } else if (nameMove == "up-tilt") {
          key = to_string(it->second.getUpTilt());//convert to string
        } else if (nameMove == "down-tilt") {
          key = to_string(it->second.getDownTilt());//convert to string
        } else if (nameMove == "forward-smash") {
          key = to_string(it->second.getForwardSmash());//convert to string
        } else if (nameMove == "up-smash") {
          key = to_string(it->second.getUpSmash());//convert to string
        } else if (nameMove == "down-smash") {
          key = to_string(it->second.getDownSmash());//convert to string
        }

        if (key.size() == 0) {
          // output invalid move
          cout << "Invalid Move" << endl;
        } else {
          if (key.size() == 1) {
            key = "0" + key;
          }
          key = key + it->first;
          greaterComparison.insert(key);
        }
      }
      std::set<string, less<string> >::iterator sit = greaterComparison.begin();
      for (int i = 0; i < limit && sit != greaterComparison.end(); i++) {
        outfile << sit->substr(2, sit->size() - 2) << " ";
        string spd = sit->substr(0, 2);
        if (spd[0] == '0') {
          outfile << spd[1] << endl;
        } else {
          outfile << spd << endl;
        }
        sit++;//keep iterating
      }
    }
  }
  return 0;
}

bool compareGreaterAndAlpa(string a, string b) {
  if (a.substr(0, 2) > b.substr(0, 2)) {
    return true;
  } else if (a.substr(0, 2) == b.substr(0, 2) &&
             a.substr(2, a.size() - 2) < b.substr(2, b.size() - 2)) {
    return true;
  }
  return false;
}