// #include <iostream>
// #include <string>
// using namespace std;
// class Player{
//     public:
//         Player();
//         Player(string n, int g, int a, int p, string t);
//         // int name, goals, penalties;
//     int add_goal(int goal);
//     int add_penalty(int penalties);
//     int add_assists(int assists);
//     string get_name();
//     string get_team();
    
//     private:
//         string name;
//         int goals;
//         int assists;
//         int penalties;
//         string team;
// };
#ifndef PLAYER
#define PLAYER
#include <cmath>
#include <iostream>
#include <string>
#include "team.h"
using namespace std;
class Player
{
private:
    string name;
    string team;
    int goals, assists, penalties;

public:
    Player()
    {
        this->goals = 0;
        this->penalties = 0;
        this->assists = 0;
    }

    string getName()
    {
        return this->name;
    }
    void setNameAndTeam(string name, string team)
    {
        this->name = name;
        this->team = team;
    }
    void incrementGoals()
    {
        this->goals += 1;
    }
    void incrementPenalty()
    {
        this->penalties += 1;
    }
    void incrementAssists()
    {
        this->assists += 1;
    }
    string getTeam()
    {
        return this->team;
    }
    int getGoals()
    {
        return this->goals;
    }
    int getPenalties()
    {
        return this->penalties;
    }
    int getAssists()
    {
        return this->assists;
    }
};



bool closer(Team& r1, Team& r2)
{
    return r1.getWinPercentage() > r2.getWinPercentage();
}
#endif