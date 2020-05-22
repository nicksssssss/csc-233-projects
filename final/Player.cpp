#include "Player.h"
#include "Space.h"
#include <vector>
#include <iostream>

//Constructors
Player::Player(){
    this->xPos = 0;
    this->yPos = 0;
}

Player::Player(int x, int y)
{
    std::cout << "player at make: " << x << " " << y << std::flush <<std::endl;
    this->xPos = 0;
    this->yPos = 0;
    xBound = x;
    yBound = y;
}


void Player::move()
{
    char input = 'o';
    bool validSpace = false;
    while(!validSpace)
    {
        std::cin >> input;
        //check position is within the boards bounds
        if(input == 'w')
        {
            validSpace = (yPos != 0);
        }
        else if(input == 'a')
        {
            validSpace = (xPos != 0);
        }
        else if(input == 's')
        {
            validSpace = (yPos < yBound - 1);
        }
        else if(input == 'd')
        {
            validSpace = (xPos < xBound - 1);
        }
        if (!validSpace) {
            std::cout << xBound << yBound << "\nInvalid space. Try Again...\n";
        }
    }
    //move player
    if(input == 'w')
    {
        --yPos;
    }
    if(input == 'a')
    {
        --xPos;
    }
    if(input == 's')
    {
        ++yPos;
    }
    if(input == 'd')
    {
        ++xPos;
    }
}

int Player::getX()
{
    return xPos;
}

int Player::getY()
{
    return yPos;
}