#ifndef SNAKE_LEVELPARAMETERS_H
#define SNAKE_LEVELPARAMETERS_H

#include <vector>
#include "Food.h"
#include "Enemy.h"

class LevelParameters
{
public:
    LevelParameters()
    {}

    LevelParameters(int speedOfGamePlay, std::vector<Food *> &foods, std::vector<Enemy*> &enemies, int scoreToLevelUp);

    std::vector<Food*> foods;
    std::vector<Enemy*> enemies;
    int speedOfGamePlay{50};
    int appleAmount{0};
    int orangeAmount{0};
    int bananaAmount{0};
    int spidersAmount{0};
    int scoreToLevelUp{0};


};
#endif //SNAKE_LEVELPARAMETERS_H
