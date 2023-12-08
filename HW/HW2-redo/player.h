#include <iostream>
#include <string>
using namespace std;
class Player
{
private:
    string name;
    string team;
    int goals, assists, penalties;

public:
    Player();
    

    string getName();
    void setNameAndTeam(string name, string team);
    void incrementGoals();
    void incrementPenalty();
    void incrementAssists();
    string getTeam();
    int getGoals();
    int getPenalties();
    int getAssists();
};

