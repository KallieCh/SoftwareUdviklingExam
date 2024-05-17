#ifndef CAVES_H
#define CAVES_H
#include <iostream>
#include <string>
#include <vector>
#include "enemy.h"
#include "hero.h"
#include "gamestate.h"
class Caves
{
public:
    Caves();
    Caves(std::string name, int gold, std::vector<Enemy> ListOfEnemies):mName(name), mGold(gold), mListofEnemies(ListOfEnemies){};
    void enterTheCave(Hero& h, GameState& gs);
    void setCaveName(std::string name);
    void setGold(int gold);
    void setListOfEnemies(std::vector<Enemy> en);
    void addToEnemyVector(Enemy& e);
    std::string getCaveName() const;
    int getGold() const;
    std::vector<Enemy> getListOfEnemies() const;

private:
    std::string mName;
    int mGold;
    std::vector<Enemy> mListofEnemies;
};

#endif // CAVES_H
