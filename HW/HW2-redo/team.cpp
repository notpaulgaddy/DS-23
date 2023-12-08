#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "team.h"
#include "player.h"
#include <string.h>
#include <map>
#include <iomanip>
#include <cmath>
#include <algorithm>

Team::Team(){
    // string name;
    // int wins, losses, ties, goals, penalties;
    // float winPercent;
    this->goals = 0;
    this->penalties = 0;
    this->wins = 0;
    this->losses = 0;
    this->ties = 0;
    this->winPercent = 0;
}
string Team::getName(){
    return this->name;
}
void Team::setName(){
    this->name = name;
}

//     {
//         return this->name;
//     }
// class Team
// {
// private:
//     string name;
//     int wins, losses, ties, goals, penalties;
//     float winPercent;

// public:
//     Team()
//     {
//         this->goals = 0;
//         this->penalties = 0;
//         this->wins = 0;
//         this->losses = 0;
//         this->ties = 0;
//         this->winPercent = 0;
//     }

//     string getName()
//     {
//         return this->name;
//     }
//     void setName(string name)
//     {
//         this->name = name;
//     }
//     void incrementGoals(int goals)
//     {
//         this->goals += goals;
//     }
//     void incrementPenalty()
//     {
//         this->penalties += 1;
//     }

//     void incrementWins()
//     {
//         this->wins += 1;
//     }
//     void incrementTie()
//     {
//         this->ties += 1;
//     }

//     void incrementLosses()
//     {
//         this->losses += 1;
//     }

//     int getWins()
//     {
//         return this->wins;
//     }
//     int getPenalties()
//     {
//         return this->penalties;
//     }
//     int getGoals()
//     {
//         return this->goals;
//     }
//     int getLosses()
//     {
//         return this->losses;
//     }
//     int getTies()
//     {
//         return this->ties;
//     }
//     void winPercentage()
//     {

//         this->winPercent = ceil((this->getWins() + 0.5 * this->getTies()) / (this->getWins() + this->getTies() + this->getLosses()) * 100) / 100;
//     }
//     float getWinPercentage()
//     {
//         return this->winPercent;
//     }
// };