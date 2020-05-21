#include "Space.h"
#include "Entity.h"

Space::Space()
{
    Entity *entity = nullptr;
}

bool Space::isEmpty()
{
    if (entity == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Entity* Space::getEntity()
{
    return entity;
}

void Space::setEntity(Entity* tempEntity)
{
    entity = tempEntity;
    return;
}

void Space::removeEntity()
{
    entity = nullptr;
    return;
}