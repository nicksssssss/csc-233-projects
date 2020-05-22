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
#include <iostream>


Game::Game()
{
    Game(10);
}

Game::Game(int bound)
{
    Game(bound, bound);
}

Game::Game(int xBound, int yBound)
{
    board = Board(xBound, yBound);
    makeBoard();
    player = Player(xBound, yBound);
}

int Game::turn()
{
    printGame();
    std::vector <std::vector <Space>> spaces = board.getBoardInfo();
    int gameStatus = 0;

    player.move(spaces);
    gameStatus = checkForCollision();
    if(gameStatus == 0)
    {
        for (auto dude: dudes) {
            dude.move(board);
        }
    }
    else if(gameStatus == 1) {
        std::cout << "YOU WON" << std::endl;
    }
    else if(gameStatus == 2){
        std::cout << "YOU LOST" << std::endl;
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

void Game::makeBoard()
{
    int xBound = board.getXBound();
    int yBound = board.getYBound();
    int determineEntity;
    srand(time(NULL));

    for(int i = 0; i < yBound; i++)
    {
        for(int j = 0; j < xBound; j++)
        {
            Entity* dude;
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
                    dudes.push_back(*dynamic_cast<SuperBadGuy*>(dude));
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

void Game::printGame() {    
    for (int i = 0; i < board.getXBound(); i++) {
        for (int j = 0; j < board.getYBound(); j++) {
            if (i == player.getX() && j == player.getY()) {
                std::cout << "P";
            } else {
                if(board.getSpace(i,j).isEmpty()) {
                    std::cout << ".";
                } else {
                    std::cout << (*board.getSpace(i,j).getEntity()).getIcon();
                }
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}