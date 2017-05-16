#include "player.h"

void player::setLocation(int i, int coord){
    location[i] = coord;
}
int player::getLocation(int i){
    return location[i];
}
void player::setInventory(int i, int j){
    inventory[i] = j; 
}
int player::getInventory(int i){
    return inventory[i];
}
void player::setInventorySize(int i){
    inventorySize = i;
}
int player::getInventorySize(){
    return inventorySize;
}
void player::setInvertControls(int i){
    invertControls = i;
}
int player::getInvertControls(){
    return invertControls;
}
void player::moveForward(){
    if(getInvertControls() == 0){
        setLocation(0, getLocation(0) - 1);
    }else{
        setLocation(0, getLocation(0) + 1);
    }
}
void player::moveBackward(){
        if(getInvertControls() == 0){
        setLocation(0, getLocation(0) + 1);
    }else{
        setLocation(0, getLocation(0) - 1);
    }
}
void player::moveLeft(){
    if(getInvertControls() == 0){
        setLocation(1, getLocation(1) - 1);
    }else{
        setLocation(1, getLocation(1) + 1);
    }
}
void player::moveRight(){
    if(getInvertControls() == 0){
        setLocation(1, getLocation(1) + 1);
    }else{
        setLocation(1, getLocation(1) - 1);
    }
}