#ifndef PICKUP_H
#define PICKUP_H
#include "entity.h"


class pickup : public entity
{
    public:
        pickup();
        bool isCoin = false;
        bool isTripleFire = false;
        bool isNovaAttack = false;
        bool issuperNovaAttack = false;
        //bool isHeal = false;
        bool isHPbuff = false;
        int HPbuffValue = 5000;
        bool isDamageBuff = false;
        int DamageBuffValue = 2000;
        bool isMovementBuff = false;
        int MovementBuffValue = 10;
        bool inShop = false;
        int coinValue = 5;
        int cost = 0;
        bool destroy = false;
        int counter = 0;
        void update();
        void updateMovement();
    protected:
    private:
};

#endif // PICKUP_H
