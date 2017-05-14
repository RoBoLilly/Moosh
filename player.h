#pragma once

class player {
    private:
        int location[2];
        int inventory;
    public:
        int getLocation(int i);
        void setLocation(int i, int coord);
        int getInventory();
        void setInventory(int i);
};