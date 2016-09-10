#include "wall.h"

wall::wall()
{
    rect.setSize(sf::Vector2f(70,70));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Red);
}

void wall::update()
{
    sprite.setPosition(rect.getPosition());
}

void wall::updateMovement()
{
         sprite.setTextureRect(sf::IntRect(counter*72, 72*0, 72, 72));
         counter++;
         if(counter>=5)
         {
             counter = 0;
         }

}
