#include "pickup.h"
#include <SFML/Graphics.hpp>
using namespace sf;

pickup::pickup()
{
    rect.setSize(Vector2f(32,32));
    rect.setPosition(Vector2f(500,500));
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void pickup::update()
{
    sprite.setPosition(rect.getPosition());
    text.setPosition(rect.getPosition().x, rect.getPosition().y - 75);
}

void pickup::updateMovement()
{
         sprite.setTextureRect(sf::IntRect(counter*32, 32*0, 32, 32));
         counter++;
         if(counter>=8)
         {
             counter = 0;
         }

}
