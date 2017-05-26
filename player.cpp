#include "map.h"
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
void player::moveForward(map &map){
    if(!getInvertControls()){
        if (map.isPermeable(getLocation(0) - 1, getLocation(1))){
            setLocation(0, getLocation(0) - 1); // Move Forward
        }
    }else{
        if (map.isPermeable(getLocation(0) + 1, getLocation(1))){
            setLocation(0, getLocation(0) + 1); // Move Backward
        }
    }
}
void player::moveBackward(map &map){
    if(!getInvertControls()){
        if (map.isPermeable(getLocation(0) + 1, getLocation(1))){
            setLocation(0, getLocation(0) + 1); // Move Backward
        }
    }else{
        if (map.isPermeable(getLocation(0) - 1, getLocation(1))){
            setLocation(0, getLocation(0) - 1); // Move Forward
        }
    }
}
void player::moveLeft(map &map){
    if(!getInvertControls()){
        if (map.isPermeable(getLocation(0), getLocation(1) - 1)){
            setLocation(1, getLocation(1) - 1);
        }
    }else{
        if (map.isPermeable(getLocation(0), getLocation(1) + 1)){
            setLocation(1, getLocation(1) + 1);
        }
    }
}
void player::moveRight(map &map){
    if(!getInvertControls()){
        if (map.isPermeable(getLocation(0), getLocation(1) + 1)){
            setLocation(1, getLocation(1) + 1);
        }
    }else{
        if (map.isPermeable(getLocation(0), getLocation(1) - 1)){
            setLocation(1, getLocation(1) - 1);
        }
    }
}