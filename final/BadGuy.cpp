#include "BadGuy.h"

//constructor
BadGuy::BadGuy()
{
    icon = 'O';
}

int BadGuy::onCollision()
{
    //returns flag for losing the game
    return 2;
}

char BadGuy::getIcon()
{
    return icon;
}