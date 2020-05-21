#ifndef BADGUY_H
#define BADGUY_H

#include "Entity.h"

class BadGuy: public Entity
{
    public:
        //Constructors
        BadGuy();

        int onCollision();
        char getIcon();
};
#endif