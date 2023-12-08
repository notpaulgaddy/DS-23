// #include <string>
// using namespace std;
// class Team{
//     public:
//         Team();
//         Team(std::string n, int g, int p);
//         // int name, goals, penalties;
//     int set_goal(int goal);
//     int add_penalty(int penalties);
//     void set_name(std::string n);
//     std::string get_name();
//     private:
//         string name;
//         int goals;
//         int penalties;
// };
#ifndef TEAM
#define TEAM
#include <cmath>
#include <iostream>
class Team
{
private:
    string name;
    int wins, losses, ties, goals, penalties;
    float winPercent;

public:
    Team()
    {
        this->goals = 0;
        this->penalties = 0;
        this->wins = 0;
        this->losses = 0;
        this->ties = 0;
        this->winPercent = 0;
    }

    string getName()
    {
        return this->name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void incrementGoals(int goals)
    {
        this->goals += goals;
    }
    void incrementPenalty()
    {
        this->penalties += 1;
    }

    void incrementWins()
    {
        this->wins += 1;
    }
    void incrementTie()
    {
        this->ties += 1;
    }

    void incrementLosses()
    {
        this->losses += 1;
    }

    int getWins()
    {
        return this->wins;
    }
    int getPenalties()
    {
        return this->penalties;
    }
    int getGoals()
    {
        return this->goals;
    }
    int getLosses()
    {
        return this->losses;
    }
    int getTies()
    {
        return this->ties;
    }
    void winPercentage()
    {

        this->winPercent = ceil((this->getWins() + 0.5 * this->getTies()) / (this->getWins() + this->getTies() + this->getLosses()) * 100) / 100;
    }
    float getWinPercentage()
    {
        return this->winPercent;
    }
};
#endif