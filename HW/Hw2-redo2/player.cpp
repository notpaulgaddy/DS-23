#include "player.h"

Player::Player()
    {//initialize them all to 0
        this->goals = 0;
        this->penalties = 0;
        this->assists = 0;
    }
    string Player::getName()
    {//function to get the name
        return this->name;
    }
    void Player::setNameAndTeam(string name, string team)
    {//function to set the name and team together
        this->name = name;
        this->team = team;
    }
    void Player::incrementGoals()
    {//function to set the goal increment
        this->goals += 1;
    }
    void Player::incrementPenalty()
    {//function to set the penalty increment
        this->penalties += 1;
    }
    void Player::incrementAssists()
    {//function to set the assist increment
        this->assists += 1;
    }
    string Player::getTeam()
    {//get the team info
        return this->team;
    }
    int Player::getGoals()
    {//get the team goals
        return this->goals;
    }
    int Player::getPenalties()
    {//get the team penalties
        return this->penalties;
    }
    int Player::getAssists()
    {//get the team assists
        return this->assists;
    }