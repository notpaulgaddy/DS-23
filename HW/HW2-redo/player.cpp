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