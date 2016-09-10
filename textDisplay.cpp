#include "textDisplay.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


textDisplay::textDisplay()
{
    text.setColor(sf::Color::Red);
    //text.setPosition(300,300);
    text.setCharacterSize(25);
    text.setString(myString);
}

void textDisplay::update()
{
    text.move(0,-movementSpeed);
    counter++;
    if (counter >= LifeTime)
    {
        destroy = true;
    }
}

std::string textDisplay::to_string(int x)
{
    int number = x;

  std::stringstream ss;
  ss << number;

   return ss.str();
}
