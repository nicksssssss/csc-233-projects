#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Space.h"
#include "Goal.h"
#include "BadGuy.h"
#include "SuperBadGuy.h"
#include <vector>
#include <stdlib.h>
#include <time.h>


Game::Game()
{
    board = Board(10,10);
    player = Player(10,10);
}

Game::Game(int bound)
{
    board = Board(bound, bound);
    player = Player(bound, bound);
}

Game::Game(int xBound, int yBound)
{
    board = Board(xBound, yBound);
    player = Player(xBound, yBound);
}

void Game::turn()
{
    std::vector <std::vector <Space>> spaces = board.getBoardInfo();
    int gameStatus = 0;

    player.move(spaces);
    gameStatus = checkForCollision();
    if(gameStatus == 0)
    {
        //SuperBadGuy.move();
    }
    
}

int Game::checkForCollision()
{
    /*  This function returns a 0, 1, or 2 based on whether the player runs 
        into anything on the board.

        0:Moves to an empty space(Continue)
        1:Runs into goal(Win)
        2:Runs into a BadGuy or SuperBadGuy(Lose)
    */
    Entity* landedOnEntity;
    std::vector <std::vector <Space>> spaces = board.getBoardInfo();
    //check the spot for other entities
    if(!(spaces[player.getX()][player.getY()].isEmpty()))//if space is not empty
    {
        landedOnEntity = spaces[player.getX()][player.getY()].getEntity();
        return (*landedOnEntity).onCollision(); //1 from goal, 2 from BadGuy or SuperBadGuy
    }
    else
    {
        return 0;
    }
}

void Game::makeBoard(Board board)
{
    int xBound = board.getXBound();
    int yBound = board.getYBound();
    int determineEntity;
    srand(time(NULL));

    Entity* dude;

    for(int i = 0; i < yBound; i++)
    {
        for(int j = 0; j < xBound; j++)
        {
            if((i+1) != yBound && (j+1) != xBound)
            {
                determineEntity = (rand() % 100) + 1;
                //80%: Empty space
                //10%: BadGuy
                //10%: SuperBadGuy
                if(determineEntity <= 10)
                {
                    dude = new BadGuy();
                }
                else if(determineEntity > 10 && determineEntity <= 20)
                {
                    dude = new SuperBadGuy(j, i, board.getXBound(), board.getYBound());
                }
            }
            else
            {
                dude = new Goal();
            }
            board.getSpace(i,j).setEntity(dude);
        }
    }
}