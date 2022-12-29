#include "Apple.h"
#include "Obstacles.h"

void Apple::generateNewPosition(int wH, int wW, Obstacles &obstacles)
{
    xOfApple = (rand() % wW);
    yOfApple = (rand() % wH);
    if ((xOfApple >= obstacles.xCordOfFence - 20 && xOfApple <= obstacles.xCordOfFence + 140 &&
        yOfApple >= obstacles.yCordOfFence - 20 && yOfApple <= obstacles.yCordOfFence + 60) ||
        (xOfApple >= obstacles.xCordOfStone - 20 && xOfApple <= obstacles.xCordOfStone + 50 &&
        yOfApple >= obstacles.yCordOfStone - 20 && yOfApple <= obstacles.yCordOfStone + 50))
    {
        generateNewPosition(wH, wW, obstacles);
    }

    if (xOfApple < 20)
    {
        xOfApple = xOfApple + 20;
    }
    if (yOfApple < 20)
    {
        yOfApple = yOfApple + 20;
    }
    if (xOfApple > wW - 20)
    {
        xOfApple = xOfApple - 20;
    }
    if (yOfApple > wH - 20)
    {
        yOfApple = yOfApple - 20;
    }
}

void Apple::updatePositionOfFood()
{
    apple.setPosition(xOfApple, yOfApple);
}

void Apple::loadTexture()
{
    textureOfApple.loadFromFile("../Pictures/apple.png");
    apple.setTexture(textureOfApple);
}

float Apple::getXfoodPosition()
{
    return xOfApple;
}

float Apple::getYfoodPosition()
{
    return yOfApple;
}

sf::Sprite Apple::getSprite()
{
    return apple;
}

int Apple::scoreOfFood()
{
    return scoreOfApple;
}
