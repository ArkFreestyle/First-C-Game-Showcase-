#include "enemy.h"
#include "entity.h"
#include "random.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;
using namespace std;

enemy::enemy()
{
    rect.setSize(Vector2f(dimensionx,dimensiony));
    rect.setPosition(Vector2f(600,200));
    sprite.setTextureRect(sf::IntRect((walkingcounter*dimensionx) + dimensionxStart, (dimensiony*0) + dimensionyStart, dimensionx, dimensiony));
}

void enemy::update()
{
    sprite.setPosition(rect.getPosition());
    //text.setPosition(rect.getPosition().x , rect.getPosition().y - rect.getSize());
}


void enemy::updateMovement()
{

    if (direction == 1) // UP
    {
        if (canMoveUp == true)
        {
            rect.move(0,-movementSpeed);
            sprite.setTextureRect(sf::IntRect((walkingcounter*dimensionx) + dimensionxStart, (dimensiony*3) + dimensionyStart, dimensionx, dimensiony));
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
            //direction = 1;
        }

    }
    else if (direction == 2) //DOWN
    {
        if (canMoveDown == true)
        {
            rect.move(0,movementSpeed);
            sprite.setTextureRect(sf::IntRect((walkingcounter*dimensionx) + dimensionxStart, (dimensiony*0) + dimensionyStart, dimensionx, dimensiony));
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }

        //direction = 2;
    }
    else if (direction == 3) //LEFT
    {
        if (canMoveLeft == true)
        {
            rect.move(-movementSpeed,0);
            sprite.setTextureRect(sf::IntRect((walkingcounter*dimensionx) + dimensionxStart, (dimensiony*1) + dimensionyStart, dimensionx, dimensiony));
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }

        //direction = 3;
    }
    else if (direction == 4) //RIGHT
    {
        if (canMoveRight == true)
        {
            rect.move(movementSpeed,0);
            sprite.setTextureRect(sf::IntRect((walkingcounter*dimensionx) + dimensionxStart, (dimensiony*2) + dimensionyStart, dimensionx, dimensiony));
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }

        //direction = 4;

    }

    walkingcounter++;
         if(walkingcounter>=3)
         {
             walkingcounter = 0;
         }
         counter++;
         if (counter >= 100)
         {
             direction = generateRandom(5);
             counter = 0;
         }


}
