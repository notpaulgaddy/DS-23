#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
// #include "team.h"
#include <string.h>
#include <map>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include "player.h"
#include "team.h"

using namespace std;

bool closer(Team& r1, Team& r2){//function to rank the win percentages
    return r1.getWinPercentage() > r2.getWinPercentage();
}
bool stats(Player& p1, Player& p2){
    if(p1.getGoals()+p1.getAssists() == p2.getGoals()+p2.getAssists()){//check if the amt of assists and goals equal
        return p1.getName().compare(p2.getName()) == -1;//then rank by names
    }
    return p1.getGoals()+p1.getAssists() > p2.getGoals()+p2.getAssists();//function to rank the goals and assists
}
vector<Player> sortPlayers(std::map<std::string, Player> &players ){
    vector<Player> A;
    for(auto& item : players){
        A.push_back(item.second);
    }
    sort(A.begin(),A.end(), stats);//sort using stats function
    return A;
}
//1st num goals+assists
//2nd num num of penalties

int main(int argc, char *argv[])
{
    std::ifstream file(argv[1]);
    string outPutFile = argv[2];
    string formatting = argv[3];
    string varScanned;
    string homeTeam;
    string awayTeam;
    string timeOfEvent;
    int awayTeamGoals;
    int homeTeamGoals;
    int periodNumber;
    string teamOfEvent;
    string event;
    string playerEvent;
    string typePenalty;
    string playerPenalty;
    string teamPenalty;

    // int timePenalty;
    // int f = 0;

    int readTeamsFlag = 0;
    int readEventsFlag = 1;

    std::map<std::string, Team> teamMap;//map for the teams
    std::map<std::string, Player> playerMap;//map for the players
    vector<Team> vectorTeam;//vector for the team

    int readInput;
    string playerGoal;
    string teamGoal;
    string assist1;
    string assist2;
    string assist3;
   //while(file >> varScanned){}
    while (1)
    {
        if (readInput)//read the input lines
        {
            if (!(file >> varScanned))
            {
                break;
            }
        }
        if (varScanned.compare("Sunday,") == 0 || varScanned.compare("Monday,") == 0 || varScanned.compare("Tuesday,") == 0 || varScanned.compare("Wednesday,") == 0 || varScanned.compare("Thursday,") == 0 || varScanned.compare("Friday,") == 0 || varScanned.compare("Saturday,") == 0)
        {

            readTeamsFlag = 1;
            file >> varScanned >> varScanned >> varScanned;
            file >> awayTeam;
            file >> varScanned;
            file >> homeTeam;
            cout << "away Team" << awayTeam << " "
                 << "home team" << homeTeam << endl;
            readInput = 1;

            if (teamMap.count(awayTeam) < 1)
            {
                teamMap[awayTeam] = Team();
                teamMap[awayTeam].setName(awayTeam);
            }
            if (teamMap.count(homeTeam) < 1)
            {
                teamMap[homeTeam] = Team();
                teamMap[homeTeam].setName(homeTeam);
            }
        }
        else if (varScanned.compare("FINAL") == 0)//check to see if the game is done
        {

            cout << "Coming here";
            readEventsFlag = 0;
            readInput = 1;
            file >> varScanned;

            file >> awayTeamGoals;
            file >> varScanned;
            file >> homeTeamGoals;

            teamMap[awayTeam].incrementGoals(awayTeamGoals);//add the amt of goals to away team
            teamMap[homeTeam].incrementGoals(homeTeamGoals);//add the amt of goals to home team

            if (awayTeamGoals == homeTeamGoals)
            {
                teamMap[awayTeam].incrementTie();//if equal, make it a tie
                teamMap[homeTeam].incrementTie();
            }
            else if (awayTeamGoals > homeTeamGoals)//set winner
            {
                teamMap[awayTeam].incrementWins();
                teamMap[homeTeam].incrementLosses();
            }
            else
            {
                teamMap[homeTeam].incrementWins();//set winner
                teamMap[awayTeam].incrementLosses();
            }
            teamMap[awayTeam].winPercentage();
            teamMap[homeTeam].winPercentage();

            cout << "Away team wins:" << awayTeamGoals << " home team wins:" << homeTeamGoals << endl;//output for debugging
        }
        else if (varScanned.compare("PERIOD") == 0)
        {
            file >> periodNumber;//see the amount of periods

            readEventsFlag = 1;
            file >> varScanned;
            if (varScanned.compare("PERIOD") == 0)
                file >> periodNumber;
            if (varScanned.compare("PERIOD") == 0)
                file >> periodNumber;
            readInput = 1;
        }
        if (readEventsFlag)
        {

            file >> teamOfEvent;
            file >> event;
            if (event.compare("penalty") == 0)
            {
                teamPenalty = teamOfEvent;
                file >> playerPenalty;
                file >> varScanned;
                file >> typePenalty;
                file >> varScanned;

                teamMap[teamPenalty].incrementPenalty();
                if (playerMap.count(playerPenalty) < 1)
                {
                    playerMap[playerPenalty] = Player();
                    playerMap[playerPenalty].setNameAndTeam(playerPenalty, teamPenalty);//set the amount of penalties for the player and team
                }
                playerMap[playerPenalty].incrementPenalty();//add 1 to the amt of penalties

                cout << "team of event " << teamOfEvent << " event " << event << " player penalty " << playerPenalty << " type Penalty " << typePenalty << endl;
                if (varScanned.compare("PERIOD") == 0)
                {
                    file >> periodNumber;
                    readEventsFlag = 1;
                    readInput = 1;
                }
                else if (varScanned.compare("FINAL") == 0)
                {
                    cout << "Coming here";
                    readEventsFlag = 0;
                    readInput = 1;
                    file >> varScanned;

                    file >> awayTeamGoals;
                    file >> varScanned;
                    file >> homeTeamGoals;

                    teamMap[awayTeam].incrementGoals(awayTeamGoals);//increment away team goals
                    teamMap[homeTeam].incrementGoals(homeTeamGoals);//increment home team goals

                    if (awayTeamGoals == homeTeamGoals)
                    {
                        teamMap[awayTeam].incrementTie();//tie
                        teamMap[homeTeam].incrementTie();//tie
                    }
                    else if (awayTeamGoals > homeTeamGoals)
                    {
                        teamMap[awayTeam].incrementWins();//win
                        teamMap[homeTeam].incrementLosses();//loss function
                    }
                    else
                    {
                        teamMap[homeTeam].incrementWins();//win fucntion
                        teamMap[awayTeam].incrementLosses();//loss function
                    }

                    teamMap[awayTeam].winPercentage();//get the win percentage for away team
                    teamMap[homeTeam].winPercentage();//get the win percentage for home team

                    cout << "Away team wins:" << awayTeamGoals << " home team wins:" << homeTeamGoals << endl;
                }
                else
                {
                    readInput = 0;
                }
            }
            else if (event.compare("goal") == 0)//compare the goal
            {
                readInput = 1;
                teamGoal = teamOfEvent;
                file >> playerGoal;
                file >> varScanned;
                file >> varScanned;
                if (playerMap.count(playerGoal) < 1)
                {
                    playerMap[playerGoal] = Player();//set the goals to that player
                    playerMap[playerGoal].setNameAndTeam(playerGoal, teamGoal);//set it to the name and team
                }
                playerMap[playerGoal].incrementGoals();//increment the players goals
                cout << "var scan" << varScanned;//debugging
                assist1 = "";
                assist2 = "";
                assist3 = "";//data for assists
                if (varScanned.compare(")") != 0)
                {
                    assist1 = varScanned;

                    if (playerMap.count(assist1) < 1)
                    {
                        playerMap[assist1] = Player();//set assists to the player
                        playerMap[assist1].setNameAndTeam(assist1, teamGoal);//set the assist to the team and player
                    }
                    playerMap[assist1].incrementAssists();

                    file >> varScanned;
                    if (varScanned.compare(")") != 0)
                    {
                        assist2 = varScanned;
                        file >> varScanned;

                        if (playerMap.count(assist2) < 1)
                        {
                            playerMap[assist2] = Player();
                            playerMap[assist2].setNameAndTeam(assist2, teamGoal);
                        }
                        playerMap[assist2].incrementAssists();

                        if (varScanned.compare(")") != 0)//check to see if the (fn_ln) is done 
                        {

                            assist3 = varScanned;
                            file >> varScanned;
                            if (playerMap.count(assist3) < 1)
                            {
                                playerMap[assist3] = Player();
                                playerMap[assist3].setNameAndTeam(assist3, teamGoal);
                            }
                            playerMap[assist3].incrementAssists();
                        }
                    }
                }
                cout << teamOfEvent << " player goal " << playerGoal << " assist1 " << assist1 << " assist2 " << assist2 << " assist3 " << assist3 << endl;//debugging
            }
        }
    }

    // ofstream outFile("output.txt");
    // outFile << left << setw(15) << "Team Name" << setw(3) << "W" << setw(3) << "L" << setw(3) << "T" << setw(6) << "Win%" << setw(6) << "Goals" << right << setw(10) << "Penalties" << endl;
    if(formatting == "--team_stats"){
        for (auto element : teamMap){//go through each item in the team map
            cout << element.first << " and ";//use and as the seperator
            Team obj = element.second;
            cout << "Name:" << obj.getName() << "  goals:" << obj.getGoals() << "    penalties:" << obj.getPenalties() << "  wins" << obj.getWins() << "     ties:" << obj.getTies() << "     lossses:" << obj.getLosses() << endl;
            vectorTeam.push_back(obj);
        }
        ofstream outFile(outPutFile);
        outFile << left << setw(15) << "Team Name" << setw(3) << "W" << setw(3) << "L" << setw(3) << "T" << setw(6) << "Win%" << setw(6) << "Goals" << right << setw(10) << "Penalties" << endl;
        std::sort(vectorTeam.begin(), vectorTeam.end(), closer);

        for(Team obj:vectorTeam){//iterate thru each item in the team vector
            outFile << left << setw(15) << obj.getName() << setw(3) << obj.getWins() << setw(3) << obj.getLosses() << setw(3) << obj.getTies() << setw(6) << obj.getWinPercentage() << setw(6) << obj.getGoals() << right << setw(10) << obj.getPenalties() << endl;

        }
        outFile.close();
    } else if(formatting == "--player_stats"){
        ofstream outFile(outPutFile);
        outFile << left << setw(25) << "\nPlayer Name" << setw(15) << "Team" << setw(6) << "Goals" << setw(9) << "Assists" << right << setw(10) << "Penalties" << endl;
        auto sortedPlayers = sortPlayers(playerMap);
        // for (auto element : playerMap)
        for (auto obj : sortedPlayers)
        {
            // Player obj = element.second;
            cout << "Name:" << obj.getName() << "  goals:" << obj.getGoals() << "    penalties:" << obj.getPenalties() << "  Assists" << obj.getAssists() << "     Team:" << obj.getTeam() << endl;
            outFile << left << setw(25) << obj.getName() << setw(15) << obj.getTeam() << setw(6) << obj.getGoals() << setw(9) << obj.getAssists() << right << setw(10) << obj.getPenalties() << endl;
        }
        outFile.close();
    } else if(formatting == "--custom_stats"){
        ofstream outFile(outPutFile);
        float benchThem = 0;
        vector<string> theNames;
        for (auto element : playerMap)
        {
            Player obj = element.second;
            theNames.push_back(obj.getName());
            if(obj.getGoals() < 1 && obj.getAssists()<1){
                benchThem++;
            }
            // cout << "Name:" << obj.getName() << "  goals:" << obj.getGoals() << "    penalties:" << obj.getPenalties() << "  Assists" << obj.getAssists() << "     Team:" << obj.getTeam() << endl;
            // outFile << left << setw(25) << obj.getName() << setw(15) << obj.getTeam() << setw(6) << obj.getGoals() << setw(9) << obj.getAssists() << right << setw(8) << obj.getPenalties() << endl;
        }
        float benchPerc = benchThem/ (float)theNames.size();
        outFile << "This percentage of players should be benched and have someone else subbed in for them " << benchPerc << "% because they haven't scored a goal" << endl;
        outFile.close();
    }
    

    // ofstream outFile2("output2.txt");

    // outFile2 << left << setw(25) << "Player Name" << setw(15) << "Team" << setw(6) << "Goals" << setw(9) << "Assists" << right << setw(10) << "Penalties" << endl;

}