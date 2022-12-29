#ifndef SNAKE_GAMEOVER_H
#define SNAKE_GAMEOVER_H

#include <vector>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Spider.h"
#include "Obstacles.h"

class GameOver
{
public:
    bool isGameOver(std::vector<float> xC, std::vector<float> yC);

    void displayGameOver(sf::RenderWindow &window, int score);

    void buttonSet(sf::RenderWindow &window);

    void waitForClick(sf::RenderWindow &window,  sf::Event &event);

    bool checkColisionWithEnemy (std::vector<Enemy *> &enemies, float xDirect, float yDirect);

    bool checkColisionWithObstacle(Obstacles &obstacles, float xDirect, float yDirect);

private:
    void setTextPlayAgain();

    void displayFinalScore(int score);

    sf::Font fontOfGameOver;
    sf::Text textOfGameOver;
    sf::Text textOfPlayAgain;
    sf::Text textOfFianlScore;
    sf::Color colorOfGameOver{255, 0, 0};
    sf::RectangleShape buttonToRestartGame;
};
#endif //SNAKE_GAMEOVER_H
