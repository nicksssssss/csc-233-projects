#include "SuperBadGuy.h"
#include "Board.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

SuperBadGuy::SuperBadGuy(int x, int y, int xB, int yB)
{
    xPos = x;
    yPos = y;
    xBound = xB;
    yBound = yB;
    icon = 'S';
}

void SuperBadGuy::move(Board board, std::vector <SuperBadGuy> listOfDudes)
{
    int direction = 0;
    bool validSpace = false;
    srand(time(NULL));
    for (auto i = listOfDudes.begin(); i != listOfDudes.end(); i++)
    {
        int trys = 0;
        direction = (rand() % 4);
        while(!validSpace && trys < 4)
        {
            //check if moving to a valid space
            if(direction == 0)
            {
                validSpace == (!(yPos == 0) && board.getSpace(xPos, yPos - 1).isEmpty());
            }
            if(direction == 1)
            {
                validSpace = (!(xPos == 0) && board.getSpace(xPos - 1, yPos).isEmpty());
            }
            if(direction == 2)
            {
                validSpace = (!((yPos + 1) < yBound) && board.getSpace(xPos, yPos + 1).isEmpty());
            }
            if(direction == 3)
            {
                validSpace = (!((xPos + 1) < xBound) && board.getSpace(xPos + 1, yPos).isEmpty());
            }
            direction += 1;
            direction %= 4;
            trys++;
        }
            //move bad guy
            board.getSpace(xPos, yPos).removeEntity();
            if(direction == 0)
            {                
                --yPos;                
            }
            if(direction == 1)
            {
                --xPos;
            }
            if(direction == 2)
            {
                ++yPos;
            }
            if(direction == 3)
            {
                ++xPos;
            }
            board.getSpace(xPos, yPos).setEntity(this);
    }
}

char SuperBadGuy::getIcon()
{
    return icon;
}