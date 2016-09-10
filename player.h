#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"
#include <SFML/Graphics.hpp>


class player: public entity
{
    public:
        player();
        int hp = 500;
        int coins = 0;
        bool tripleFire = false;
        bool novaAttack = false;
        bool superNovaAttack = false;
        int dimension = 65;
        float movementSpeed = 10;
        int walkingcounter = 0;
        bool canMoveUp = true;
        bool canMoveDown = true;
        bool canMoveLeft = true;
        bool canMoveRight = true;
        int attackDamage = 25;
        int kills = 0;
        int direction = 2; //if 1= UP, 2=down, 3= Left, 4=Right
        void update();
        sf::Clock clock1;
        sf::Time elapsed1;
        void updateMovement();


};

#endif // PLAYER_H
