#ifndef WALL_H
#define WALL_H
#include "entity.h"


class wall : public entity
{
    public:
        wall();
        bool destructable = false;
        int hp = 10;
        bool destroy = false;
        void update();
        void updateMovement();
        int counter = 0;
    protected:
    private:
};

#endif // WALL_H
