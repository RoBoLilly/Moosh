#include <iostream>
#include "colors.h" // has color IDs
#include "map.h"
#include "map.cpp"
#include "player.h"
#include "player.cpp"
#include "enemy.h"
#include "enemy.cpp"
using namespace std;

int printDirections = false; // tells askCommand to list possible actions 

char command;
int meta;

void askCommand(player player, map map);
void printGrid(player player, map map);
int checkAroundFor(player player, map map, int i);

int main(){
    system("clear");
    map map1;
    player player1;
    enemy boss1;

    map1.setLoadedGrid(0, 0); // Loads first grid
    player1.setLocation(0, 7); //Y Places player1 on grid
    player1.setLocation(1, 4); //X 
    boss1.setMapLocation(0, 1);
    boss1.setMapLocation(1, 3);
    boss1.setLocation(0, 4);
    boss1.setLocation(1, 4);
    while (command != 'Q'){
        cout << BLUE << "Moosh" << GREEN << "Vr.2" << RESET << endl;
        //cout << "[" << map1.getLoadedGrid(0) << ", " << map1.getLoadedGrid(1) << "]" <<endl; // Prints current loaded grid
        //cout << "[" << boss1.getLocation(0) << ", " << boss1.getLocation(1) << "]" <<endl;
        //cout << "[" << player1.getLocation(0) << ", " << player1.getLocation(1) << "]" <<endl;
        cout << YELLOW << "["; // Prints Inventory
        for(int inv=0;inv<10;inv++){
            if (player1.getInventory(inv) == 1){cout << "ß ";}
        }
        cout << "]" << RESET;
        if(map1.gridValue(player1.getLocation(0), player1.getLocation(1))==6){ // checks if controls should be inverted
            player1.setInvertControls(1);
        }else{player1.setInvertControls(0);}

        if(boss1.getMapLocation(0) == map1.getLoadedGrid(0)
        && boss1.getMapLocation(1) == map1.getLoadedGrid(1)){
            for(int a=1;a<11;a++){
                for(int b=1;b<11;b++){
                    if(map1.gridValue(a, b) == 8){
                        map1.setGridValueNoSave(a, b, 1);
                    }
                    if(boss1.getLocation(0) == a && boss1.getLocation(1) == b){
                        map1.setGridValueNoSave(a, b, 8);
                    }
                }
            }
        }
        askCommand(player1, map1); // This is what prints the little hints 
        printGrid(player1, map1); // This is what prints the Grid. Duh...
        // if(boss1.getLocation(0) == player1.getLocation(0)
        // && boss1.getLocation(1) == player1.getLocation(1)){
        //     cout << endl << "The Boss Got You" << endl << "You Lose!" << endl;
        //     cin >> command;
        //     return 0; 
        // }
        system ("/bin/stty raw"); // allows for single key press
        cin >> command;
        system ("/bin/stty cooked");
        
        if(boss1.getAIstate() == 0){
            if (map1.isPermeable(boss1.getLocation(0), boss1.getLocation(1) + 1)){
                boss1.moveRight();
            }
            if(boss1.getLocation(1) > 6){
                boss1.setAIstate(1);
            }
        }else if(boss1.getAIstate() == 1){
            if (map1.isPermeable(boss1.getLocation(0) + 1, boss1.getLocation(1))){
                boss1.moveBackward();
            }
            if(boss1.getLocation(0) > 6){
                boss1.setAIstate(2);
            }
        }else if(boss1.getAIstate() == 2){
            if (map1.isPermeable(boss1.getLocation(0), boss1.getLocation(1) - 1)){
                boss1.moveLeft();
            }
            if(boss1.getLocation(1) < 5){
                boss1.setAIstate(3);
            }
        }else if(boss1.getAIstate() == 3){
            if (map1.isPermeable(boss1.getLocation(0) - 1, boss1.getLocation(1))){
                boss1.moveForward();
            }
            if(boss1.getLocation(0) < 5){
                boss1.setAIstate(0);
            }
        }

        if (command == 1 || command == 'i'){
            if (map1.isPermeable(boss1.getLocation(0) - 1, boss1.getLocation(1))){
                boss1.moveForward();
            }
        }
        if (command == 2 || command == 'k'){
            if (map1.isPermeable(boss1.getLocation(0) + 1, boss1.getLocation(1))){
                boss1.moveBackward();
            }
        }
        if (command == 3 || command == 'j'){
            if (map1.isPermeable(boss1.getLocation(0), boss1.getLocation(1) - 1)){
                boss1.moveLeft();
            }
        }
        if (command == 4 || command == 'l'){
            if (map1.isPermeable(boss1.getLocation(0), boss1.getLocation(1) + 1)){
                boss1.moveRight();
            }
        }
        if (command == 'w')
        {   
            player1.moveForward(map1);
        }
        if (command == 's')
        {
            player1.moveBackward(map1);
        }
        if (command == 'a')
        {
            player1.moveLeft(map1);
        }
        if (command == 'd')
        {
            player1.moveRight(map1);
        }
        if (command == 'e')
        {
            if (map1.gridValue(player1.getLocation(0), player1.getLocation(1)) == 2) // Pickup Key and add to inventory
            { 
                map1.setGridValue(player1.getLocation(0), player1.getLocation(1), 1);
                player1.setInventory(player1.getInventorySize(), 1);
                player1.setInventorySize(player1.getInventorySize()+1);
            }
            if(player1.getInventory(0)==1){ // Unlock door and remove key from inventory
                meta = checkAroundFor(player1, map1, 3);
                if(meta){
                    if (meta == 2){
                        map1.setGridValue(player1.getLocation(0) + 1, player1.getLocation(1), 4);
                    }
                    if (meta == 3){
                        map1.setGridValue(player1.getLocation(0) - 1, player1.getLocation(1), 4);
                    }
                    if (meta == 4){
                        map1.setGridValue(player1.getLocation(0), player1.getLocation(1) + 1, 4);
                    }
                    if (meta == 5){
                        map1.setGridValue(player1.getLocation(0), player1.getLocation(1) - 1, 4);
                    }
                    player1.setInventory(player1.getInventorySize()-1, 0);
                    player1.setInventorySize(player1.getInventorySize()-1);
                }
            }
            if(player1.getInventory(0)==1 && // Unlock Big Door and remove 3 keys from inventory
                player1.getInventory(1)==1 &&
                player1.getInventory(2)==1){
                meta = checkAroundFor(player1, map1, 7);
                if(meta){
                    if (meta == 2){
                        map1.setGridValue(player1.getLocation(0) + 1, player1.getLocation(1), 4);
                    }
                    if (meta == 3){
                        map1.setGridValue(player1.getLocation(0) - 1, player1.getLocation(1), 4);
                    }
                    if (meta == 4){
                        map1.setGridValue(player1.getLocation(0), player1.getLocation(1) + 1, 4);
                    }
                    if (meta == 5){
                        map1.setGridValue(player1.getLocation(0), player1.getLocation(1) - 1, 4);
                    }
                    player1.setInventory(player1.getInventorySize()-1, 0);
                    player1.setInventorySize(player1.getInventorySize()-1);
                    player1.setInventory(player1.getInventorySize()-1, 0);
                    player1.setInventorySize(player1.getInventorySize()-1);
                    player1.setInventory(player1.getInventorySize()-1, 0);
                    player1.setInventorySize(player1.getInventorySize()-1);
                }
            }
        }
        // If player is over the edge of the grid
        if(map1.gridValue(player1.getLocation(0), player1.getLocation(1))== -1){
            // Teleport player to oposing side and load grid from the same side the player telported from
            if(player1.getLocation(0) == 0){
                map1.loadForwardGrid();
                player1.setLocation(0, 10);
            }
            if(player1.getLocation(0) == 11){
                map1.loadBackwardGrid();
                player1.setLocation(0, 1);
            }
            if(player1.getLocation(1) == 0){
                map1.loadLeftGrid();
                player1.setLocation(1, 10);
            }
            if(player1.getLocation(1) == 11){
                map1.loadRightGrid();
                player1.setLocation(1, 1);
            }
        }
        system("clear");
        if(map1.gridValue(player1.getLocation(0), player1.getLocation(1))==5){
           cout << "You beat Moosh!" << endl;
           cout << RED << "Score: " << player1.getInventorySize() << RESET;
           cin >> command;
           return 0;
        }
    }
}
void printGrid(player player, map map){
    for (int a = 1; a < 11; a++){
        for (int b = 1; b < 11; b++){
            if (a == player.getLocation(0) && b == player.getLocation(1)){
                cout << MAGENTA << "X" << RESET;
            }else{
                if (map.gridValue(a, b) ==-1){cout << MAGENTA << "Z" << RESET;}
                if (map.gridValue(a, b) == 0){cout << RED << "#" << RESET;}
                if (map.gridValue(a, b) == 1){cout << GREEN << "0" << RESET;}
                if (map.gridValue(a, b) == 2){cout << YELLOW << "ß" << RESET;}
                if (map.gridValue(a, b) == 3){cout << RED << "∆" << RESET;}
                if (map.gridValue(a, b) == 4){cout << GREEN << "∆" << RESET;}
                if (map.gridValue(a, b) == 5){cout << CYAN << "◊" << RESET;}
                if (map.gridValue(a, b) == 6){cout << GREEN << "8" << RESET;}
                if (map.gridValue(a, b) == 7){cout << CYAN << "∆" << RESET;}
                if (map.gridValue(a, b) == 8){cout << BOLDCYAN << "E" << RESET;}
            }
            cout << " ";
        }
        cout << endl;
    }
}

