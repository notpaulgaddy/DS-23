#include <iostream>
#include <string>
#include <string.h>
#include "team.h"
using namespace std;

// namespace name

Team::Team(){
    name = "";
    goals = 0;
    penalties = 0;
}

Team::Team(string n, int g, int p){
    name = n;
    goals = g;
    penalties = p;
}

void Team::set_name(string n){

    name = n;
}
string Team::get_name(){
    return name;
}

int Team::set_goal(int goal){
        goals = goal;
        return goals;
    }

int Team::add_penalty(int pen){
        penalties+= pen;
        return penalties;
    }