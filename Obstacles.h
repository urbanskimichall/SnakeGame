#ifndef SNAKE_OBSTACLES_H
#define SNAKE_OBSTACLES_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Obstacles
{
public:


    void loadTexturesOfObstacles();

    void setPositionOfObstacles();

    sf::Sprite getFenceSprite();

    sf::Sprite getStoneSprite();

    float xCordOfFence{300};
    float yCordOfFence{300};
    float xCordOfStone{500};
    float yCordOfStone{150};
private:
    sf::Texture textureOfFence;
    sf::Texture textureOfStone;

    sf::Sprite fence;
    sf::Sprite stone;

};


#endif //SNAKE_OBSTACLES_H
