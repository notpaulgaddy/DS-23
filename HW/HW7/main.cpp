#include <string>
//You may add additional typedefs, includes, etc. up here
#include "Fighter.h"
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
//This is the only array you are allowed to have in your program.
const std::string move_names[7] = {"jab", "forward-tilt", "up-tilt", "down-tilt", "forward-smash", "up-smash", "down-smash"};

//Feel free to put forward declarations here
 

int main(int argc, char** argv){
	Fighter f1;
	// Argument parsing
	if(argc != 4){
		std::cerr << "Proper usage is " << argv[0] << " [database file] [input file] [output file]" << std::endl;
		return -1;
	}

	std::ifstream dbfile(argv[1]);
	if(!dbfile){//the database file
		std::cerr << "Failed to open database " << argv[1] << " for reading." << std::endl;
	}

	std::ifstream infile(argv[2]);//the input file
	if(!infile){
		std::cerr << "Failed to open input " << argv[2] << " for reading." << std::endl;
	}

	std::ofstream outfile(argv[3]);//the output file
	if(!outfile){
		std::cerr << "Failed to open output " << argv[3] << " for writing." << std::endl;
	}

	///////Fill in the rest of main below:
	string characterName;
	string stringOne,stringTwo,stringThree,stringFour,stringFive,stringSix,stringSeven,stringEight;
	int jabs, forwardTilt,upTilt, downTilt, forwardSmash, upSmash, downSmash;

	dbfile >> stringOne >> stringTwo >> stringThree >> stringFour >> stringFive >> stringSix >> stringSeven >> stringEight;//line one
	map<string,unordered_set<Fighter> > characterData;//dont use unordered sets
	
	while(!dbfile.eof()){
		dbfile >> characterName >> jabs >> forwardTilt >> upTilt >> downTilt >> forwardSmash >> upSmash >> downSmash;
		characterData[characterName].insert({jabs, forwardTilt,upTilt, downTilt, forwardSmash, upSmash, downSmash});
	}

	string command, nameMove, numberMove;
	while(!infile.eof()){
		infile >> command >> nameMove >> numberMove;
		if(command=="-q"){//0
			if(characterData.find(nameMove)!=characterData.end()){
				std::unordered_set<Fighter> data = characterData[nameMove];//get the unordered set that matches the figher name as key
				std::unordered_set<Fighter>::iterator it = data.begin();//iterate through this
				if(numberMove=="all"){
					
				}else{
					if(numberMove=="jab"){
						cout << nameMove << numberMove << ": " <<f1.getJabs() << "\n" << endl;
					}else if(numberMove=="forward-tilt"){
						cout << nameMove << numberMove << ": " <<f1.getforwardTilts() << "\n" << endl;
					}else if(numberMove=="up-tilt"){
						cout << nameMove << numberMove << ": " <<f1.getupTilts() << "\n" << endl;
					}else if(numberMove=="down-tilt"){
						cout << nameMove << numberMove << ": " <<f1.getdownTilts() << "\n" << endl;
					}else if(numberMove=="forward-smash"){
						cout << nameMove << numberMove << ": " <<f1.getforwardSmashes() << "\n" << endl;
					}else if(numberMove=="up-smash"){
						cout << nameMove << numberMove << ": " <<f1.getupSmashes() << "\n" << endl;
					}else if(numberMove=="down-smash"){
						cout << nameMove << numberMove << ": " <<f1.getdownSmashes() << "\n" << endl;
					}
				}
			}else{
				cout << "Invalid character name: " << nameMove << endl;
			}
		}else if(command=="-f"){
			std::unordered_set<Fighter> data = characterData[nameMove];//get the unordered set that matches the figher name as key
			std::unordered_set<Fighter>::iterator it = data.begin();//iterate through this
			//Output [limit] number of fighters that have the fastest [move], along with the corresponding frame data.
			int maxNum = stoi(numberMove);//turn the number string to an int

		}else if(command=="-s"){
		//Output [limit] number of fighters that have the slowest [move], along with the corresponding frame data.
			int maxNum = stoi(numberMove);//turn the number string to an int
		}else if(command=="-d"){
		//Output fighters that have a startup frame of [startup frame] for [move].
			int maxNum = stoi(numberMove);//turn the number string to an int
			int indexNum;
			if(nameMove=="jab"){
				std::unordered_set<Fighter> data = characterData[nameMove];//get the unordered set that matches the figher name as key
				std::unordered_set<Fighter>::iterator it = data.begin();//iterate through this
				indexNum = 0;
				advance(it,indexNum);
				int theItem = *it;
			}else if(nameMove=="forward-tilt"){
				indexNum = 1;
			}else if(nameMove=="up-tilt"){
				indexNum = 2;
			}else if(nameMove=="down-tilt"){
				indexNum = 3;
			}else if(nameMove=="forward-smash"){
				indexNum = 4;
			}else if(nameMove=="up-smash"){
				indexNum = 5;
			}else if(nameMove=="down-smash"){
				indexNum = 6;
			}
			
		}
	}



















	return 0;
}
