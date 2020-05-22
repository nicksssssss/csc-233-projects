#ifndef PLAYER_H
#define PLAYER_H


#include "Board.h"
#include "Space.h"
#include <vector>

class Player
{
    public:
        //constructors
        Player();
        Player(int, int);

        void move();
        int getX();
        int getY();

    private:
        int xPos;
        int yPos;
        int xBound;
        int yBound;
};
#endif