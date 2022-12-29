#include <iostream>
#include <SFML/Window/Event.hpp>
#include <sstream>
#include "GameOver.h"

bool GameOver::isGameOver(std::vector<float> xC, std::vector<float> yC)
{
    for (int i = 1; i < xC.size(); i++)
    {
        if (xC[0] == xC[i] && yC[0] == yC[i])
        {
            std::cout << "Game Over!";
            return true;
        }
    }
    return false;
}

void GameOver::displayGameOver(sf::RenderWindow &window, int score)
{
    fontOfGameOver.loadFromFile("../Fonts/Raleway-Black.ttf");
    textOfGameOver.setFont(fontOfGameOver);
    textOfGameOver.setCharacterSize(32);
    textOfGameOver.setString("GAME OVER!");
    textOfGameOver.setPosition(200, 150);
    textOfGameOver.setColor(colorOfGameOver);

    displayFinalScore(score);

    window.draw(textOfGameOver);
    window.draw(textOfFianlScore);
}

void GameOver::buttonSet(sf::RenderWindow &window)
{
    buttonToRestartGame.setSize(sf::Vector2f(200, 100));
    buttonToRestartGame.setFillColor(sf::Color::Blue);
    buttonToRestartGame.setOutlineColor(sf::Color::Red);
    buttonToRestartGame.setOutlineThickness(5);
    buttonToRestartGame.setPosition(200, 250);

    setTextPlayAgain();
    window.draw(buttonToRestartGame);
    window.draw(textOfPlayAgain);
}

void GameOver::setTextPlayAgain()
{
    fontOfGameOver.loadFromFile("../Fonts/Raleway-Black.ttf");
    textOfPlayAgain.setFont(fontOfGameOver);
    textOfPlayAgain.setCharacterSize(32);
    textOfPlayAgain.setString("Play Again");
    textOfPlayAgain.setPosition(215, 280);
    textOfPlayAgain.setColor(sf::Color::Green);
}

void GameOver::waitForClick(sf::RenderWindow &window, sf::Event &event)
{
    bool isMousePressed{false};
    while (1)
    {
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.x > 200 &&
                 event.mouseButton.x < 400 && event.mouseButton.y > 250 && event.mouseButton.y < 350) ||
                (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
            {
                isMousePressed = true;
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (isMousePressed)
        {
            std::cout << "klikk";
            break;
        }
    }
}

void GameOver::displayFinalScore(int score) {
    std::stringstream ss;
    ss << score;
    std::string strScore = ss.str();

    textOfFianlScore.setFont(fontOfGameOver);
    textOfFianlScore.setCharacterSize(25);
    textOfFianlScore.setString("Your score: " + strScore);
    textOfFianlScore.setPosition(215, 200);
    textOfFianlScore.setColor(sf::Color::Green);
}

bool GameOver::checkColisionWithEnemy(std::vector<Enemy *> &enemies, float xDirect, float yDirect)
{
    for (int i = 0; i < enemies.size(); ++i)
    {
        if (xDirect >= enemies[i]->getXCordOfEnemy() - 10 && xDirect <= enemies[i]->getXCordOfEnemy() + 10 &&
            yDirect >= enemies[i]->getYCordOfEnemy() - 10 && yDirect <= enemies[i]->getYCordOfEnemy() + 10)
        {
            return true;
        }
    }
    return false;
}

bool GameOver::checkColisionWithObstacle(Obstacles &obstacles, float xDirect, float yDirect)
{
    if ((xDirect >= obstacles.xCordOfStone && xDirect <= obstacles.xCordOfStone + 30 &&
         yDirect >= obstacles.yCordOfStone && yDirect <= obstacles.yCordOfStone + 30) ||
        (xDirect >= obstacles.xCordOfFence && xDirect <= obstacles.xCordOfFence + 120 &&
         yDirect >= obstacles.yCordOfFence && yDirect <= obstacles.yCordOfFence + 40))
    {
        return true;
    }
    return false;
}
