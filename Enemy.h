

#ifndef SNAKE_ENEMY_H
#define SNAKE_ENEMY_H


#include <SFML/Graphics/RenderWindow.hpp>

class Enemy
{
public:

    virtual void updatePositionOfEnemy(sf::RenderWindow &window, int width, int height) = 0;

    virtual float getXCordOfEnemy() = 0;

    virtual float getYCordOfEnemy() = 0;
};
#endif //SNAKE_ENEMY_H