void askCommand(player player, map map){
    if(printDirections){
        if(map.gridValue(player.getLocation(0) - 1, player.getLocation(1))==1){cout << "Forward, ";}
        if(map.gridValue(player.getLocation(0) + 1, player.getLocation(1))==1){cout << "Backward, ";}
        if(map.gridValue(player.getLocation(0), player.getLocation(1) - 1)==1){cout << "Left, ";}
        if(map.gridValue(player.getLocation(0), player.getLocation(1) + 1)==1){cout << "Right, ";}
    }
    if(map.gridValue(player.getLocation(0), player.getLocation(1)) == 2){
        cout << YELLOW <<"Pick up Key with e" << RESET;
    }
    
    if(player.getInvertControls()){
        cout << MAGENTA <<"Controls Reversed" << RESET;
    }
    if(checkAroundFor(player, map, 3)){
        if(player.getInventory(0)==1){
            cout << YELLOW << "Open door with with e" << RESET;
        }else{
            cout << YELLOW << "Door needs Key" << RESET;
        }
    }
    if(checkAroundFor(player, map, 7)){
        if(player.getInventory(0)==1 &&
            player.getInventory(1)==1 &&
            player.getInventory(2)==1){
            cout << YELLOW << "Open door with with e" << RESET;
        }else{
            cout << YELLOW << "Door needs 3 Keys to Open" << RESET;
        }
    }
    cout << endl;
}
int checkAroundFor(player player, map map, int i){
    if(map.gridValue(player.getLocation(0), player.getLocation(1)) == i){return 1;}
    else if (map.gridValue(player.getLocation(0) + 1, player.getLocation(1)) == i){return 2;}
    else if (map.gridValue(player.getLocation(0) - 1, player.getLocation(1)) == i){return 3;}
    else if (map.gridValue(player.getLocation(0), player.getLocation(1) + 1) == i){return 4;}
    else if (map.gridValue(player.getLocation(0), player.getLocation(1) - 1) == i){return 5;}
    else{
        return 0;
    }
}