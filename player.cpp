#include "player.h"

int player::getLocation(int i){
    return location[i];
}
void player::setLocation(int i, int coord){
    location[i] = coord;
}
int player::getInventory(){
    return inventory;
}
void player::setInventory(int i){
    inventory = i; 
}