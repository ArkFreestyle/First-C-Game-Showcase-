#include <iostream>
#include "projectile.h"
#include "entity.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

projectile::projectile()
{
    rect.setSize(Vector2f(75,75));
    //rect.setPosition(0,0);
    rect.setFillColor(Color::Red);
    sprite.setTextureRect(sf::IntRect(0, 0, 75, 75));
    if (enemyProjectile==true)
    {
        movementSpeed = 10;
    }
}

void projectile::update()
{
    if(direction == 1) //UP
    {
        //rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterAnimation*75, 75*3, 75, 75));
    }
    if(direction == 2) //DOWN
    {
        //rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterAnimation*75, 0, 75, 75));
    }
    if(direction == 3) //LEFT
    {
        //rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterAnimation*75, 75*1, 75, 75));
    }
    if(direction == 4) //RIGHT
    {
        //rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterAnimation*75, 75*2, 75, 75));
    }
    counterLifetime++;
    if(counterLifetime >= Lifetime)
    {
        counterLifetime = 0;
        destroy = true;
    }

    counterAnimation++;
    if(counterAnimation >= 2)
    {
        counterAnimation = 0;
    }



    //Setting sprite to rect's position
    //sprite.setPosition(rect.getPosition());
}
void projectile::updatePosition()
{
    //Setting sprite to rect's position
    sprite.setPosition(rect.getPosition());
    //Trying to keep the rect moving for speed
    if(direction == 1) //UP
    {
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterAnimation*75, 75*3, 75, 75));
    }
    if(direction == 2) //DOWN
    {
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterAnimation*75, 0, 75, 75));
    }
    if(direction == 3) //LEFT
    {
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterAnimation*75, 75*1, 75, 75));
    }
    if(direction == 4) //RIGHT
    {
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterAnimation*75, 75*2, 75, 75));
    }

}















