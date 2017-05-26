#pragma once

class enemy {
    private:
    int location[2];
    int mapLocation[2];
    int AIstate;
    public:
    int getLocation(int i);
    void setLocation(int i, int j);
    int getMapLocation(int i);
    void setMapLocation(int i, int j);
    int getAIstate();
    void setAIstate(int i);
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    int attackForward();
    int attackBackward();
    int attackLeft();
    int attackRight();

};