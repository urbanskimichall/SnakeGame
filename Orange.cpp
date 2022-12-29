#include "Orange.h"

void Orange::loadTexture()
{
    textureOfOrange.loadFromFile("../Pictures/orange.png");
    orange.setTexture(textureOfOrange);
}

void Orange::generateNewPosition(int wH, int wW, Obstacles &obstacles)
{
    xOfOrange = (rand() % wW);
    yOfOrange = (rand() % wH);

    if ((xOfOrange >= obstacles.xCordOfFence - 20 && xOfOrange <= obstacles.xCordOfFence + 140 &&
         yOfOrange >= obstacles.yCordOfFence - 20 && yOfOrange <= obstacles.yCordOfFence + 60) ||
        (xOfOrange >= obstacles.xCordOfStone - 20 && xOfOrange <= obstacles.xCordOfStone + 50 &&
         yOfOrange >= obstacles.yCordOfStone - 20 && yOfOrange <= obstacles.yCordOfStone + 50))
    {
        generateNewPosition(wH, wW, obstacles);
    }

    if (xOfOrange < 20)
    {
        xOfOrange = xOfOrange + 20;
    }
    if (yOfOrange < 20)
    {
        yOfOrange = yOfOrange + 20;

    }
    if (xOfOrange > wW - 20)
    {
        xOfOrange = xOfOrange - 20;
    }
    if (yOfOrange > wH - 20)
    {
        yOfOrange = yOfOrange - 20;
    }
}

void Orange::updatePositionOfFood()
{
    orange.setPosition(xOfOrange, yOfOrange);
}

float Orange::getXfoodPosition()
{
    return xOfOrange;
}

float Orange::getYfoodPosition()
{
    return yOfOrange;
}

sf::Sprite Orange::getSprite()
{
    return orange;
}

int Orange::scoreOfFood()
{
    return scoreOfOrange;
}
