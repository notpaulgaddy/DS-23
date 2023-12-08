#include <string>
using namespace std;

class Player
{
private:
    string name;//string for the name
    string team;//string for the team
    int goals, assists, penalties;//int for each of the goals, assists and penalties

public:
    Player();

    string getName();//get the name
    void setNameAndTeam(string name, string team);//setter for the name and team

    void incrementGoals();//increment the goals and penalties
    void incrementPenalty();//increment penalties
    void incrementAssists();//increment assists

    string getTeam();//get the team 
    int getGoals();//get the amount of goals
    int getPenalties();//get the amoutn of penalties
    int getAssists();//get the amount of assists
};