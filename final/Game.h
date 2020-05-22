#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "SuperBadGuy.h"

class Game
{
    public:
        //constructors
        Game();
        Game(int);
        Game(int, int);

        int turn();
        int checkForCollision();
        void makeBoard();
        void printGame();
    private:
        std::vector<SuperBadGuy> dudes;
        Board board;
        Player player;
};
#endif