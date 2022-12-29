#include "LevelUpdater.h"
#include "Apple.h"
#include "Banana.h"
#include "Orange.h"
#include "Enemy.h"
#include "Spider.h"

LevelUpdater::LevelUpdater()
{
    std::vector<Food *> foods;
    std::vector<Enemy *> enemies;
    Enemy *spider0 = new Spider(10, 200);
    enemies.push_back(spider0);
    Food *apple = new Apple;
    foods.push_back(apple);
    LevelParameters level1(50, foods, enemies, 5);
    levels[1] = level1;

    Food *apple1 = new Apple;
    foods.push_back(apple1);
    LevelParameters level2(48, foods, enemies, 15);
    levels[2] = level2;

    Food *orange = new Orange;
    foods.push_back(orange);
    LevelParameters level3(45, foods, enemies, 30);
    levels[3] = level3;

    Enemy *spider = new Spider(100, 250);
    enemies.push_back(spider);
    Food *orange1 = new Orange;
    foods.push_back(orange1);
    LevelParameters level4(40, foods, enemies, 50);
    levels[4] = level4;

    foods.erase(foods.begin());
    Food *banana = new Banana;
    foods.push_back(banana);
    LevelParameters level5(30, foods, enemies, 70);
    levels[5] = level5;

    Food *banana1 = new Banana;
    foods.push_back(banana1);
    LevelParameters level6(25, foods, enemies, 100);
    levels[6] = level6;

    Food *orange2 = new Orange;
    foods.push_back(orange2);
    LevelParameters level7(24, foods, enemies, 150);
    levels[7] = level7;

    Enemy *spider1 = new Spider(20, 250);
    enemies.push_back(spider1);
    Food *banana2 = new Banana;
    foods.push_back(banana2);
    LevelParameters level8(21, foods, enemies, 250);
    levels[8] = level8;

    Food *banana3 = new Banana;
    foods.push_back(banana3);
    LevelParameters level9(18, foods, enemies, 350);
    levels[9] = level9;

    Enemy *spider2 = new Spider(100, 250);
    enemies.push_back(spider2);
    Food *banana4 = new Banana;
    foods.push_back(banana4);
    LevelParameters level10(15, foods, enemies, 500);
    levels[10] = level10;
}

LevelParameters LevelUpdater::getLevelParameters(int level)
{
    return levels[level];
}

std::vector<Food *> LevelUpdater::prepareFood(int level)
{
    LevelParameters levelParameters = levels[level];

    std::vector<Food *> foodToEat;

    for (int i = 0; i < levelParameters.appleAmount; i++)
    {
        Food *appleToEat = new Apple;
        foodToEat.push_back(appleToEat);

    }
    for (int i = 0; i < levelParameters.bananaAmount; i++)
    {
        Food *bananaToEat = new Banana;
        foodToEat.push_back(bananaToEat);

    }
    for (int i = 0; i < levelParameters.orangeAmount; i++)
    {
        Food *orangeToEat = new Orange;
        foodToEat.push_back(orangeToEat);

    }
    return foodToEat;
}
