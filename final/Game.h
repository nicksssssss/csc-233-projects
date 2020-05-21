#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game
{
    public:
        //constructors
        Game();
        Game(int);
        Game(int, int);

        void turn();
        int checkForCollision();
        void makeBoard(Board);
        void printBoard();
    private:
        Board board;
        Player player;
};
#endif