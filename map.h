#pragma once

class map {
    private:
    int grid[12][12];
    int loadedMap[2];
    public:
    int gridValue(int i, int j);
    void setGridValueNoSave(int i, int j, int k);
    void setGridValue(int i, int j, int k);
    void setLoadedGrid(int i, int j);
    int getLoadedGrid(int i);
    void loadGrid(int loadGrid[][12]);
    void loadForwardGrid();
    void loadBackwardGrid();
    void loadLeftGrid();
    void loadRightGrid();
    int isPermeable(int i, int j);
};