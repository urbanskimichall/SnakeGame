#include "LevelParameters.h"

LevelParameters::LevelParameters(int speedOfGamePlay, std::vector<Food *> &foods,
                                 std::vector<Enemy*> &enemies, int scoreToLevelUp)
{
    this->foods = foods;
    this->enemies = enemies;
    this->speedOfGamePlay = speedOfGamePlay;
    this->spidersAmount = spidersAmount;
    this->scoreToLevelUp = scoreToLevelUp;
}