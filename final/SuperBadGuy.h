#ifndef SUPERBADGUY_H
#define SUPERBADGUY_H

#include "Entity.h"
#include "BadGuy.h"
#include "Board.h"
#include <vector>

class SuperBadGuy: public BadGuy
{
    public:
        //Constructors
        SuperBadGuy(int,int,int,int);
        void move(Board);
        char getIcon();
        
    private:
            int xPos;
            int yPos;
            int xBound;
            int yBound;
};
#endif