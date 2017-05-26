#include "enemy.h"

void enemy::setLocation(int i, int j){
    location[i] = j;
}
int enemy::getLocation(int i){
    return location[i];
}
int enemy::getMapLocation(int i){
    return mapLocation[i];
}
void enemy::setMapLocation(int i, int j){
    mapLocation[i] = j;
}
void enemy::moveForward(){
    location[0] = location[0] - 1;
}
void enemy::moveBackward(){
    location[0] = location[0] + 1;
}
void enemy::moveLeft(){
    location[1] = location[1] - 1;
}
void enemy::moveRight(){
    location[1] = location[1] + 1;
}
// AI
int enemy::getAIstate(){
    return AIstate;
}
void enemy::setAIstate(int i){
    AIstate = i;
}
int enemy::attackForward(){
    return 0;
}
int enemy::attackBackward(){
    return 0;
}
int enemy::attackLeft(){
    return 0;
}
int enemy::attackRight(){
    return 0;
}