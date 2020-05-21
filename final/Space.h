#ifndef SPACE_H
#define SPACE_H

#include "Entity.h"

class Space
{
    public:
    //Constructors
    Space();

    bool isEmpty();
    Entity* getEntity();
    void setEntity(Entity*);
    void removeEntity();

    private:
    Entity *entity;
};
#endif