#include "Die.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Die::Die()
{
    Die::value = 1;    
    srand(time(NULL));
}
int Die::roll()
{        
    return (rand() % 6) + 1;
}
void Die::show()
{
    std::cout << value << std::endl;
}