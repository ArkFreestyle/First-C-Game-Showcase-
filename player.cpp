#include "player.h"
#include "entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;


player::player()
{
    rect.setSize(Vector2f(dimension,dimension));
    rect.setPosition(Vector2f(400,200));
    sprite.setTextureRect(sf::IntRect(0, 0, dimension, dimension));
}


void player::update()
{
    sprite.setPosition(rect.getPosition());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(canMoveUp == true)
        {
            rect.move(0,-movementSpeed);
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }

        sprite.setTextureRect(sf::IntRect(walkingcounter*dimension, dimension*3, dimension, dimension));
        direction = 1;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (canMoveDown == true)
        {
            rect.move(0,movementSpeed);
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }

        sprite.setTextureRect(sf::IntRect(walkingcounter*dimension, dimension*0, dimension, dimension));
        direction = 2;

    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (canMoveLeft == true)
        {
            rect.move(-movementSpeed,0);
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }

        sprite.setTextureRect(sf::IntRect(walkingcounter*dimension, dimension*1, dimension, dimension));
        direction = 3;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (canMoveRight == true)
        {
            rect.move(movementSpeed,0);
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
        sprite.setTextureRect(sf::IntRect(walkingcounter*dimension, dimension*2, dimension, dimension));
        direction = 4;


    }

}




void player::updateMovement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(canMoveUp==true)
        {
            rect.move(0,-movementSpeed);
        }

        sprite.setTextureRect(sf::IntRect(walkingcounter*dimension, dimension*3, dimension, dimension));
        direction = 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(canMoveDown==true)
        {
             rect.move(0,movementSpeed);
        }

        sprite.setTextureRect(sf::IntRect(walkingcounter*dimension, dimension*0, dimension, dimension));
        direction = 2;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(canMoveLeft==true)
        {
             rect.move(-movementSpeed,0);
        }

        sprite.setTextureRect(sf::IntRect(walkingcounter*dimension, dimension*1, dimension, dimension));
        direction = 3;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(canMoveRight==true)
        {
            rect.move(movementSpeed,0);
        }

        sprite.setTextureRect(sf::IntRect(walkingcounter*dimension, dimension*2, dimension, dimension));
        direction = 4;

    }

    walkingcounter++;
         if(walkingcounter>=3)
         {
             walkingcounter = 0;
         }


}
