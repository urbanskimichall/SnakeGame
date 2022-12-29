#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H


#include <SFML/Graphics/Sprite.hpp>
#include "Obstacles.h"

class Food
{
public:

    virtual void loadTexture() = 0;

    virtual void generateNewPosition(int wH, int wW , Obstacles &obstacles) = 0;

    virtual void updatePositionOfFood() = 0;

    virtual float getXfoodPosition() = 0;

    virtual float getYfoodPosition() = 0;

    virtual sf::Sprite getSprite() = 0;

    virtual int scoreOfFood()=0;
};
#endif //SNAKE_FOOD_H
