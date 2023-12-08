// #include <algorithm>
// #include <fstream>
// #include <iostream>
// #include <vector>

// int main(int argc, char* argv[]){

// }

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
// #include "name.h"
using namespace std;

int main(int argc, char* argv[]) {
    ifstream in_str(argv[1]);
    if (!in_str.good()) {
        cerr << "Can't open " << argv[3] << " to read.\n";
        exit(1);
    }
    string line;
    int game;
    vector<string> doc;
    unordered_map<int,vector<string> > games;//games dictionary
    unordered_map<string, vector<string> >  players; //players dictionary
    // while (in_str >> line) {
    while (getline(in_str, line)) {
        doc.push_back(line);
        if (line == "FINAL") {
            game+=1;
        }else{
            // if(games.find(game) != games.end()){
            if(games.count(game) > 0){
                games[game].push_back(line);
            }else{
                games[game] = {line};
            }
        }
    }

    return 0;
}
