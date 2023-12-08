#include <string>
using namespace std;

class Team{
    public:
        Team();//initialize team
        Team(int g, int p, int w, int l, int t, float wp, string n);//setup all the variables

        string getName() const;//get the names
        int getWins() const;//get the amt of wins
        int getPenalties() const;//get the amt of penalties
        int getGoals() const;//get the amt of goals
        int getLosses() const;//get the amt of losses
        int getTies() const;//get the amt of ties
        float getWinPercentage() const;//get the win %

        void setName(string name);//set the name

        void incrementGoals(int goals);
        void incrementPenalty();
        void incrementWins();
        void incrementTie();
        void incrementLosses();
        void winPercentage();
    private:
        string name;
        int wins, losses, ties, goals, penalties;
        float winPercent;
};