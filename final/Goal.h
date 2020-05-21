#ifndef GOAL_H
#define GOAL_H

#include "Entity.h"

class Goal: public Entity
{
    public:
        //Constructors
        Goal();

        int onCollision();
        char getIcon();
};
#endif