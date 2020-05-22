#include "Board.h"
#include <iostream>
#include "Space.h"
#include <vector>

Board::Board(){
    Board(10,10);
}

Board::Board(int x, int y)
{
    xBound = x;
    yBound = y;
    std::cout << "Making a new board " << xBound << " " << yBound << std::flush << std::endl;  
    //spaces.resize(xBound, std::vector<Space>(yBound, Space()));
    std::vector<std::vector<Space> > vec( xBound , std::vector<Space> (yBound));
    this->spaces = vec;
  
    for (int i = 0; i < xBound; i++) { 
        for (int j = 0; j < yBound; j++){ 
            this->spaces[i][j] = Space(); 
        } 
    } 
}

Space Board::getSpace(int x, int y) {
    std::cout << "x: " << x << " y: " << y << " xB:" << xBound << " yB:" << yBound << std::endl << std::flush;
    //std::cout << (x >= 0 && x < xBound && y >= 0 && y < yBound) << std::flush << std::endl;
    if (x >= 0 && x < xBound && y >= 0 && y < yBound) {
        return spaces.at(x).at(y);
    }
    else 
    {
        throw "Out of board bounds";
    }
}

int Board::getXBound()
{
    return xBound;
}

int Board::getYBound()
{
    return yBound;
}

