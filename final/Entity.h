#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
    public:
        virtual int onCollision() = 0;
    protected:
        char icon;
};
#endif