#include <SFML/Graphics/RenderWindow.hpp>
#include "Spider.h"
#include <iostream>

Spider::Spider(float xCor, float yCor)
{
    xCordOfSpider = xCor;
    yCordOfSpider = yCor;

    srand(time(NULL));
    textureOfSpider.loadFromFile("../Pictures/spider.png");
    spider.setTexture(textureOfSpider);
    directionOfSpider = Direction::DOWN;
}

void Spider::updatePositionOfEnemy(sf::RenderWindow &window, int width, int height)
{
    spider.setPosition(xCordOfSpider, yCordOfSpider);
    window.draw(spider);
    updateDirectionOfSpider();
    if (counterOfSteps == steps)
    {

        generateNewDirection();
        generateNumbOfSteps();
        counterOfSteps = 0;
    }
    counterOfSteps++;

    if (xCordOfSpider < 20)
    {
        directionOfSpider = Direction::RIGHT;
        counterOfSteps = 0;
        steps = 10;
    }
    if (xCordOfSpider > width - 20)
    {
        directionOfSpider = Direction::LEFT;
        counterOfSteps = 0;
        steps = 10;
    }
    if (yCordOfSpider < 20)
    {
        directionOfSpider = Direction::DOWN;
        counterOfSteps = 0;
        steps = 10;
    }
    if (yCordOfSpider > height - 20)
    {
        directionOfSpider = Direction::UP;
        counterOfSteps = 0;
        steps = 10;
    }
}

void Spider::updateDirectionOfSpider()
{
    switch (directionOfSpider)
    {
        case Direction::LEFT:
            spider.setRotation(270);
            xCordOfSpider -= 10;
            break;
        case Direction::RIGHT:
            spider.setRotation(90);
            xCordOfSpider += 10;
            break;
        case Direction::UP:
            spider.setRotation(0);
            yCordOfSpider -= 10;
            break;
        case Direction::DOWN:
            spider.setRotation(180);
            yCordOfSpider += 10;
            break;
        default:
            break;
    }
}

void Spider::generateNewDirection()
{
    int newDirection = rand() % 4;
    std::cout << "____________" << newDirection << std::endl;
    switch (newDirection)
    {
        case 0:
            directionOfSpider = Direction::DOWN;
            break;
        case 1:
            directionOfSpider = Direction::UP;
            break;
        case 2:
            directionOfSpider = Direction::LEFT;
            break;
        case 3:
            directionOfSpider = Direction::RIGHT;
            break;
        default:
            break;
    }
}

void Spider::generateNumbOfSteps()
{
    steps = rand() % 10 + 10;
}

float Spider::getXCordOfEnemy()
{
    return xCordOfSpider;
}

float Spider::getYCordOfEnemy()
{
    return yCordOfSpider;
}
