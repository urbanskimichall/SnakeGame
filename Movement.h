#ifndef SNAKE_MOVEMENT_H
#define SNAKE_MOVEMENT_H

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "GameOver.h"

class Movement
{
public:
    explicit Movement();

    float xDirect{400};
    float yDirect{400};
    float speedOfSnake{10};
    int score{0};
    int level{1};

    enum class Direction : int
    {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };


    Direction directionOfHead{Direction::LEFT};

    bool checkIfFoodEaten(float xApple, float yApple, int scoreUp);

    void updatePositionOfSnake(float windowWidth, float windowHeight);

    void displayPoints();

    void buttonOfGameOverDisplay(sf::RenderWindow &window, sf::Event &event, std::vector<Enemy *> &enemies,
                                 Obstacles &obstacles);

    void resetSnake();

    bool updateLevel(int scoreToLevelUp);

    std::vector<float> xCordsOfSnake{
            xDirect, xDirect + 20, xDirect + 40, xDirect + 60
    };
    std::vector<float> yCordsOfSnake{
            yDirect, yDirect, yDirect, yDirect
    };
    std::vector<sf::Sprite> bodyTexture;
    sf::Texture textureOfBody;
    sf::Sprite body;
    sf::Texture textureOfHead;
    sf::Sprite head;

    sf::Font fontOfGameOver;
    sf::Text textOfPoints;
    sf::Color colorOfPoints{0, 255, 10};

    GameOver gameOver;

    void updateMovementDirection();

    void checkPressedKey(sf::Event event);

private:
    void snakeOutsideSnakeIn(float windowWidth, float windowHeight);

    void setRotationHead();
};
#endif //SNAKE_MOVEMENT_H
