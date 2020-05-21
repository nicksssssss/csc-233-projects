#include "Board.h"
#include "Space.h"
#include <vector>

Board::Board(){}

Board::Board(int x, int y)
{
    xBound = x;
    yBound = y;
    for (int i = 0; i < xBound; i++) {
        for (int j = 0; j < yBound; j++) {
            spaces[i][j] = Space();
        }
    }
}

Space Board::getSpace(int x, int y) {
    if (x >= 0 && x < xBound && y >= 0 && y < yBound) {
        return spaces[x][y];
    }
    throw 20;
}

std::vector <std::vector <Space>> Board::getBoardInfo()
{
    return spaces;
}

int Board::getXBound()
{
    return xBound;
}

int Board::getYBound()
{
    return yBound;
}

