#include "Game.h"
#include <iostream>

using namespace std;
int main()
{
    std::cout << "starting Game" << std::endl << std::flush;
    Game game = Game();
    int gameStatus = 0;
    while(gameStatus == 0) {
        gameStatus = game.turn();
    }
    return 0;
}
/*POSSIBLE PROBLEMS

-none
-might be that spaces aren't being passed by reference

*/