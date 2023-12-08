#include <string>
//You may add additional typedefs, includes, etc. up here
#include "Fighter.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;
//This is the only array you are allowed to have in your program.
const std::string move_names[7] = {"jab", "forward-tilt", "up-tilt", "down-tilt", "forward-smash", "up-smash", "down-smash"};

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
	// map<string,unordered_set<Fighter> > characterData;//dont use unordered sets
	map<string, set<pair<string, Fighter> > > characterData;

    while(!dbfile.eof()){
        dbfile >> characterName >> jabs >> forwardTilt >> upTilt >> downTilt >> forwardSmash >> upSmash >> downSmash;
        //characterData.insert(make_pair(characterName, set<pair<string, Fighter> > {make_pair("jabs", jabs), make_pair("forwardTilt", forwardTilt), make_pair("upTilt", upTilt), make_pair("downTilt", downTilt), make_pair("forwardSmash", forwardSmash), make_pair("upSmash", upSmash), make_pair("downSmash", downSmash)}));


    }

	string command, nameMove, numberMove;

    string command, nameMove, numberMove;
	while(!infile.eof()){
		infile >> command >> nameMove >> numberMove;
		if(command=="-q"){//character 0
            //check if the name is one of the keys
            for(map<string, set<pair<string, Fighter> > >::iterator it1=characterData.begin();it1!=characterData.end();++it1){
                if(nameMove == it1->first){//if the name matches
                    int maxNum = stoi(numberMove);//turn the number string to an int
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
            }
        }
    }
}