#include <cmath>
#include <iostream>

using namespace std;
class Team
{
private:
    std::string name;
    int wins, losses, ties, goals, penalties;
    float winPercent;

public:
    Team();
    
    string getName();
    void setName(string name);
    void incrementGoals(int goals);
    void incrementPenalty();
    void incrementWins();
    void incrementTie();

    void incrementLosses();

    int getWins();
    int getPenalties();
    int getGoals();
    int getLosses();
    int getTies();
    void winPercentage();
    float getWinPercentage();
};
