#include "Player.h"
#include "Space.h"
#include <vector>
#include <iostream>

//Constructors
Player::Player(){}

Player::Player(int x, int y)
{
    xPos = 0;
    yPos = 0;
    xBound = x;
    yBound = y;
}


void Player::move(std::vector <std::vector <Space>> spaces)
{
    char input = 'o';
    bool validSpace = false;
    while(!validSpace)
    {
        std::cin >> input;
        //check position is within the boards bounds
        if(input == 'w')
        {
            validSpace == (!(yPos == 0));
        }
        if(input == 'a')
        {
            validSpace = (!(xPos == 0));
        }
        if(input == 's')
        {
            validSpace = (!(yPos < yBound));
        }
        if(input == 'd')
        {
            validSpace = (!(xPos < xBound));
        }
        if (!validSpace) {
            std::cout << "\nInvalid space. Try Again...\n";
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