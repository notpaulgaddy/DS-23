#ifndef FIGHTER_H
#define FIGHTER_H

class Fighter {
  public:
    Fighter();//fighter class init
    void setJab(int  frame);
    int getJab();
    void setForwardTilt(int  frame);
    int getForwardTilt();
    void setUpTilt(int  frame);
    int getUpTilt();
    void setDownTilt(int  frame);
    int getDownTilt();
    void setForwardSmash(int  frame);
    int getForwardSmash();
    void setUpSmash(int  frame);
    int getUpSmash();
    void setDownSmash(int  frame);
    int getDownSmash();
    //all the getters and setters
  private:
    int jab;
    int forwardTilt;
    int upTilt;
    int downTilt;
    int forwardSmash;
    int upSmash;
    int downSmash;
    //all the integer values
};

#endif
