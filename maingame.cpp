#include <iostream>
#include <vector>
#include "entity.h"
#include "player.h"
#include "projectile.h"
#include "enemy.h"
#include "random.h"
#include "pickup.h"
#include "textDisplay.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace sf;
using namespace std;







int main()
{
    srand(time(NULL));
    sf::Clock clock, clock2, clock3, clock4, clock5, clock6, clock7, clock8;
    sf::Time elapsed1, elapsed2, elapsed3, elapsed4, elapsed5, elapsed6, elapsed7, elapsed8;
    int counter, counter2, counter3;
    int roomSize;
    int verticalDoorLocationRight;
    int verticalDoorLocationLeft;
    int horizontalDoorLocationUp;
    int horizontalDoorLocationDown;
    int roomStartX;
    int roomStartY;
    int tempRandom;
    int RoomSpawnRate = 120; //Increase this for lesser enemies, decrease it for more enemies.


    //Creating the main window
    RenderWindow window;
    window.create(VideoMode(1000, 800), "PLATFORMER!", Style::Default);
    window.setFramerateLimit(60);

    //Creating a player view
    sf::View view1;
    view1.setSize(sf::Vector2f(window.getSize().x , window.getSize().y));
    view1.setCenter(window.getSize().x/2 , window.getSize().y/2);
    window.setView(view1);

    //Texture for Charizard
        Texture textureCharizard;
        if(!textureCharizard.loadFromFile("charizard.png"))
        {
            return EXIT_FAILURE;
        }
        //Texture for boss Groudon
        Texture textureBoss;
        if(!textureBoss.loadFromFile("groudon.png"))
        {
            return EXIT_FAILURE;
        }
        //Texture for boss2
        Texture textureBoss2;
        if(!textureBoss2.loadFromFile("dragon.png"))
        {
            return EXIT_FAILURE;
        }
        //Texture for enemies
        Texture textureEnemies;
        if(!textureEnemies.loadFromFile("enemies.png"))
        {
            return EXIT_FAILURE;
        }
        //Getting the coin texture
        Texture textureCoin;
        if(!textureCoin.loadFromFile("coins.png"))
        {
            return EXIT_FAILURE;
        }
        //Making a FireBall texture
         Texture textureFireball;
        if(!textureFireball.loadFromFile("FireBall.png"))
        {
            return EXIT_FAILURE;
        }
        //Powerups texture
        Texture texturePowerup;
        if(!texturePowerup.loadFromFile("powerups.png"))
        {
            return EXIT_FAILURE;
        }
        //Ground texture
        Texture textureGround;
        if(!textureGround.loadFromFile("ground.png"))
        {
            return EXIT_FAILURE;
        }
        Texture textureBoulder;
        if(!textureBoulder.loadFromFile("crate.png"))
        {
            return EXIT_FAILURE;
        }
        Texture textureWall;
        if(!textureWall.loadFromFile("brick.png"))
        {
            return EXIT_FAILURE;
        }
        //Making text
        sf::Font font;
        if (!font.loadFromFile("victorpixel.ttf"))
        {
            return EXIT_FAILURE;
        }
        //Text for Coins
        sf::Text text, text2, text3, text4;
        text.setFont(font);
        text.setColor(sf::Color::Red);
        text.setCharacterSize(25);
        text.setPosition(0, 0);

        text2.setFont(font);
        text2.setColor(sf::Color::Red);
        text2.setCharacterSize(25);
        text2.setPosition(200, 0);

        text3.setFont(font);
        text3.setColor(sf::Color::Red);
        text3.setCharacterSize(25);
        text3.setPosition(400, 0);

        text4.setFont(font);
        text4.setColor(sf::Color::Red);
        text4.setCharacterSize(25);
        text4.setPosition(600, 0);





        //Make a player object
        class player player1;
        player1.sprite.setTexture(textureCharizard);
        //Make a projectile object
        class projectile projectile1;
        projectile1.sprite.setTexture(textureFireball);
        //Make an enemy object
        class enemy enemy1;
        enemy1.sprite.setTexture(textureEnemies);
        enemy1.text.setFont(font);
        enemy1.text.setColor(sf::Color::Red);
        //Make an enemy BOSS object
        class enemy enemyBOSS;
        enemyBOSS.sprite.setTexture(textureBoss);
        enemyBOSS.rect.setSize(Vector2f(100,100));
        enemyBOSS.dimensionx = 100;
        enemyBOSS.dimensiony = 100;
        enemyBOSS.dimensionxStart = 0;
        enemyBOSS.dimensionyStart = 0;
        //enemyBOSS.attackDamage = 100;
        enemyBOSS.movementSpeed = 7;
        enemyBOSS.hp = 999999;
        enemyBOSS.maxhp = 999999;
        enemyBOSS.boss1 = true;
        enemyBOSS.boss2 = false;
        enemyBOSS.aggroed = false;
        enemyBOSS.text.setFont(font);
        enemyBOSS.text.setColor(sf::Color::Red);
        enemyBOSS.rect.setPosition(10*70 + 10*70 +30*70 +10*70,100);

        class enemy enemyBOSS2;
        enemyBOSS2.sprite.setTexture(textureBoss2);
        enemyBOSS2.rect.setSize(Vector2f(80,64));
        enemyBOSS2.dimensionx = 80;
        enemyBOSS2.dimensiony = 64;
        enemyBOSS2.dimensionxStart = 0;
        enemyBOSS2.dimensionyStart = 0;
        //enemyBOSS.attackDamage = 100;
        enemyBOSS2.movementSpeed = 7;
        enemyBOSS2.hp = 10000;
        enemyBOSS2.maxhp = 10000;
        enemyBOSS2.boss2 = true;
        enemyBOSS2.boss1 = false;
        enemyBOSS2.aggroed = false;
        enemyBOSS2.text.setFont(font);
        enemyBOSS2.text.setColor(sf::Color::Red);
        enemyBOSS2.rect.setPosition(10*70 + 10*70 +15*70,100);
        //Make a text object
        class textDisplay text1;
        text1.text.setFont(font);
        //Make a pickup object
        class pickup pickup1;
        pickup1.text.setFont(font);
        pickup1.text.setCharacterSize(20);
        pickup1.text.setColor(sf::Color::Magenta);
        //Wall object
        class wall wall1;





        //Making a vector array for projectiles
        vector<projectile>::const_iterator iter;
        vector<projectile>::iterator iter4;
        vector<projectile> projectileArray;

        //Making a vector array for enemies and loading the sprite
        vector<enemy>::const_iterator iter2;
        vector<enemy>::iterator iter3;
        vector<enemy> enemyArray;
        //enemy1.rect.setPosition(600, 200);
        //enemy1.sprite.setTexture(chtexture);
        enemyArray.push_back(enemyBOSS);
        enemyArray.push_back(enemyBOSS2);


        //Making a vector for textDisplay
        vector<textDisplay>::const_iterator iter5;
        vector<textDisplay>::iterator iter6;
        vector<textDisplay> textDisplayArray;


        //Making a vector array for our coins
        vector<pickup>::const_iterator iter7;
        vector<pickup>::iterator iter8;
        vector<pickup> pickupArray;
        pickup1.sprite.setTexture(textureCoin);
//        pickup1.isCoin = true;
//        pickupArray.push_back(pickup1);


        //Vector array for Wall
        vector<wall>::const_iterator iter9;
        vector<wall>::iterator iter10;
        vector<wall> wallArray;


        //Ground vector array
        vector<wall>::const_iterator iter11;
        vector<wall> groundArray;
        class wall ground1;
        ground1.sprite.setTexture(textureGround);
        ground1.sprite.setTextureRect(sf::IntRect(64*3, 32*8, 64, 64));
        ground1.sprite.setPosition(player1.rect.getPosition());
        //groundArray.push_back(ground1);




//*******************************************************MUSIC AND SOUND EFFECTS**********************************************************************************

 // Load a music to play
    sf::Music music;
    if (!music.openFromFile("music1.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();
    music.setLoop(true);


 // Sound effects
    sf::SoundBuffer bufferShot;
    if (!bufferShot.loadFromFile("shot.ogg"))
        return -1;
    sf::Sound soundShot;
    soundShot.setBuffer(bufferShot);

    sf::SoundBuffer bufferCollision;
    if (!bufferCollision.loadFromFile("collision.ogg"))
        return -1;
    sf::Sound soundCollision;
    soundCollision.setBuffer(bufferCollision);

    sf::SoundBuffer bufferCoin;
    if (!bufferCoin.loadFromFile("coin.wav"))
        return -1;
    sf::Sound soundCoin;
    soundCoin.setBuffer(bufferCoin);

    sf::SoundBuffer bufferPlayerhit;
    if (!bufferPlayerhit.loadFromFile("playerhit.ogg"))
        return -1;
    sf::Sound soundPlayerhit;
    soundPlayerhit.setBuffer(bufferPlayerhit);

    sf::SoundBuffer bufferGroudon;
    if (!bufferGroudon.loadFromFile("Groudon2.ogg"))
        return -1;
    sf::Sound soundGroudon;
    soundGroudon.setBuffer(bufferGroudon);











//***********************************************************  CREATING THE ROOMS ********************************************************************************************






        //ROOM 1:
        roomSize = 10;
        verticalDoorLocationRight = 3;
        verticalDoorLocationLeft = 100;
        horizontalDoorLocationUp = 100;
        horizontalDoorLocationDown = 3;
        roomStartX = 0;
        roomStartY = 0;
        wall1.destructable = false;
        wall1.sprite.setTexture(textureWall);
        //horizontal wall
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationUp && counter != horizontalDoorLocationUp + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != verticalDoorLocationLeft && counter != verticalDoorLocationLeft + 1)
            {
                wall1.rect.setPosition(roomStartX , 70 * counter + roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //horizontal bottom wall
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationDown && counter != horizontalDoorLocationDown + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY + (70*roomSize));
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall right
        counter = 0;
        while(counter < roomSize + 1)
        {
            if (counter != verticalDoorLocationRight && counter != verticalDoorLocationRight + 1)
            {
                wall1.rect.setPosition(roomStartX + (70*roomSize) , (70*counter) + roomStartY);
                wallArray.push_back(wall1);

            }
            counter++;

        }
        //Random Stuff in the room
        wall1.sprite.setTexture(textureBoulder);
        wall1.sprite.setTextureRect(sf::IntRect(0,0,72,72));

        counter = 0;
        while (counter < (roomSize - 1))
        {
            counter2 = 0;
            while (counter2 < (roomSize - 1))
            {
                tempRandom = generateRandom(RoomSpawnRate);
                if (tempRandom == 1)
                {
                    //Destructable boxes
                    wall1.destructable = true;
                    wall1.rect.setFillColor(sf::Color::Yellow);
                    wall1.rect.setPosition(counter*70 + 70 + roomStartX , counter2*70 + 70 + roomStartY );
                    wallArray.push_back(wall1);
                    //Setting the stuff back
                    wall1.destructable = false;
                    wall1.rect.setFillColor(sf::Color::Red);
                }
                if (tempRandom == 2)
                {
                    //Skeletons
                    enemy1.dimensionxStart = 32*0;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 100;
                    enemy1.maxhp = 100;
                    enemy1.attackDamage = 11;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 3)
                {
                    //Thugs
                    enemy1.dimensionxStart = 32*0;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 50;
                    enemy1.maxhp = 50;
                    enemy1.attackDamage = 5;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 4)
                {
                    //Assassins
                    enemy1.dimensionxStart = 32*3;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 110;
                    enemy1.maxhp = 110;
                    enemy1.attackDamage = 15;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 5)
                {
                    //Pink armour dudes
                    enemy1.dimensionxStart = 32*6;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 75;
                    enemy1.maxhp = 75;
                    enemy1.attackDamage = 12;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 6)
                {
                    //Rock armour dudes
                    enemy1.dimensionxStart = 32*9;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 140;
                    enemy1.maxhp = 140;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 7)
                {
                    //Mohawk armour dudes
                    enemy1.dimensionxStart = 32*3;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 90;
                    enemy1.maxhp = 90;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 8)
                {
                    //Cyborg thug dudes
                    enemy1.dimensionxStart = 32*6;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 80;
                    enemy1.maxhp = 80;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 9)
                {
                    //Monster dudes
                    enemy1.dimensionxStart = 32*9;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 200;
                    enemy1.maxhp = 200;
                    enemy1.attackDamage = 20;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                counter2++;
            }
            counter++;
        }
        //Lay down your floor!
        counter = 0;
        while (counter <= roomSize+1)
        {
            counter2 = 0;
            while(counter2 <= roomSize+1)
            {
                ground1.sprite.setPosition(60*counter, 60*counter2);
                groundArray.push_back(ground1);
                counter2++;
            }

            counter++;
        }




        //ROOM 2
        roomSize = 10;
        verticalDoorLocationRight = 5;
        verticalDoorLocationLeft = 3;
        horizontalDoorLocationUp = 5;
        horizontalDoorLocationDown = 5;
        roomStartX = 10*70;
        roomStartY = 0;
        wall1.destructable = false;
        wall1.sprite.setTexture(textureWall);
        //horizontal wall top
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationUp && counter != horizontalDoorLocationUp + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall left
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != verticalDoorLocationLeft && counter != verticalDoorLocationLeft + 1)
            {
                wall1.rect.setPosition(roomStartX , 70 * counter + roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
         }
        //horizontal bottom wall
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationDown && counter != horizontalDoorLocationDown + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY + (70*roomSize));
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall right
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != verticalDoorLocationRight && counter != verticalDoorLocationRight + 1)
            {
                wall1.rect.setPosition(roomStartX + 70*roomSize , 70*counter + roomStartY);
                wallArray.push_back(wall1);

            }
            counter++;

        }
        //Random Stuff in the room
        wall1.sprite.setTexture(textureBoulder);
        wall1.sprite.setTextureRect(sf::IntRect(0,0,72,72));
        counter = 0;
        while (counter < (roomSize - 1))
        {
            counter2 = 0;
            while (counter2 < (roomSize - 1))
            {
                tempRandom = generateRandom(RoomSpawnRate);
                if (tempRandom == 1)
                {
                    //Destructable boxes
                    wall1.destructable = true;
                    wall1.rect.setFillColor(sf::Color::Yellow);
                    wall1.rect.setPosition(counter*70 + 70 + roomStartX , counter2*70 + 70 + roomStartY );
                    wallArray.push_back(wall1);
                    //Setting the stuff back
                    wall1.destructable = false;
                    wall1.rect.setFillColor(sf::Color::Red);
                }
                if (tempRandom == 2)
                {
                    //Skeletons
                    enemy1.dimensionxStart = 32*0;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 100;
                    enemy1.maxhp = 100;
                    enemy1.attackDamage = 11;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 3)
                {
                    //Thugs
                    enemy1.dimensionxStart = 32*0;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 50;
                    enemy1.maxhp = 50;
                    enemy1.attackDamage = 5;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 4)
                {
                    //Assassins
                    enemy1.dimensionxStart = 32*3;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 110;
                    enemy1.maxhp = 110;
                    enemy1.attackDamage = 15;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 5)
                {
                    //Pink armour dudes
                    enemy1.dimensionxStart = 32*6;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 75;
                    enemy1.maxhp = 75;
                    enemy1.attackDamage = 12;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 6)
                {
                    //Rock armour dudes
                    enemy1.dimensionxStart = 32*9;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 140;
                    enemy1.maxhp = 140;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 7)
                {
                    //Mohawk armour dudes
                    enemy1.dimensionxStart = 32*3;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 90;
                    enemy1.maxhp = 90;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 8)
                {
                    //Cyborg thug dudes
                    enemy1.dimensionxStart = 32*6;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 80;
                    enemy1.maxhp = 80;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 9)
                {
                    //Monster dudes
                    enemy1.dimensionxStart = 32*9;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 200;
                    enemy1.maxhp = 200;
                    enemy1.attackDamage = 20;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                counter2++;
            }
            counter++;
        }
        //Lay down your floor!
        counter = 0;
        while (counter <= roomSize+1)
        {
            counter2 = 0;
            while(counter2 <= roomSize+1)
            {
                ground1.sprite.setPosition(60*counter + roomStartX, 60*counter2 + roomStartY);
                groundArray.push_back(ground1);
                counter2++;
            }

            counter++;
        }



        //ROOM 3:
        roomSize = 10;
        verticalDoorLocationRight = 100;
        verticalDoorLocationLeft = 100;
        horizontalDoorLocationUp = 5;
        horizontalDoorLocationDown = 100;
        roomStartX = 10*70;
        roomStartY = 10*70;
        wall1.destructable = false;
        wall1.sprite.setTexture(textureWall);
        //horizontal wall top
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationUp && counter != horizontalDoorLocationUp + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall left
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != verticalDoorLocationLeft && counter != verticalDoorLocationLeft + 1)
            {
                wall1.rect.setPosition(roomStartX , 70 * counter + roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
         }
        //horizontal bottom wall
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationDown && counter != horizontalDoorLocationDown + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY + (70*roomSize));
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall right
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != verticalDoorLocationRight && counter != verticalDoorLocationRight + 1)
            {
                wall1.rect.setPosition(roomStartX + 70*roomSize , 70*counter + roomStartY);
                wallArray.push_back(wall1);

            }
            counter++;

        }
        //Random Stuff in the room
        wall1.sprite.setTexture(textureBoulder);
        wall1.sprite.setTextureRect(sf::IntRect(0,0,72,72));
        counter = 0;
        while (counter < (roomSize - 1))
        {
            counter2 = 0;
            while (counter2 < (roomSize - 1))
            {
                tempRandom = generateRandom(RoomSpawnRate);
                if (tempRandom == 1)
                {
                    //Destructable boxes
                    wall1.destructable = true;
                    wall1.rect.setFillColor(sf::Color::Yellow);
                    wall1.rect.setPosition(counter*70 + 70 + roomStartX , counter2*70 + 70 + roomStartY );
                    wallArray.push_back(wall1);
                    //Setting the stuff back
                    wall1.destructable = false;
                    wall1.rect.setFillColor(sf::Color::Red);
                }
                if (tempRandom == 2)
                {
                    //Skeletons
                    enemy1.dimensionxStart = 32*0;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 100;
                    enemy1.maxhp = 100;
                    enemy1.attackDamage = 11;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 3)
                {
                    //Thugs
                    enemy1.dimensionxStart = 32*0;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 50;
                    enemy1.maxhp = 50;
                    enemy1.attackDamage = 5;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 4)
                {
                    //Assassins
                    enemy1.dimensionxStart = 32*3;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 110;
                    enemy1.maxhp = 110;
                    enemy1.attackDamage = 15;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 5)
                {
                    //Pink armour dudes
                    enemy1.dimensionxStart = 32*6;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 75;
                    enemy1.maxhp = 75;
                    enemy1.attackDamage = 12;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 6)
                {
                    //Rock armour dudes
                    enemy1.dimensionxStart = 32*9;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 140;
                    enemy1.maxhp = 140;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 7)
                {
                    //Mohawk armour dudes
                    enemy1.dimensionxStart = 32*3;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 90;
                    enemy1.maxhp = 90;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 8)
                {
                    //Cyborg thug dudes
                    enemy1.dimensionxStart = 32*6;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 80;
                    enemy1.maxhp = 80;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 9)
                {
                    //Monster dudes
                    enemy1.dimensionxStart = 32*9;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 200;
                    enemy1.maxhp = 200;
                    enemy1.attackDamage = 20;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                counter2++;
            }
            counter++;
        }
        //Lay down your floor!
        counter = 0;
        while (counter <= roomSize+1)
        {
            counter2 = 0;
            while(counter2 <= roomSize+1)
            {
                ground1.sprite.setPosition(60*counter + roomStartX, 60*counter2 + roomStartY);
                groundArray.push_back(ground1);
                counter2++;
            }

            counter++;
        }

        //ROOM 4
        roomSize = 10;
        verticalDoorLocationRight = 100;
        verticalDoorLocationLeft = 100;
        horizontalDoorLocationUp = 100;
        horizontalDoorLocationDown = 5;
        roomStartX = 10*70;
        roomStartY = -1*(10*70);
        wall1.destructable = false;
        wall1.sprite.setTexture(textureWall);
        //horizontal wall top
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationUp && counter != horizontalDoorLocationUp + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall left
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != verticalDoorLocationLeft && counter != verticalDoorLocationLeft + 1)
            {
                wall1.rect.setPosition(roomStartX , 70 * counter + roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
         }
        //horizontal bottom wall
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationDown && counter != horizontalDoorLocationDown + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY + (70*roomSize));
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall right
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != verticalDoorLocationRight && counter != verticalDoorLocationRight + 1)
            {
                wall1.rect.setPosition(roomStartX + 70*roomSize , 70*counter + roomStartY);
                wallArray.push_back(wall1);

            }
            counter++;

        }
        //Random Stuff in the room
        wall1.sprite.setTexture(textureBoulder);
        wall1.sprite.setTextureRect(sf::IntRect(0,0,72,72));
        counter = 0;
        while (counter < (roomSize - 1))
        {
            counter2 = 0;
            while (counter2 < (roomSize - 1))
            {
                tempRandom = generateRandom(RoomSpawnRate);
                if (tempRandom == 1)
                {
                    //Destructable boxes
                    wall1.destructable = true;
                    wall1.rect.setFillColor(sf::Color::Yellow);
                    wall1.rect.setPosition(counter*70 + 70 + roomStartX , counter2*70 + 70 + roomStartY );
                    wallArray.push_back(wall1);
                    //Setting the stuff back
                    wall1.destructable = false;
                    wall1.rect.setFillColor(sf::Color::Red);
                }
                if (tempRandom == 2)
                {
                    //Skeletons
                    enemy1.dimensionxStart = 32*0;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 100;
                    enemy1.maxhp = 100;
                    enemy1.attackDamage = 11;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 3)
                {
                    //Thugs
                    enemy1.dimensionxStart = 32*0;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 50;
                    enemy1.maxhp = 50;
                    enemy1.attackDamage = 5;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 4)
                {
                    //Assassins
                    enemy1.dimensionxStart = 32*3;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 110;
                    enemy1.maxhp = 110;
                    enemy1.attackDamage = 15;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 5)
                {
                    //Pink armour dudes
                    enemy1.dimensionxStart = 32*6;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 75;
                    enemy1.maxhp = 75;
                    enemy1.attackDamage = 12;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 6)
                {
                    //Rock armour dudes
                    enemy1.dimensionxStart = 32*9;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 140;
                    enemy1.maxhp = 140;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 7)
                {
                    //Mohawk armour dudes
                    enemy1.dimensionxStart = 32*3;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 90;
                    enemy1.maxhp = 90;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 8)
                {
                    //Cyborg thug dudes
                    enemy1.dimensionxStart = 32*6;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 80;
                    enemy1.maxhp = 80;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 9)
                {
                    //Monster dudes
                    enemy1.dimensionxStart = 32*9;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 200;
                    enemy1.maxhp = 200;
                    enemy1.attackDamage = 20;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                counter2++;
            }
            counter++;
        }
        //Lay down your floor!
        counter = 0;
        while (counter <= roomSize+1)
        {
            counter2 = 0;
            while(counter2 <= roomSize+1)
            {
                ground1.sprite.setPosition(60*counter + roomStartX, 60*counter2 + roomStartY);
                groundArray.push_back(ground1);
                counter2++;
            }

            counter++;
        }

        //ROOM 5
        roomSize = 30;
        verticalDoorLocationRight = 3;
        verticalDoorLocationLeft = 15;
        horizontalDoorLocationUp = 100;
        horizontalDoorLocationDown = 100;
        roomStartX = 10*70 + 10*70;
        roomStartY = -1*10*70;
        wall1.destructable = false;
        wall1.sprite.setTexture(textureWall);
        //horizontal wall top
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationUp && counter != horizontalDoorLocationUp + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall left
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != verticalDoorLocationLeft && counter != verticalDoorLocationLeft + 1)
            {
                wall1.rect.setPosition(roomStartX , 70 * counter + roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
         }
        //horizontal bottom wall
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationDown && counter != horizontalDoorLocationDown + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY + (70*roomSize));
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall right
        counter = 0;
        while(counter < roomSize+1)
        {
            if (counter != verticalDoorLocationRight && counter != verticalDoorLocationRight + 1)
            {
                wall1.rect.setPosition(roomStartX + 70*roomSize , 70*counter + roomStartY);
                wallArray.push_back(wall1);

            }
            counter++;

        }
        //Random Stuff in the room
        wall1.sprite.setTexture(textureBoulder);
        wall1.sprite.setTextureRect(sf::IntRect(0,0,72,72));
        counter = 0;
        while (counter < (roomSize - 1))
        {
            counter2 = 0;
            while (counter2 < (roomSize - 1))
            {
                tempRandom = generateRandom(RoomSpawnRate);
                if (tempRandom == 1)
                {
                    //Destructable boxes
                    wall1.destructable = true;
                    wall1.rect.setFillColor(sf::Color::Yellow);
                    wall1.rect.setPosition(counter*70 + 70 + roomStartX , counter2*70 + 70 + roomStartY );
                    wallArray.push_back(wall1);
                    //Setting the stuff back
                    wall1.destructable = false;
                    wall1.rect.setFillColor(sf::Color::Red);
                }
                if (tempRandom == 2)
                {
                    //Skeletons
                    enemy1.dimensionxStart = 32*0;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 100;
                    enemy1.maxhp = 100;
                    enemy1.attackDamage = 11;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 3)
                {
                    //Thugs
                    enemy1.dimensionxStart = 32*0;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 50;
                    enemy1.maxhp = 50;
                    enemy1.attackDamage = 5;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 4)
                {
                    //Assassins
                    enemy1.dimensionxStart = 32*3;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 110;
                    enemy1.maxhp = 110;
                    enemy1.attackDamage = 15;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 5)
                {
                    //Pink armour dudes
                    enemy1.dimensionxStart = 32*6;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 75;
                    enemy1.maxhp = 75;
                    enemy1.attackDamage = 12;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 6)
                {
                    //Rock armour dudes
                    enemy1.dimensionxStart = 32*9;
                    enemy1.dimensionyStart = 35*0;
                    enemy1.hp = 140;
                    enemy1.maxhp = 140;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 7)
                {
                    //Mohawk armour dudes
                    enemy1.dimensionxStart = 32*3;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 90;
                    enemy1.maxhp = 90;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 8)
                {
                    //Cyborg thug dudes
                    enemy1.dimensionxStart = 32*6;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 80;
                    enemy1.maxhp = 80;
                    enemy1.attackDamage = 10;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                if (tempRandom == 9)
                {
                    //Monster dudes
                    enemy1.dimensionxStart = 32*9;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 200;
                    enemy1.maxhp = 200;
                    enemy1.attackDamage = 20;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                counter2++;
            }
            counter++;
        }
        //Lay down your floor!
        counter = 0;
        while (counter <= roomSize+5)
        {
            counter2 = 0;
            while(counter2 <= roomSize+5)
            {
                ground1.sprite.setPosition(60*counter + roomStartX , 60*counter2 + roomStartY );
                groundArray.push_back(ground1);
                counter2++;
            }

            counter++;
        }


        //ROOM 6
        roomSize = 20;
        verticalDoorLocationRight = 100;
        verticalDoorLocationLeft = 3;
        horizontalDoorLocationUp = 100;
        horizontalDoorLocationDown = 100;
        roomStartX = 10*70 + 10*70 + 10*70 + 20*70;
        roomStartY = -1*10*70;
        wall1.destructable = false;
        wall1.sprite.setTexture(textureWall);
        //horizontal wall top
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationUp && counter != horizontalDoorLocationUp + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall left
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != verticalDoorLocationLeft && counter != verticalDoorLocationLeft + 1)
            {
                wall1.rect.setPosition(roomStartX , 70 * counter + roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
         }
        //horizontal bottom wall
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationDown && counter != horizontalDoorLocationDown + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY + (70*roomSize));
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall right
        counter = 0;
        while(counter < roomSize+1)
        {
            if (counter != verticalDoorLocationRight && counter != verticalDoorLocationRight + 1)
            {
                wall1.rect.setPosition(roomStartX + 70*roomSize , 70*counter + roomStartY);
                wallArray.push_back(wall1);

            }
            counter++;

        }
        //Random Stuff in the room
        wall1.sprite.setTexture(textureBoulder);
        wall1.sprite.setTextureRect(sf::IntRect(0,0,72,72));
        counter = 0;
        while (counter < (roomSize - 1))
        {
            counter2 = 0;
            while (counter2 < (roomSize - 1))
            {
                tempRandom = generateRandom(3);
                if (tempRandom == 1)
                {
                    //Destructable boxes
                    wall1.destructable = true;
                    wall1.rect.setFillColor(sf::Color::Yellow);
                    wall1.rect.setPosition(counter*70 + 70 + roomStartX , counter2*70 + 70 + roomStartY );
                    wallArray.push_back(wall1);
                    //Setting the stuff back
                    wall1.destructable = false;
                    wall1.rect.setFillColor(sf::Color::Red);
                }

                if (generateRandom(20) == 3)
                {
                    //Monster dudes
                    enemy1.dimensionxStart = 32*9;
                    enemy1.dimensionyStart = 35*4;
                    enemy1.hp = 200;
                    enemy1.maxhp = 200;
                    enemy1.attackDamage = 20;
                    enemy1.rect.setPosition((counter*70) + 70 + roomStartX , (counter2*70) + 70 +roomStartY);
                    enemyArray.push_back(enemy1);
                }
                counter2++;
            }
            counter++;
        }
        //Lay down your floor!
        counter = 0;
        while (counter <= roomSize+3)
        {
            counter2 = 0;
            while(counter2 <= roomSize+3)
            {
                ground1.sprite.setPosition(60*counter + roomStartX , 60*counter2 + roomStartY );
                groundArray.push_back(ground1);
                counter2++;
            }

            counter++;
        }



        //Room Item shop!
        roomSize = 10;
        verticalDoorLocationRight = 100;
        verticalDoorLocationLeft = 100;
        horizontalDoorLocationUp = 3;
        horizontalDoorLocationDown = 100;
        roomStartX = 0;
        roomStartY = 10 * 70;
        wall1.destructable = false;
        wall1.sprite.setTexture(textureWall);
        //horizontal wall
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationUp && counter != horizontalDoorLocationUp + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != verticalDoorLocationLeft && counter != verticalDoorLocationLeft + 1)
            {
                wall1.rect.setPosition(roomStartX , 70 * counter + roomStartY);
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //horizontal bottom wall
        counter = 0;
        while(counter < roomSize)
        {
            if (counter != horizontalDoorLocationDown && counter != horizontalDoorLocationDown + 1)
            {
                wall1.rect.setPosition(70 * counter + roomStartX , roomStartY + (70*roomSize));
                wallArray.push_back(wall1);
            }
            counter++;
        }
        //vertical wall right
        counter = 0;
        while(counter < roomSize + 1)
        {
            if (counter != verticalDoorLocationRight && counter != verticalDoorLocationRight + 1)
            {
                wall1.rect.setPosition(roomStartX + (70*roomSize) , (70*counter) + roomStartY);
                wallArray.push_back(wall1);

            }
            counter++;

        }
        //Lay down your floor!
        counter = 0;
        while (counter <= roomSize+1)
        {
            counter2 = 0;
            while(counter2 <= roomSize+1)
            {
                ground1.sprite.setPosition(60*counter + roomStartX, 60*counter2 + roomStartY);
                groundArray.push_back(ground1);
                counter2++;
            }

            counter++;
        }
        //Items
        //TRIPLE FIRE
        pickup1.cost = 20;
        pickup1.text.setString("TRIPLE FIRE\nCosts: 20 COINS\n(0 KILLS)");
        pickup1.isCoin = false;
        pickup1.isTripleFire = true;
        pickup1.isNovaAttack = false;
        pickup1.inShop = true;
        pickup1.sprite.setTexture(texturePowerup);
        pickup1.sprite.setTextureRect(sf::IntRect(0, 32*3, 32, 32));
        pickup1.rect.setPosition(200, 10*70+7*70);
        pickupArray.push_back(pickup1);

        //NOVA ATTACK
        pickup1.cost = 20;
        pickup1.text.setString("NOVA ATTACK\nCosts: 20 COINS\n(0 KILLS)");
        pickup1.isCoin = false;
        pickup1.isTripleFire = false;
        pickup1.isNovaAttack = true;
        pickup1.inShop = true;
        pickup1.sprite.setTexture(texturePowerup);
        pickup1.sprite.setTextureRect(sf::IntRect(32*5, 32*7, 32, 32));
        pickup1.rect.setPosition(500, 10*70+7*70);
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;

        //Super Nova Attack!
        pickup1.cost = 25;
        pickup1.text.setString("ERUPTION\nCosts: 25 COINS\n(100 KILLS)");
        pickup1.isCoin = false;
        pickup1.isTripleFire = false;
        pickup1.isNovaAttack = false;
        pickup1.issuperNovaAttack = true;
        pickup1.inShop = true;
        pickup1.sprite.setTexture(texturePowerup);
        pickup1.sprite.setTextureRect(sf::IntRect(32*7, 32*7, 32, 32));
        pickup1.rect.setPosition(500, 10*70+7*70+2*70);
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;

        //HP BUFF
        pickup1.cost = 25;
        pickup1.text.setString("HP BUFF\nCosts: 25 COINS\n(30 KILLS)");
        pickup1.isCoin = false;
        pickup1.isTripleFire = false;
        pickup1.isNovaAttack = false;
        pickup1.issuperNovaAttack = false;
        pickup1.isHPbuff = true;
        pickup1.inShop = true;
        pickup1.sprite.setTexture(texturePowerup);
        pickup1.sprite.setTextureRect(sf::IntRect(32*4, 32*7, 32, 32));
        pickup1.rect.setPosition(200, 10*70+7*70-2*70);
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;

        //DAMAGE BUFF
        pickup1.cost = 25;
        pickup1.text.setString("DAMAGE BUFF\nCosts: 25 COINS\n(50 KILLS)");
        pickup1.isCoin = false;
        pickup1.isTripleFire = false;
        pickup1.isNovaAttack = false;
        pickup1.issuperNovaAttack = false;
        pickup1.isHPbuff = false;
        pickup1.isDamageBuff = true;
        pickup1.inShop = true;
        pickup1.sprite.setTexture(texturePowerup);
        pickup1.sprite.setTextureRect(sf::IntRect(32*7, 32*6, 32, 32));
        pickup1.rect.setPosition(200, 10*70+7*70+2*70);
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;

        //MOVEMENT BUFF
        pickup1.cost = 25;
        pickup1.text.setString("MOVEMENT BUFF\nCosts: 25 COINS\n(50 KILLS)");
        pickup1.isCoin = false;
        pickup1.isTripleFire = false;
        pickup1.isNovaAttack = false;
        pickup1.issuperNovaAttack = false;
        pickup1.isHPbuff = false;
        pickup1.isDamageBuff = false;
        pickup1.isMovementBuff = true;
        pickup1.inShop = true;
        pickup1.sprite.setTexture(texturePowerup);
        pickup1.sprite.setTextureRect(sf::IntRect(32*5, 32*5, 32, 32));
        pickup1.rect.setPosition(500, 10*70+7*70-2*70);
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;


















    //*************************************************Game loop**************************************************************************************
    while(window.isOpen())
    {
        //making the close button work:
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
        }
        text.setPosition(player1.rect.getPosition().x - window.getSize().x/2 , player1.rect.getPosition().y - window.getSize().y/2);
        text2.setPosition(player1.rect.getPosition().x - window.getSize().x/2 + 200, player1.rect.getPosition().y - window.getSize().y/2);
        text3.setPosition(player1.rect.getPosition().x - window.getSize().x/2 + 400, player1.rect.getPosition().y - window.getSize().y/2);
        text4.setPosition(player1.rect.getPosition().x - window.getSize().x/2 + 600, player1.rect.getPosition().y - window.getSize().y/2);



        //update the player's position, as well as the rect's.
        player1.update();
        if(elapsed5.asSeconds() >= 0.1)
        {
            clock5.restart();
            player1.updateMovement();
        }
//        player1.updateMovement();


//         Spawn an enemy
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            enemy1.rect.setPosition(generateRandom(window.getSize().x) , generateRandom(window.getSize().y));
            enemyArray.push_back(enemy1);

        }


         //Fire if you press SPACE BAR
        if(elapsed1.asSeconds() >= 0.1)
        {
            clock.restart();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            soundShot.play();

        if (player1.tripleFire == true) //TRIPLE FIRE
        {
            if (player1.direction == 1) // UP
            {
                projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 25);
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 50 ,
                                          player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 );
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 50 ,
                                          player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 );
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);

            }
            if (player1.direction == 2) //DOWN
            {
                 projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 25);
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 50 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 50 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);
            }
            if (player1.direction == 3) //LEFT
            {
                 projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 25 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 50);
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 50);
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);
            }
            if (player1.direction == 4) //RIGHT
            {
                 projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 25 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 50);
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 50);
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);
            }

        }
        else if (player1.novaAttack == true)
        {
            projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = 1;
            projectileArray.push_back(projectile1);

            projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = 2;
            projectileArray.push_back(projectile1);

            projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = 3;
            projectileArray.push_back(projectile1);

            projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = 4;
            projectileArray.push_back(projectile1);
        }
        else if (player1.superNovaAttack == true)
        {
            //Triple fire in direction 1 (UP)
            projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 25);
            projectile1.direction = 1;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 50 ,
                                          player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 );
            projectile1.direction = 1;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 50 ,
                                          player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 );
            projectile1.direction = 1;
            projectileArray.push_back(projectile1);

            //Triple fire in direction 2 (DOWN)
            projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 25);
            projectile1.direction = 2;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 50 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = 2;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 50 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = 2;
            projectileArray.push_back(projectile1);

            //Triple Fire in direction 3 (LEFT)
            projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 25 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = 3;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 50);
            projectile1.direction = 3;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 50);
            projectile1.direction = 3;
            projectileArray.push_back(projectile1);

            //Triple Fire in direction 4 (RIGHT)
            projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 25 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = 4;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 50);
            projectile1.direction = 4;
            projectileArray.push_back(projectile1);

             projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 50);
            projectile1.direction = 4;
            projectileArray.push_back(projectile1);


        }
        else if(player1.tripleFire == false && player1.novaAttack == false && player1.superNovaAttack == false) //NORMAL ATTACK
        {
            projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
            projectile1.direction = player1.direction;
            projectileArray.push_back(projectile1);
        }
        }
        }






        //clearing the window before drawing everything
       window.clear();

       //Clock
       elapsed1 = clock.getElapsedTime();
       elapsed2 = clock2.getElapsedTime();
       elapsed3 = clock3.getElapsedTime();
       elapsed4 = clock4.getElapsedTime();
       elapsed5 = clock5.getElapsedTime();
       elapsed6 = clock6.getElapsedTime();
       elapsed7 = clock7.getElapsedTime();
       elapsed8 = clock8.getElapsedTime();

        //Draw Ground
        counter = 0;
        for(iter11 = groundArray.begin(); iter11 != groundArray.end(); iter11++)
        {
            window.draw(groundArray[counter].sprite);
            counter++;
        }


        //Draw Wall
        counter = 0;
        for(iter9 = wallArray.begin(); iter9 != wallArray.end(); iter9++)
        {
            //window.draw(wallArray[counter].rect);
            window.draw(wallArray[counter].sprite);
            wallArray[counter].update();
//            if (wallArray[counter].destructable == true)
//            {
//                if (elapsed8.asSeconds() >= 0.1)
//                {
//                    clock8.restart();
//                    wallArray[counter].updateMovement();
//                }
//            }
            counter++;
        }






        //Drawing our pick ups
        counter = 0;
        for(iter7 = pickupArray.begin(); iter7 != pickupArray.end(); iter7++)
        {
            pickupArray[counter].update();
            if(pickupArray[counter].inShop == true)
            {
                window.draw(pickupArray[counter].text);
            }


           if(elapsed3.asSeconds() >= 0.1)
         {
             clock3.restart();
             if(pickupArray[counter].isCoin == true)
             {
                 pickupArray[counter].updateMovement();
             }
             //pickupArray[counter].updateMovement();
         }

            window.draw(pickupArray[counter].sprite);
            counter++;
        }




        //Drawing Projectiles!
        counter=0;
        for(iter=projectileArray.begin(); iter!=projectileArray.end(); iter++)
        {
            projectileArray[counter].updatePosition();
            if(elapsed4.asSeconds() >= 0.1)
            {
                clock4.restart();
                projectileArray[counter].update();
            }

            //window.draw(projectileArray[counter].rect);
            window.draw(projectileArray[counter].sprite);
            counter++;
        }
        //Drawing enemies!
       counter=0;
        for(iter2=enemyArray.begin(); iter2!=enemyArray.end(); iter2++)
        {
            enemyArray[counter].update();
            enemyArray[counter].text.setString(text1.to_string(enemyArray[counter].hp) + "/" + text1.to_string(enemyArray[counter].maxhp));
            enemyArray[counter].text.setPosition(enemyArray[counter].rect.getPosition().x , enemyArray[counter].rect.getPosition().y - enemyArray[counter].rect.getSize().y);
            if (elapsed6.asSeconds() >= 0.1)
            {
                clock6.restart();
                enemyArray[counter].updateMovement();
            }
            //enemyArray[counter].updateMovement();
            //window.draw(enemyArray[counter].rect);
            window.draw(enemyArray[counter].sprite);
            window.draw(enemyArray[counter].text);
            counter++;
        }



        //Player Collision with WALL
        counter = 0;
        for (iter9 = wallArray.begin(); iter9 != wallArray.end(); iter9++)
        {
            if (player1.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()))
            {
                 if (player1.direction == 1) //UP
                {
                    player1.canMoveUp = false;
                    player1.rect.move(0,1);
                }
                 if (player1.direction == 2) //DOWN
                {
                    player1.canMoveDown = false;
                    player1.rect.move(0,-1);
                }
                 if (player1.direction == 3) //LEFT
                {
                    player1.canMoveLeft = false;
                    player1.rect.move(1,0);
                }
                 if (player1.direction == 4) //RIGHT
                {
                    player1.canMoveRight = false;
                    player1.rect.move(-1,0);
                }

            }
            counter++;
        }
