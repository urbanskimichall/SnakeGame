#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H

#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Food.h"
#include "Obstacles.h"

class Apple : public Food
{
public:
    float xOfApple{200};
    float yOfApple{200};
    sf::Sprite apple;

    Apple()
    {
        srand(time(NULL));
    }

    void generateNewPosition(int wH, int wW , Obstacles &obstacles) override;
    void updatePositionOfFood() override;
    void loadTexture() override;
    float getXfoodPosition() override;
    float getYfoodPosition() override;
    sf::Sprite getSprite() override;
    int scoreOfFood() override ;

private:
    sf::Texture textureOfApple;
    int scoreOfApple{1};
};
#endif //SNAKE_APPLE_H
