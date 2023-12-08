#include "player.h"
#include <string>
using namespace std;
int Player::add_goal(int goal){
        goal+=1;
        return goal;
}
int Player::add_penalty(int penalties){
    penalties+=1;
    return penalties;
}
string Player::get_name(){
    return name;
}
string Player::get_team(){
    return team;
}
//constructor defintion