#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "entity.h"


class projectile : public entity
{
    public:
        projectile();
        int movementSpeed = 20;
        int attackDamage = 1;
        //int counterDelay = 0;
        int counterLifetime = 0;
        int counterAnimation = 0;
        int Lifetime = 100;
        bool destroy = false;
        bool enemyProjectile = false;
        int direction = 0; //if 1= UP, 2=down, 3= Left, 4=Right
        void update();
        void updatePosition();
    protected:
    private:
};

#endif // PROJECTILE_H
