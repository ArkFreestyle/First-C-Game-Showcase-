#include "random.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;



int generateRandom(int max)
{
    int randomNumber = rand();
    float random = (randomNumber % max) + 1;
    int myRandom = random;
    return myRandom;
}

int generateRandom0(int max)
{
    srand(time(0));
    int random0 = rand()%max;
    return random0;
}

bool generateRandomBool()
{
    srand(time(0));
    int randombool = (rand()%2)+1;
    if (randombool == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
