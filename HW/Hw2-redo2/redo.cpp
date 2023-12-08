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

bool closer(Team &r1, Team &r2)
{
    return r1.getWinPercentage() > r2.getWinPercentage();
}



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

    std::map<std::string, Team> teamMap;
    std::map<std::string, Player> playerMap;
    vector<Team> vectorTeam;

    int readInput;
    string playerGoal;
    string teamGoal;
    string assist1;
    string assist2;
    string assist3;
    // while(file >> varScanned){}
    while (1)
    {
        if (readInput)
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
        else if (varScanned.compare("FINAL") == 0)
        {

            cout << "Coming here";
            readEventsFlag = 0;
            readInput = 1;
            file >> varScanned;

            file >> awayTeamGoals;
            file >> varScanned;
            file >> homeTeamGoals;

            teamMap[awayTeam].incrementGoals(awayTeamGoals);
            teamMap[homeTeam].incrementGoals(homeTeamGoals);

            if (awayTeamGoals == homeTeamGoals)
            {
                teamMap[awayTeam].incrementTie();
                teamMap[homeTeam].incrementTie();
            }
            else if (awayTeamGoals > homeTeamGoals)
            {
                teamMap[awayTeam].incrementWins();
                teamMap[homeTeam].incrementLosses();
            }
            else
            {
                teamMap[homeTeam].incrementWins();
                teamMap[awayTeam].incrementLosses();
            }
            teamMap[awayTeam].winPercentage();
            teamMap[homeTeam].winPercentage();

            // cout << "Away team wins:" << awayTeamGoals << " home team wins:" << homeTeamGoals << endl;
            cout << "Away team wins:" << teamMap[awayTeam].getWins() << " home team wins:" << teamMap[homeTeam].getWins() << endl;
        }
        else if (varScanned.compare("PERIOD") == 0)
        {
            file >> periodNumber;

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
                    playerMap[playerPenalty].setNameAndTeam(playerPenalty, teamPenalty);
                }
                playerMap[playerPenalty].incrementPenalty();

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

                    teamMap[awayTeam].incrementGoals(awayTeamGoals);
                    teamMap[homeTeam].incrementGoals(homeTeamGoals);

                    if (awayTeamGoals == homeTeamGoals)
                    {
                        teamMap[awayTeam].incrementTie();
                        teamMap[homeTeam].incrementTie();
                    }
                    else if (awayTeamGoals > homeTeamGoals)
                    {
                        teamMap[awayTeam].incrementWins();
                        teamMap[homeTeam].incrementLosses();
                    }
                    else
                    {
                        teamMap[homeTeam].incrementWins();
                        teamMap[awayTeam].incrementLosses();
                    }

                    teamMap[awayTeam].winPercentage();
                    teamMap[homeTeam].winPercentage();

                    cout << "Away team wins:" << awayTeamGoals << " home team wins:" << homeTeamGoals << endl;
                }
                else
                {
                    readInput = 0;
                }
            }
            else if (event.compare("goal") == 0)
            {
                readInput = 1;
                teamGoal = teamOfEvent;
                file >> playerGoal;
                file >> varScanned;
                file >> varScanned;
                if (playerMap.count(playerGoal) < 1)
                {
                    playerMap[playerGoal] = Player();
                    playerMap[playerGoal].setNameAndTeam(playerGoal, teamGoal);
                }
                playerMap[playerGoal].incrementGoals();
                cout << "var scane" << varScanned;
                assist1 = "";
                assist2 = "";
                assist3 = "";
                if (varScanned.compare(")") != 0)
                {
                    assist1 = varScanned;

                    if (playerMap.count(assist1) < 1)
                    {
                        playerMap[assist1] = Player();
                        playerMap[assist1].setNameAndTeam(assist1, teamGoal);
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

                        if (varScanned.compare(")") != 0)
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
                cout << teamOfEvent << " player goal " << playerGoal << " assist1 " << assist1 << " assist2 " << assist2 << " assist3 " << assist3 << endl;
            }
        }
    }
    cout << endl
         << endl
         << endl;

    if (formatting == "--team_stats")
    {
        // ofstream outFile(outPutFile);
        // outFile << left << setw(15) << "Team Name" << setw(3) << "W" << setw(3) << "L" << setw(3) << "T" << setw(6) << "Win%" << setw(6) << "Goals" << right << setw(10) << "Penalties" << endl;
        // for (auto element : teamMap)
        // {
        //     cout << element.first << " and ";
        //     Team obj = element.second;
        //     cout << "Name:" << obj.getName() << "  goals:" << obj.getGoals() << "    penalties:" << obj.getPenalties() << "  wins" << obj.getWins() << "     ties:" << obj.getTies() << "     lossses:" << obj.getLosses() << endl;
        //     // THIS TOO
        //     outFile << left << setw(15) << obj.getName() << setw(3) << obj.getWins() << setw(3) << obj.getLosses() << setw(3) << obj.getTies() << setw(6) << obj.getWinPercentage() << setw(6) << obj.getGoals() << right << setw(10) << obj.getPenalties() << endl;
        //     vectorTeam.push_back(obj);
        // }
        // outFile.close();
    }
    else if (formatting == "--player_stats")
    {
        ofstream outFile(outPutFile);
        outFile << left << setw(25) << "\nPlayer Name" << setw(15) << "Team" << setw(6) << "Goals" << setw(9) << "Assists" << right << setw(10) << "Penalties" << endl;
        for (auto element : playerMap)
        {
            Player obj = element.second;
            cout << "Name:" << obj.getName() << "  goals:" << obj.getGoals() << "    penalties:" << obj.getPenalties() << "  Assists" << obj.getAssists() << "     Team:" << obj.getTeam() << endl;
            outFile << left << setw(25) << obj.getName() << setw(15) << obj.getTeam() << setw(6) << obj.getGoals() << setw(9) << obj.getAssists() << right << setw(10) << obj.getPenalties() << endl;
        }
        outFile.close();
    }else if(formatting == "custom_stats"){

    }

    ofstream outFile3("outputSorted.txt");
    outFile3 << left << setw(15) << "Team Name" << setw(3) << "W" << setw(3) << "L" << setw(3) << "T" << setw(6) << "Win%" << setw(6) << "Goals" << right << setw(10) << "Penalties" << endl;
    std::sort(vectorTeam.begin(), vectorTeam.end(), closer);

    for(Team obj:vectorTeam){

        outFile3 << left << setw(15) << obj.getName() << setw(3) << obj.getWins() << setw(3) << obj.getLosses() << setw(3) << obj.getTies() << setw(6) << obj.getWinPercentage() << setw(6) << obj.getGoals() << right << setw(10) << obj.getPenalties() << endl;

    }

    outFile3.close();

    // ofstream outFile2("output2.txt");
    // outFile2 << left << setw(25) << "Player Name" << setw(15) << "Team" << setw(6) << "Goals" << setw(9) << "Assists" << right << setw(10) << "Penalties" << endl;
    // for (auto element : playerMap)
    // {
    //     // element.first represents the key in the map

    //     // element.second represents the value in the map
    //     Player obj = element.second;
    //     cout << "Name:" << obj.getName() << "  goals:" << obj.getGoals() << "    penalties:" << obj.getPenalties() << "  Assists" << obj.getAssists() << "     Team:" << obj.getTeam() << endl;

    //     outFile2 << left << setw(25) << obj.getName() << setw(15) << obj.getTeam() << setw(6) << obj.getGoals() << setw(9) << obj.getAssists() << right << setw(10) << obj.getPenalties() << endl;

    // }
}
