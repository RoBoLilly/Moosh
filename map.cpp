#include "map.h"

int map::gridValue(int i, int j){
    if(i>9 || j>9 || i<0 || j<0){
        return 0;   
    }
    return grid[i][j];
}
void map::setGridValue(int i, int j, int k){
    grid[i][j] = k;
}
