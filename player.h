#pragma once

class player {
    private:
        int location[2];
        int inventory[10];
        int inventorySize;
        int invertControls;
    public:
        void setLocation(int i, int coord);
        int getLocation(int i);
        void moveForward();
        void moveBackward();
        void moveLeft();
        void moveRight();
        void setInventory(int i, int j);
        int getInventory(int i);
        void setInventorySize(int i);
        int getInventorySize();
        void setInvertControls(int i);
        int getInvertControls();
};