#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string.h>
#include <iomanip>
#include <cmath>
using namespace std;
#include "team.h"

Team::Team(){
    goals = 0;
    penalties = 0;
    wins = 0;
    losses = 0;
    ties = 0;
    winPercent = 0;
}
Team::Team(int g, int p, int w, int l, int t, float wp, string n){
    goals = g;
    penalties = p;
    wins = w;
    losses = l;
    ties = t;
    winPercent = wp;
    name = n;
}
string Team::getName() const{
    return name;
}
int Team::getWins() const{
    return wins;
}
int Team::getPenalties() const{
    return penalties;
}
int Team::getGoals() const{
    return goals;
}
int Team::getLosses() const{
    return losses;
}
int Team::getTies() const{
    return ties;
}
float Team::getWinPercentage() const{
    return winPercent;
}
void Team::setName(string name){//set each name
    this->name = name;
}
void Team::incrementGoals(int goals){//increment the goals
    this->goals += goals;
}
void Team::incrementPenalty(){//increment penalties
    this->penalties += 1;
}
void Team::incrementWins(){
    this->wins += 1;
}
void Team::incrementTie(){
    this->ties += 1;
}
void Team::incrementLosses(){
    this->losses += 1;
}
void Team::winPercentage(){
    this->winPercent = ceil((this->getWins() + 0.5 * this->getTies()) / (this->getWins() + this->getTies() + this->getLosses()) * 100) / 100;
}