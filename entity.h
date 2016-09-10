#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>


class entity
{
    public:
        entity();
        sf::RectangleShape rect;
        sf::Sprite sprite;
        sf::Text text;

};

#endif // ENTITY_H
