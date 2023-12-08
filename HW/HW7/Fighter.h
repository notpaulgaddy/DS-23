#ifndef FIGHTER
#define FIGHTER
#include <iostream>
using namespace std;
class Fighter{
    public:
        // Fighter(string characterName, int jabs, int forwardTilt,int upTilt,int downTilt, int forwardSmash,int upSmash,int downSmash);
        Fighter(int jabs, int forwardTilt,int upTilt,int downTilt, int forwardSmash,int upSmash,int downSmash);
        Fighter();
        //string getFighterName() {return nameOfFighter;};
        int getJabs() {return numJabs;};
        int getforwardTilts() {return numFtilts;};
        int getupTilts() {return numUtilts;};
        int getdownTilts() {return numDtilts;};
        int getforwardSmashes() {return numFsmashes;};
        int getupSmashes() {return numUsmashes;};
        int getdownSmashes() {return numDsmashes;};
    private:
        string nameOfFighter;
        int numJabs, numFtilts,numUtilts,numDtilts,numFsmashes,numUsmashes,numDsmashes;
};  
#endif