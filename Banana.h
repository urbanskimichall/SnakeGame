#ifndef SNAKE_BANANA_H
#define SNAKE_BANANA_H

#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Food.h"

class Banana : public Food
{
public:
    Banana()
    {
        srand(time(NULL));
    }

    float xOfBanana{400};
    float yOfBanana{100};
    sf::Sprite banana;


    void loadTexture() override;

    void generateNewPosition(int wH, int wW , Obstacles &obstacles) override;

    void updatePositionOfFood() override;

    float getXfoodPosition() override;

    float getYfoodPosition() override;

    sf::Sprite getSprite() override;

    int scoreOfFood() override;

private:
    sf::Texture textureOfBanana;

    int scoreOfBanana{3};
};
#endif //SNAKE_BANANA_H
