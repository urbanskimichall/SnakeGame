#ifndef SNAKE_ORANGE_H
#define SNAKE_ORANGE_H

#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Food.h"

class Orange : public Food
{
public:
    Orange()
    {
        srand(time(NULL));
    }

    float xOfOrange{100};
    float yOfOrange{100};
    sf::Sprite orange;


    void loadTexture() override;

    void generateNewPosition(int wH, int wW , Obstacles &obstacles) override;

    void updatePositionOfFood() override;

    float getXfoodPosition() override;

    float getYfoodPosition() override;

    sf::Sprite getSprite() override;

    int scoreOfFood() override;

private:
    sf::Texture textureOfOrange;

    int scoreOfOrange{2};
};
#endif //SNAKE_ORANGE_H
