#include "Banana.h"

void Banana::loadTexture()
{
    textureOfBanana.loadFromFile("../Pictures/banana.png");
    banana.setTexture(textureOfBanana);
}

void Banana::generateNewPosition(int wH, int wW , Obstacles &obstacles)
{
    xOfBanana = (rand() % wW);
    yOfBanana = (rand() % wH);

    if ((xOfBanana >= obstacles.xCordOfFence - 20 && xOfBanana <= obstacles.xCordOfFence + 140 &&
        yOfBanana >= obstacles.yCordOfFence - 20 && yOfBanana <= obstacles.yCordOfFence + 60) ||
        (xOfBanana >= obstacles.xCordOfStone - 20 && xOfBanana <= obstacles.xCordOfStone + 50 &&
        yOfBanana >= obstacles.yCordOfStone - 20 && yOfBanana <= obstacles.yCordOfStone + 50))
    {
        generateNewPosition(wH, wW, obstacles);
    }

    if (xOfBanana < 20)
    {
        xOfBanana = xOfBanana + 20;
    }
    if (yOfBanana < 20)
    {
        yOfBanana = yOfBanana + 20;

    }
    if (xOfBanana > wW - 20)
    {
        xOfBanana = xOfBanana - 20;
    }
    if (yOfBanana > wH - 20)
    {
        yOfBanana = yOfBanana - 20;
    }
}

void Banana::updatePositionOfFood()
{
    banana.setPosition(xOfBanana, yOfBanana);
}

float Banana::getXfoodPosition()
{
    return xOfBanana;
}
float Banana::getYfoodPosition()
{
    return yOfBanana;
}

sf::Sprite Banana::getSprite()
{
    return banana;
}

int Banana::scoreOfFood()
{
    return scoreOfBanana;
}
