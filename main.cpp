#include <iostream>
#include <GL/glew.h>
#include "colors.cpp"
#include "player.h"
#include "map.h"

using namespace std;

char command;
int entryPoint[2] = {9, 2};
int grid[10][10] = {
    {0, 0, 1, 1, 1, 1, 3, 1, 1, 1},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 1, 1, 1, 1, 2, 0, 1},
    {5, 3, 1, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {2, 1, 1, 1, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 3, 1, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
    {2, 0, 1, 0, 0, 0, 1, 1, 1, 0}
};
void askCommand(player player, map map);
void printGrid(player player, map map);
int isPermeable(int i, int j, map map);
int checkAroundFor(player player, map map, int i);

int main(){
    system("clear");
    map map1;
    player player1;
    for (int a = 0; a<10; a++){
        for (int b = 0; b < 10; b++){
            map1.setGridValue(a, b, grid[a][b]);
        }
    }
    player1.setLocation(0, entryPoint[0]);
    player1.setLocation(1, entryPoint[1]);

    while (command != 'Q'){
        cout << BLUE << "Moosh" << GREEN << "Vr.1" << RESET << endl;
        if (player1.getInventory() == 1)
        {
            cout << YELLOW << "ß " << RESET;
        }
        askCommand(player1, map1);
        printGrid(player1, map1);
        system ("/bin/stty raw");
        cin >> command;
        system ("/bin/stty cooked");
        if(map1.gridValue(player1.getLocation(0), player1.getLocation(1))==6){
            
        }
        if (command == 'w')
        {
            if (isPermeable(player1.getLocation(0) - 1, player1.getLocation(1), map1))
            {
                player1.setLocation(0, player1.getLocation(0) - 1);
            }
        }
        if (command == 's')
        {
            if (isPermeable(player1.getLocation(0) + 1, player1.getLocation(1), map1))
            {
                player1.setLocation(0, player1.getLocation(0) + 1);
            }
        }
        if (command == 'a')
        {
            if (isPermeable(player1.getLocation(0), player1.getLocation(1) - 1, map1))
            {
                player1.setLocation(1, player1.getLocation(1) - 1);
            }
        }
        if (command == 'd')
        {
            if (isPermeable(player1.getLocation(0), player1.getLocation(1) + 1, map1))
            {
                player1.setLocation(1, player1.getLocation(1) + 1);
            }
        }
        if (command == 'e')
        {
            if (map1.gridValue(player1.getLocation(0), player1.getLocation(1)) == 2)
            {
                map1.setGridValue(player1.getLocation(0), player1.getLocation(1), 1);
                player1.setInventory(1);
            }
            if(player1.getInventory()==1){
                if(checkAroundFor(player1, map1, 3)){
                    if (checkAroundFor(player1, map1, 3) == 2)
                    {
                        map1.setGridValue(player1.getLocation(0) + 1, player1.getLocation(1), 4);
                    }
                    if (checkAroundFor(player1, map1, 3) == 3)
                    {
                        map1.setGridValue(player1.getLocation(0) - 1, player1.getLocation(1), 4);
                    }
                    if (checkAroundFor(player1, map1, 3) == 4)
                    {
                        map1.setGridValue(player1.getLocation(0), player1.getLocation(1) + 1, 4);
                    }
                    if (checkAroundFor(player1, map1, 3) == 5)
                    {
                        map1.setGridValue(player1.getLocation(0), player1.getLocation(1) - 1, 4);
                    }
                    player1.setInventory(0);
                }
            }
        }
        system("clear");
        if(map1.gridValue(player1.getLocation(0), player1.getLocation(1))==5){
           cout << "You beat Moosh!" << endl;
           cin >> command;
           return 0;
        }
    }
}
void printGrid(player player, map map)
{
    for (int a = 0; a < 10; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            if (a == player.getLocation(0) && b == player.getLocation(1))
            {
                cout << MAGENTA << "X" << RESET;
            }
            else
            {
                if (map.gridValue(a, b) == 0)
                {
                    cout << RED << "#" << RESET;
                }
                if (map.gridValue(a, b) == 1)
                {
                    cout << GREEN << "0" << RESET;
                }
                if (map.gridValue(a, b) == 2)
                {
                    cout << YELLOW << "ß" << RESET;
                }
                if (map.gridValue(a, b) == 3)
                {
                    cout << RED << "∆" << RESET;
                }
                if (map.gridValue(a, b) == 4)
                {
                    cout << GREEN << "∆" << RESET;
                }
                if (map.gridValue(a, b) == 5)
                {
                    cout << CYAN << "◊" << RESET;
                }
                if (map.gridValue(a, b) == 6 )
                {
                    cout << GREEN << "8" << RESET;
                }
            }
            cout << " ";
        }
        cout << endl;
    }
}

void askCommand(player player, map map)
{
    if(0){
        if(map.gridValue(player.getLocation(0) - 1, player.getLocation(1))==1)
        {
            cout << "Forward, ";
        }
        if(map.gridValue(player.getLocation(0), player.getLocation(1) - 1)==1)
        {
            cout << "Left, ";
        }
        if(map.gridValue(player.getLocation(0), player.getLocation(1) + 1)==1)
        {
            cout << "Right, ";
        }
        if(map.gridValue(player.getLocation(0) + 1, player.getLocation(1))==1)
        {
            cout << "Backward, ";
        }
    }
    if(map.gridValue(player.getLocation(0), player.getLocation(1)) == 2){
        cout << YELLOW <<"Pick up Key with e" << RESET;
    }
    if(checkAroundFor(player, map, 3)){
        if(player.getInventory()==1){
            cout << YELLOW << "Open door with with e" << RESET;
        }else{
            cout << YELLOW << "Door needs Key" << RESET;
        }
    }
    cout << endl;
}
int isPermeable(int i, int j, map map)
{
    if (map.gridValue(i, j) == 0)
    {
        return 0;
    }
    else if (map.gridValue(i, j) == 1)
    {
        return 1;
    }
    else if (map.gridValue(i, j) == 2)
    {
        return 1;
    }
    else if (map.gridValue(i, j) == 3)
    {
        return 0;
    }
    else if (map.gridValue(i, j) == 4)
    {
        return 1;
    }
    else if (map.gridValue(i, j) == 5)
    {
        return 1;
    }
    else if (map.gridValue(i, j) == 6)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkAroundFor(player player, map map, int i)
{
    if (map.gridValue(player.getLocation(0), player.getLocation(1)) == i)
    {
        return 1;
    }
    else if (map.gridValue(player.getLocation(0) + 1, player.getLocation(1)) == i)
    {
        return 2;
    }
    else if (map.gridValue(player.getLocation(0) - 1, player.getLocation(1)) == i)
    {
        return 3;
    }
    else if (map.gridValue(player.getLocation(0), player.getLocation(1) + 1) == i)
    {
        return 4;
    }
    else if (map.gridValue(player.getLocation(0), player.getLocation(1) - 1) == i)
    {
        return 5;
    }
    else
    {
        return 0;
    }
}