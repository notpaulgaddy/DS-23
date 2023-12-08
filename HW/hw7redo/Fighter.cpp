#include "Fighter.h"

Fighter::Fighter() {
  jab = 0;
  forwardTilt = 0;
  upTilt = 0;
  downTilt = 0;
  forwardSmash = 0;
  upSmash = 0;
  downSmash = 0;
}
//init all the data to 0
void Fighter::setJab(int  frame) {
  jab =  frame;
}
int Fighter::getJab() {
  return jab;
}

void Fighter::setForwardTilt(int  frame) {
  forwardTilt =  frame;
}

int Fighter::getForwardTilt() {
  return forwardTilt;
}

void Fighter::setUpTilt(int  frame) {
  upTilt =  frame;
}

int Fighter::getUpTilt() {
  return upTilt;
}

void Fighter::setDownTilt(int  frame) {
  downTilt =  frame;
}

int Fighter::getDownTilt() {
  return downTilt;
}

void Fighter::setForwardSmash(int  frame) {
  forwardSmash =  frame;
}

int Fighter::getForwardSmash() {
  return forwardSmash;
}

void Fighter::setUpSmash(int  frame) {
  upSmash =  frame;
}

int Fighter::getUpSmash() {
  return upSmash;
}

void Fighter::setDownSmash(int  frame) {
  downSmash =  frame;
}

int Fighter::getDownSmash() {
  return downSmash;
}
//all getter and setter functions