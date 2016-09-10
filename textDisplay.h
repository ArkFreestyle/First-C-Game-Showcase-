#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "entity.h"
#include <string>


class textDisplay : public entity
{
    public:
        textDisplay();
        int movementSpeed = 5;
        int LifeTime = 50;
        int counter = 0;
        bool destroy = false;
        std::string myString = "Default";
        std::string to_string(int x);
        void update();
    protected:
    private:
};

#endif // TEXTDISPLAY_H
