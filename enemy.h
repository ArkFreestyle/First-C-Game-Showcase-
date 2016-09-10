#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "random.h"
#include <vector>
#include <SFML/Graphics.hpp>


class enemy : public entity
{
    public:
        enemy();
        int dimensionx=32;
        int dimensiony=35;
        int dimensionxStart=32*0;
        int dimensionyStart=35*4;
        int hp = 3;
        int maxhp = 3;
        int attackDamage = 1;
        bool alive = true;
        bool canMoveUp = true;
        bool canMoveDown = true;
        bool canMoveLeft = true;
        bool canMoveRight = true;
        bool aggroed = false;
        bool boss1 = false;
        bool boss2 = false;
        float movementSpeed = 4;
        int walkingcounter = 0;
        int direction = 2; //if 1= UP, 2=down, 3= Left, 4=Right
        int counter = 0;
        void update();
        void updateMovement();
        protected:
    private:
};

#endif // ENEMY_H
