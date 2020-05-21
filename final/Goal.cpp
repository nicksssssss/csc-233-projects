#include "Goal.h"

Goal::Goal()
{
    icon = 'X';
}

int Goal::onCollision()
{
    //returns flag for winning the game
    return 1;
}

char Goal::getIcon()
{
    return icon;
}