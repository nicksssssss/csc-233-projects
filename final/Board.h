#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Space.h"

class Board {
    public:
        //constructor
        Board();
        Board(int, int);

        std::vector <std::vector <Space>> getBoardInfo();
        int getXBound();
        int getYBound();        
        Space getSpace(int, int);

    private:
        std::vector <std::vector <Space>> spaces;
        int xBound;
        int yBound;
};
#endif