//        counter = 0;
//        for (iter9 = wallArray.begin(); iter9 != wallArray.end(); iter9++)
//        {
//            if (player1.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()))
//            {
//                cout<<"Hi you touched a wall"<<endl;
//                player1.movementSpeed = 0;
//                cout<<"your movement speed should be zero now: "<<player1.movementSpeed<<endl;
//            }
//            else
//            {
//                player1.movementSpeed = 10;
//            }
//            counter++;
//        }

        //Enemy Collision with Wall
        counter = 0;
        for(iter2=enemyArray.begin(); iter2!=enemyArray.end(); iter2++)
        {
            counter2 = 0;
            for (iter9 = wallArray.begin(); iter9 != wallArray.end(); iter9++)
            {
                if (enemyArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
                {
                    if (enemyArray[counter].direction == 1) //UP
                    {
                        enemyArray[counter].canMoveUp = false;
                        enemyArray[counter].rect.move(0,1);
                    }
                    else if (enemyArray[counter].direction == 2) //DOWN
                    {
                        enemyArray[counter].canMoveDown = false;
                        enemyArray[counter].rect.move(0,-1);
                    }
                    else if (enemyArray[counter].direction == 3) //LEFT
                    {
                        enemyArray[counter].canMoveLeft = false;
                        enemyArray[counter].rect.move(1,0);
                    }
                    else if (enemyArray[counter].direction == 4) //RIGHT
                    {
                        enemyArray[counter].canMoveRight = false;
                        enemyArray[counter].rect.move(-1,0);
                    }
                }
                counter2++;
            }

          counter++;
        }

        //PROJECTILE COLLISION with WALL
        counter = 0;
        for(iter=projectileArray.begin(); iter!=projectileArray.end(); iter++)
        {
            counter2 = 0;
            for (iter9 = wallArray.begin(); iter9 != wallArray.end(); iter9++)
            {
                if (projectileArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
                {
                    projectileArray[counter].destroy = true;
                    if (wallArray[counter2].destructable == true)
                    {
                        wallArray[counter2].hp -= player1.attackDamage;
                        if (wallArray[counter2].hp <= 0)
                        {
                            wallArray[counter2].destroy = true;
                        }
                    }
                }
                counter2++;
            }
            counter++;
        }







        //Detecting Collision between PLAYER and ENEMY
        if (elapsed2.asSeconds() >= 0.5)
        {
            clock2.restart();
            counter = 0;
            for(iter2=enemyArray.begin(); iter2!=enemyArray.end(); iter2++)
            {
            if(player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
            {
                 soundPlayerhit.play();
                 player1.hp = player1.hp - enemyArray[counter].attackDamage;
                //Showing the text
                    text1.text.setString("-"+text1.to_string(enemyArray[counter].attackDamage));
                    text1.text.setPosition(player1.rect.getPosition().x - player1.rect.getSize().x/2 ,
                                           player1.rect.getPosition().y - player1.rect.getSize().y/2);
                    textDisplayArray.push_back(text1);
                cout<<"Your HP was..."<<player1.hp<<endl;
                //player1.hp = player1.hp - enemyArray[counter].attackDamage;
                player1.tripleFire = false;
                player1.novaAttack = false;
                cout<<"Now it is..."<<player1.hp<<endl;
            }
            counter++;
            }
        }

        //Detecting Collision between projectile and enemy
        counter = 0;
        for(iter=projectileArray.begin(); iter!=projectileArray.end(); iter++)
        {
            counter2 = 0;
            for(iter2=enemyArray.begin(); iter2!=enemyArray.end(); iter2++)
            {
                if(projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
                {
                    if (projectileArray[counter].enemyProjectile == false)
                    {
                    if (enemyArray[counter2].boss1 == false)
                    {
                        soundCollision.play();
                    }

                    //soundCollision.play();
                    cout<<"OMG YOU HIT SOMETHING"<<endl;
                    projectileArray[counter].destroy = true;
                    enemyArray[counter2].aggroed = true;
                    //Showing the text
                    text1.text.setString("-" + text1.to_string(player1.attackDamage));
                    text1.text.setPosition(enemyArray[counter2].rect.getPosition().x - enemyArray[counter2].rect.getSize().x/2 ,
                                           enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y/2);
                    textDisplayArray.push_back(text1);
                    enemyArray[counter2].hp = enemyArray[counter2].hp - player1.attackDamage;
                    if(enemyArray[counter2].hp <= 0)
                    {
                        enemyArray[counter2].alive = false;
                    }
                    }
                }
                counter2++;
            }
            counter++;
        }


        // Enemy Projectile Collides with Player
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            if (projectileArray[counter].enemyProjectile == true)
            {
                if (projectileArray[counter].rect.getGlobalBounds().intersects(player1.rect.getGlobalBounds()))
                {
                    player1.hp = player1.hp - enemyArray[counter].attackDamage;

                    // Text Display
                    text1.text.setString("-"+text1.to_string(enemyArray[counter].attackDamage));
                    text1.text.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2, player1.rect.getPosition().y - player1.rect.getSize().y/2);
                    textDisplayArray.push_back(text1);

                    projectileArray[counter].destroy = true;
                }
            }

            counter++;
        }





        //Detecting Collision between player and pick ups
        counter = 0;
        for(iter7 = pickupArray.begin(); iter7 != pickupArray.end(); iter7++)
        {
            if(pickupArray[counter].rect.getGlobalBounds().intersects(player1.rect.getGlobalBounds()))
            {
                    //soundCoin.play();

                    if(pickupArray[counter].inShop == true)
                    {
                       if (player1.coins >= pickupArray[counter].cost)
                       {
                           soundCoin.play();
                            if(pickupArray[counter].isTripleFire == true)
                            {
                                player1.tripleFire = true;
                                player1.novaAttack = false;
                                player1.superNovaAttack = false;
                                player1.coins -= pickupArray[counter].cost;
                                pickupArray[counter].destroy = true;
                            }
                            if(pickupArray[counter].isNovaAttack == true)
                            {
                                player1.tripleFire = false;
                                player1.novaAttack = true;
                                player1.superNovaAttack = false;
                                player1.coins -= pickupArray[counter].cost;
                                pickupArray[counter].destroy = true;
                            }
                            if(player1.kills>=100)
                            {
                                if(pickupArray[counter].issuperNovaAttack == true)
                                {
                                    player1.tripleFire = false;
                                    player1.novaAttack = false;
                                    player1.superNovaAttack = true;
                                    player1.coins -= pickupArray[counter].cost;
                                    pickupArray[counter].destroy = true;
                                }
                            }
                            if(player1.kills>=30)
                            {
                                if(pickupArray[counter].isHPbuff == true)
                                {
                                    player1.hp += pickupArray[counter].HPbuffValue;
                                    player1.coins -= pickupArray[counter].cost;
                                    pickupArray[counter].destroy = true;
                                }
                            }
                            if(player1.kills>=50)
                            {
                                if(pickupArray[counter].isDamageBuff == true)
                                {
                                    player1.attackDamage += pickupArray[counter].DamageBuffValue;
                                    player1.coins -= pickupArray[counter].cost;
                                    pickupArray[counter].destroy = true;
                                }
                            }
                            if(player1.kills>=50)
                            {
                                if(pickupArray[counter].isMovementBuff == true)
                                {
                                    player1.movementSpeed += pickupArray[counter].MovementBuffValue;
                                    player1.coins -= pickupArray[counter].cost;
                                    pickupArray[counter].destroy = true;
                                }
                            }
                       }

                    }

                    if(pickupArray[counter].inShop == false)
                    {
                        soundCoin.play();
                        if(pickupArray[counter].isCoin == true)
                        {
                            player1.coins += pickupArray[counter].coinValue;
                        }
                        if(pickupArray[counter].isTripleFire == true)
                        {
                            player1.tripleFire = true;
                            player1.novaAttack = false;
                        }
                        if(pickupArray[counter].isNovaAttack == true)
                        {
                            player1.tripleFire = false;
                            player1.novaAttack = true;
                        }
                        pickupArray[counter].destroy = true;
                }
            }
            counter++;
        }

        //Enemy Aggro AI
        counter = 0;
        for (iter2 = enemyArray.begin(); iter2 != enemyArray.end(); iter2++)
        {
            if (enemyArray[counter].aggroed == true)
            {
                if (elapsed7.asSeconds() >= 1)
                {
                    clock7.restart();
                    int tempRand = generateRandom(3);
                    if (tempRand == 1) //Enemy fires projectile and chases the player
                    {
                        if (enemyArray[counter].boss1 == true)
                        {
                                            //Triple fire in direction 1 (UP)
                             soundGroudon.play();
                             projectile1.enemyProjectile = true;
                             projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 25);
                            projectile1.direction = 1;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 50 ,
                                          enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 );
                            projectile1.direction = 1;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 50 ,
                                          enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 );
                            projectile1.direction = 1;
                            projectileArray.push_back(projectile1);

                            //Triple fire in direction 2 (DOWN)
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 25);
                            projectile1.direction = 2;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 + 50 , enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 -
                            projectile1.rect.getSize().y/2);
                            projectile1.direction = 2;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 - 50 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectile1.direction = 2;
                            projectileArray.push_back(projectile1);

                            //Triple Fire in direction 3 (LEFT)
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 - 25 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectile1.direction = 3;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 50);
                            projectile1.direction = 3;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2, enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 50);
                            projectile1.direction = 3;
                            projectileArray.push_back(projectile1);

                            //Triple Fire in direction 4 (RIGHT)
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 + 25 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectile1.direction = 4;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 50);
                            projectile1.direction = 4;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 50);
                            projectile1.direction = 4;
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;
                        }
                        else if (enemyArray[counter].boss2 == true)
                        {
                            // Player to Right
                         if ((player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
                        {
                             soundShot.play();
                             projectile1.enemyProjectile = true;
                             projectile1.direction = 3;
                              projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 - 25 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectile1.direction = 3;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 50);
                            projectile1.direction = 3;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2, enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 50);
                            projectile1.direction = 3;
                            projectileArray.push_back(projectile1);
                             projectile1.enemyProjectile = false;

                             enemyArray[counter].direction = 3;
                        }



                        // Player to Left
                        if ((player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x) && (abs(player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                             projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 + 25 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectile1.direction = 4;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 50);
                            projectile1.direction = 4;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 50);
                            projectile1.direction = 4;
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;

                            enemyArray[counter].direction = 4;
                        }


                        // Player to Top
                        if ((player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y) && (abs(player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2 ,
                                         enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 25);
                            projectile1.direction = 1;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 50 ,
                                          enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 );
                            projectile1.direction = 1;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 50 ,
                                          enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 );
                            projectile1.direction = 1;
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;

                            enemyArray[counter].direction = 1;
                        }

                        // Player to Bottom
                        if ((player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y) && (abs(player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 25);
                            projectile1.direction = 2;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 + 50 , enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 -
                            projectile1.rect.getSize().y/2);
                            projectile1.direction = 2;
                            projectileArray.push_back(projectile1);

                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -
                            projectile1.rect.getSize().x/2 - 50 , enemyArray[counter].rect.getPosition().y +
                            enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectile1.direction = 2;
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;

                            enemyArray[counter].direction = 2;
                        }
                        }




                         if (enemyArray[counter].boss1 == false && enemyArray[counter].boss2 == false)
                        {
                        // Player to Right
                         if ((player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
                        {
                             soundShot.play();
                             projectile1.enemyProjectile = true;
                             projectile1.direction = 3;
                             projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                             projectileArray.push_back(projectile1);
                             projectile1.enemyProjectile = false;

                             enemyArray[counter].direction = 3;
                        }

                        // Player to Left
                        if ((player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x) && (abs(player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                            projectile1.direction = 4;
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;

                            enemyArray[counter].direction = 4;
                        }

                        // Player to Top
                        if ((player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y) && (abs(player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                            projectile1.direction = 1;
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;

                            enemyArray[counter].direction = 1;
                        }

                        // Player to Bottom
                        if ((player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y) && (abs(player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                            projectile1.direction = 2;
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;

                            enemyArray[counter].direction = 2;
                        }
                        }
                    }
                      else   if (tempRand == 2) // Enemy Chases Player
                    {
                        if (player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 1;
                        }
                        else if (player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 2;
                        }
                        else if (player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 3;
                        }
                        else if (player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 4;
                        }
                    }
                    else // Enemy Chases Player
                    {
                        if (player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 3;
                        }
                        else if (player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 4;
                        }
                        else if (player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 1;
                        }
                        else if (player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 2;
                        }
                    }

                    }

                }
                counter++;

            }












        //Delete the dead enemy!
        counter = 0;
        for(iter3=enemyArray.begin(); iter3!=enemyArray.end(); iter3++)
        {
            if(enemyArray[counter].alive == false)
            {
                cout<<"ENEMY HAS BEEN OBLITERATED TO SMITHERENES"<<endl;
                player1.kills += 1;

                if (enemyArray[counter].boss1 == false && enemyArray[counter].boss2 == false)
                {
                    //Drop coin
                if (generateRandom(4) == 1)
                {
                    pickup1.isCoin = true;
                    pickup1.isTripleFire = false;
                    pickup1.isNovaAttack = false;
                    pickup1.sprite.setTexture(textureCoin);
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                //Drop power up triple fire
                if (generateRandom(8) == 1)
                {
                    pickup1.isCoin = false;
                    pickup1.isTripleFire = true;
                    pickup1.isNovaAttack = false;
                    pickup1.sprite.setTexture(texturePowerup);
                    pickup1.sprite.setTextureRect(sf::IntRect(0, 32*3, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                //Drop power up Nova Attack!
                if (generateRandom(30) == 1)
                {
                    pickup1.isCoin = false;
                    pickup1.isTripleFire = false;
                    pickup1.isNovaAttack = true;
                    pickup1.sprite.setTexture(texturePowerup);
                    pickup1.sprite.setTextureRect(sf::IntRect(32*5, 32*7, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                }
                else
                {
                    pickup1.isCoin = true;
                    pickup1.sprite.setTexture(textureCoin);
                    pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                    //pickup1.sprite.setScale(1, 1);

                    counter3 = 0;
                    while (counter3 <= 10)
                    {
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x - generateRandom(30),enemyArray[counter].rect.getPosition().y - generateRandom(30));
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x + generateRandom(30),enemyArray[counter].rect.getPosition().y + generateRandom(30));
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x - generateRandom(30),enemyArray[counter].rect.getPosition().y + generateRandom(30));
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x + generateRandom(30),enemyArray[counter].rect.getPosition().y - generateRandom(30));
                        pickupArray.push_back(pickup1);

                        counter3++;
                    }
                }


                enemyArray.erase(iter3);
                break;
            }
            counter++;
        }
        //Deleting your hit projectile
        counter = 0;
        for(iter4=projectileArray.begin(); iter4 != projectileArray.end(); iter4++)
        {
            if(projectileArray[counter].destroy == true)
            {
                cout<<"projectile was erased lol"<<endl;
                projectileArray.erase(iter4);
                break;
            }
            counter++;
        }
        //Deleting the text after it displays
        counter = 0;
        for(iter6=textDisplayArray.begin(); iter6 != textDisplayArray.end(); iter6++)
        {
            if (textDisplayArray[counter].destroy == true)
            {
                cout<<"Text was erased lol"<<endl;
                textDisplayArray.erase(iter6);
                break;
            }
            counter++;
        }
        //Deleting pick ups
        counter = 0;
        for(iter8=pickupArray.begin(); iter8 != pickupArray.end(); iter8++)
        {
            if (pickupArray[counter].destroy == true)
            {
                cout<<"Pickup was erased, lol"<<endl;
                pickupArray.erase(iter8);
                break;
            }
            counter++;
        }
        //Deleting walls
        counter = 0;
        for (iter10 = wallArray.begin(); iter10 != wallArray.end(); iter10++)
        {
            if (wallArray[counter].destroy == true)
            {
                cout<<"You just destroyed a box, dude."<<endl;
                //Drop coin
                if (generateRandom(4) == 1)
                {
                    pickup1.isCoin = true;
                    pickup1.isTripleFire = false;
                    pickup1.isNovaAttack = false;
                    pickup1.sprite.setTexture(textureCoin);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                //Drop power up triple fire
                if (generateRandom(8) == 1)
                {
                    pickup1.isCoin = false;
                    pickup1.isTripleFire = true;
                    pickup1.isNovaAttack = false;
                    pickup1.sprite.setTexture(texturePowerup);
                    pickup1.sprite.setTextureRect(sf::IntRect(0, 32*3, 32, 32));
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                //Drop power up Nova Attack!
                if (generateRandom(30) == 1)
                {
                    pickup1.isCoin = false;
                    pickup1.isTripleFire = false;
                    pickup1.isNovaAttack = true;
                    pickup1.sprite.setTexture(texturePowerup);
                    pickup1.sprite.setTextureRect(sf::IntRect(32*5, 32*7, 32, 32));
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }

                wallArray.erase(iter10);
                break;
            }
            counter++;
        }





       //Drawing the Player
       window.draw(player1.sprite);
       //Adjusting our view
       window.setView(view1);
       view1.setCenter(player1.rect.getPosition());

       //Drawing the damage text
       counter = 0;
       for(iter5 = textDisplayArray.begin(); iter5 != textDisplayArray.end(); iter5++)
       {
           textDisplayArray[counter].update();
           window.draw(textDisplayArray[counter].text);
           counter++;
       }

       //Display Coins text
       text.setString("Coins: " + text1.to_string(player1.coins));
//       text.setPosition(player1.rect.getPosition().x - window.getSize().x/2 , player1.rect.getPosition().y - window.getSize().y/2);
       window.draw(text);
       //Display HP text
       text2.setString("HP: " + text1.to_string(player1.hp));
       window.draw(text2);
       //Display Kills text
       text3.setString("KILLS: " + text1.to_string(player1.kills));
       window.draw(text3);
       //Display AttackDamage
       text4.setString("Damage: " + text1.to_string(player1.attackDamage));
       window.draw(text4);






       window.display();


    }


}
