#include <SFML/Graphics.hpp>
#include "Movement.h"
#include "Spider.h"
#include "Banana.h"
#include "Obstacles.h"
#include "LevelUpdater.h"
#include <chrono>
#include <thread>


int main()
{
    int windowWidth{600};
    int windowHeight{600};
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake");

    LevelUpdater levelUpdater;

    sf::Texture textureOfBody;

    textureOfBody.loadFromFile("../Pictures/partOfSnake.png");

    sf::Sprite body;

    body.setTexture(textureOfBody);

    Obstacles obstacles;
    obstacles.loadTexturesOfObstacles();

    Movement moveOfSnake;

    std::vector<Enemy *> enemies;
    enemies.push_back(new Spider(100, 400));

    std::vector<Food *> foodToEat = levelUpdater.prepareFood(1);

    while (window.isOpen())
    {
        LevelParameters levelParameters1 = levelUpdater.getLevelParameters(moveOfSnake.level);
        foodToEat = levelParameters1.foods;
        enemies = levelParameters1.enemies;

        sf::Event event;

        for(int i = 0; i < foodToEat.size(); i++)
        {
            foodToEat[i]->loadTexture();
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            moveOfSnake.checkPressedKey(event);
        }

        moveOfSnake.updateLevel(levelParameters1.scoreToLevelUp);
        moveOfSnake.updateMovementDirection();
        moveOfSnake.updatePositionOfSnake(windowWidth, windowHeight);

        for (int i = 0; i < foodToEat.size(); i++)
        {
            if (moveOfSnake.checkIfFoodEaten(foodToEat[i]->getXfoodPosition(), foodToEat[i]->getYfoodPosition(),
                                             foodToEat[i]->scoreOfFood()))
            {
                foodToEat[i]->generateNewPosition(windowWidth, windowHeight, obstacles);
            }
            foodToEat[i]->updatePositionOfFood();
        }
        window.clear();

        for (int i = 0; i < enemies.size(); ++i)
        {
            enemies[i]->updatePositionOfEnemy(window, windowWidth, windowHeight);
        }

        for (int i = 0; i < foodToEat.size(); i++)
        {
            window.draw(foodToEat[i]->getSprite());
        }

        for (int i = moveOfSnake.bodyTexture.size() - 1; i >= 0; --i)
        {
            window.draw(moveOfSnake.bodyTexture[i]);
        }

        moveOfSnake.buttonOfGameOverDisplay(window, event, enemies, obstacles);
        window.draw(moveOfSnake.textOfPoints);
        window.draw(obstacles.getFenceSprite());
        window.draw(obstacles.getStoneSprite());
        window.display();

        LevelParameters levelParameters;

        levelParameters = levelUpdater.getLevelParameters(moveOfSnake.level);
        std::chrono::milliseconds timespan(levelParameters.speedOfGamePlay); // or whatever
        std::this_thread::sleep_for(timespan);
    }
    return 0;
}
