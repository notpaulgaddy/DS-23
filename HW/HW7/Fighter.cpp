#include "Fighter.h"
#include <iostream>
using namespace std;

// Fighter::Fighter(string characterName, int jabs, int forwardTilt,int upTilt,int downTilt, int forwardSmash,int upSmash,int downSmash){
Fighter::Fighter(int jabs, int forwardTilt,int upTilt,int downTilt, int forwardSmash,int upSmash,int downSmash){
    //nameOfFighter = characterName;
    numJabs = jabs;
    numFtilts = forwardTilt;
    numDtilts = downTilt;
    numFsmashes = forwardSmash;
    numUsmashes = upSmash;
    numDsmashes = downSmash;
}

Fighter::Fighter() {}