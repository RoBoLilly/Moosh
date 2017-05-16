#include "grids.h"
#include "map.h"

int map::gridValue(int i, int j){
    return grid[i][j];
}
void map::setGridValueNoSave(int i, int j, int k){
    grid[i][j] = k;
}
void map::setGridValue(int i, int j, int k){
    grid[i][j] = k;
    switch(getLoadedGrid(1)){
        case 0:
            switch(getLoadedGrid(0)){
                case 0:
                    grid0[i][j] = k;
                break;
                case 1:
                    grid1[i][j] = k;
                break;
                case 2:
                    grid2[i][j] = k;
                break;
            }
        break;
        case 1:
            switch(getLoadedGrid(0)){
                case 0:
                break;
                case 1:
                    grid3[i][j] = k;
                break;
                case 2:
                    grid4[i][j] = k;
                break;
            }
        break;
        case 2:
            switch(getLoadedGrid(0)){
                case 0:
                    grid5[i][j] = k;
                break;
                case 1:
                    grid6[i][j] = k;
                break;
            }
        break;
        case 3:
            switch(getLoadedGrid(0)){
                case 0:
                break;
                case 1:
                    grid7[i][j] = k;
                break;
                case 2:
                    grid8[i][j] = k;
                break;
            }
        break;
    }
}
void map::loadGrid(int loadGrid[][12]){
    for (int a = 0; a< 12; a++){
        for (int b = 0; b < 12; b++){
            grid[a][b] = loadGrid[a][b];
        }
    }
}
void map::setLoadedGrid(int i, int j){
    loadedMap[0]=i;
    loadedMap[1]=j;
    switch(j){
        case 0:
            switch(i){
                case 0:
                    loadGrid(grid0);
                break;
                case 1:
                    loadGrid(grid1);
                break;
                case 2:
                    loadGrid(grid2);
                break;
            }
        break;
        case 1:
            switch(i){
                case 0:
                break;
                case 1:
                    loadGrid(grid3);
                break;
                case 2:
                    loadGrid(grid4);
                break;
            }
        break;
        case 2:
            switch(i){
                case 0:
                    loadGrid(grid5);
                break;
                case 1:
                    loadGrid(grid6);
                break;
            }
        break;
        case 3:
            switch(i){
                case 0:
                break;
                case 1:
                    loadGrid(grid7);
                break;
                case 2:
                    loadGrid(grid8);
                break;
            }
        break;
    }
}
int map::getLoadedGrid(int i){
    return loadedMap[i];
}

void map::loadForwardGrid(){
    setLoadedGrid(getLoadedGrid(0), getLoadedGrid(1)-1);
}
void map::loadBackwardGrid(){
    setLoadedGrid(getLoadedGrid(0), getLoadedGrid(1)+1);
}
void map::loadRightGrid(){
    setLoadedGrid(getLoadedGrid(0)+1, getLoadedGrid(1));
}
void map::loadLeftGrid(){
    setLoadedGrid(getLoadedGrid(0)-1, getLoadedGrid(1));
}