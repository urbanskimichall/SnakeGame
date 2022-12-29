
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <thread>
#include <sstream>
#include "Movement.h"
#include "GameOver.h"
#include <SFML/Graphics.hpp>

Movement::Movement()
{

    textureOfBody.loadFromFile("../Pictures/partOfSnake.png");
    textureOfHead.loadFromFile("../Pictures/head.png");

    body.setTexture(textureOfBody);

    head.setTexture(textureOfHead);

    for (int i = 0; i < 3; ++i)
    {
        if (i == 0)
        {
            bodyTexture.push_back(head);
        }
        else
            bodyTexture.push_back(body);
    }

}

bool Movement::checkIfFoodEaten(float xApple, float yApple, int scoreUp)
{
    if (xApple > xDirect - 20 && xApple < xDirect + 20 && yApple > yDirect - 20 && yApple < yDirect + 20)
    {
        bodyTexture.push_back(body);
        float lastXcord{xCordsOfSnake.back() + 20};
        float lastYcord{yCordsOfSnake.back() + 20};
        xCordsOfSnake.push_back(lastXcord);
        yCordsOfSnake.push_back(lastYcord);

        score = score + scoreUp;
        std::cout << "Punkty: " << score << std::endl;
        return true;
    }
    return false;
}

void Movement::updatePositionOfSnake(float windowWidth, float windowHeight)
{
    snakeOutsideSnakeIn(windowWidth, windowHeight);


    xCordsOfSnake.insert(xCordsOfSnake.begin(), xDirect);
    yCordsOfSnake.insert(yCordsOfSnake.begin(), yDirect);
    xCordsOfSnake.pop_back();
    yCordsOfSnake.pop_back();

    displayPoints();


    for (int i = 0; i < xCordsOfSnake.size() - 1; i++)
    {
        bodyTexture[i].setPosition(xCordsOfSnake[i], yCordsOfSnake[i]);
        //std::cout << i << " xCord " << xCordsOfSnake[i] << " ycord " << yCordsOfSnake[i] << std::endl;
    }
    setRotationHead();
}

void Movement::snakeOutsideSnakeIn(float windowWidth, float windowHeight)
{
    if (xDirect > windowWidth)
    {
        xDirect = 0;
    }
    if (xDirect < 0)
    {
        xDirect = windowWidth;
    }
    if (yDirect > windowHeight)
    {
        yDirect = 0;
    }
    if (yDirect < 0)
    {
        yDirect = windowHeight;
    }
}

void Movement::setRotationHead()
{
    switch (directionOfHead)
    {
        case Direction::LEFT:
            bodyTexture[0].setRotation(270);
            bodyTexture[0].setPosition(xDirect, yDirect + 20);
            break;
        case Direction::RIGHT:
            bodyTexture[0].setRotation(90);
            bodyTexture[0].setPosition(xDirect + 20, yDirect);
            break;
        case Direction::UP:
            bodyTexture[0].setRotation(0);

            break;
        case Direction::DOWN:
            bodyTexture[0].setRotation(180);
            bodyTexture[0].setPosition(xDirect + 20, yDirect + 20);
            break;
    }
}

void Movement::displayPoints()
{
    std::stringstream ss;
    ss << score;
    std::string strScore = ss.str();

    fontOfGameOver.loadFromFile("../Fonts/Raleway-Black.ttf");
    textOfPoints.setFont(fontOfGameOver);
    textOfPoints.setCharacterSize(20);
    textOfPoints.setString("Score: " + strScore);
    textOfPoints.setPosition(470, 10);
    textOfPoints.setColor(colorOfPoints);
}

void Movement::buttonOfGameOverDisplay(sf::RenderWindow &window, sf::Event &event, std::vector<Enemy *> &enemies,
                                       Obstacles &obstacles)
{
    if (gameOver.isGameOver(xCordsOfSnake, yCordsOfSnake) ||
        gameOver.checkColisionWithEnemy(enemies, xDirect, yDirect) ||
        gameOver.checkColisionWithObstacle(obstacles, xDirect, yDirect))
    {
        gameOver.buttonSet(window);

        gameOver.displayGameOver(window, score);

        window.display();

        gameOver.waitForClick(window, event);

        resetSnake();
    }
}

void Movement::resetSnake()
{
    xDirect = 400;
    yDirect = 400;
    score = 0;
    xCordsOfSnake.clear();
    yCordsOfSnake.clear();

    xCordsOfSnake.push_back(xDirect);
    xCordsOfSnake.push_back(xDirect + 20);
    xCordsOfSnake.push_back(xDirect + 40);
    xCordsOfSnake.push_back(xDirect + 60);

    yCordsOfSnake.push_back(yDirect);
    yCordsOfSnake.push_back(yDirect + 20);
    yCordsOfSnake.push_back(yDirect + 40);
    yCordsOfSnake.push_back(yDirect + 60);

    directionOfHead = Direction::LEFT;
    level = 1;
    score = 0;

    bodyTexture.clear();
    for (int i = 0; i < 3; ++i)
    {
        if (i == 0)
        {
            bodyTexture.push_back(head);
        }
        else
            bodyTexture.push_back(body);
    }
}

bool Movement::updateLevel(int scoreToLevelUp)
{
    if (score >= scoreToLevelUp)
    {
        level++;
        std::cout << "Level: " << level << std::endl;
        return true;
    }
    return false;
}

void Movement::updateMovementDirection()
{
    switch (directionOfHead)
    {
        case Movement::Direction::LEFT:
            xDirect = xDirect - speedOfSnake;
            break;
        case Movement::Direction::RIGHT:
            xDirect = xDirect + speedOfSnake;
            break;
        case Movement::Direction::UP:
            yDirect = yDirect - speedOfSnake;
            break;
        case Movement::Direction::DOWN:
            yDirect = yDirect + speedOfSnake;
            break;
        default:
            std::cout << "Nieznany kierunek";

    }
}

void Movement::checkPressedKey(sf::Event event)
{
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
    {

        if (directionOfHead != Movement::Direction::RIGHT)
        {
            directionOfHead = Movement::Direction::LEFT;
        }


    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
    {

        if (directionOfHead != Movement::Direction::LEFT)
        {
            directionOfHead = Movement::Direction::RIGHT;
        }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
    {

        if (directionOfHead != Movement::Direction::DOWN)
        {
            directionOfHead = Movement::Direction::UP;
        }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
    {

        if (directionOfHead != Movement::Direction::UP)
        {
            directionOfHead = Movement::Direction::DOWN;
        }
    }
}

