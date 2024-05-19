#include "caves.h"

Caves::Caves()
{
    mName = "";
    mGold = 0;
    mListofEnemies = std::vector<Enemy> (0);
}

void Caves::enterTheCave(Hero &h, GameState& gs)
{
    for(auto& e : mListofEnemies){
        std::cout << "You encounter a: " << e.getName() << std::endl;
        gs.fight(h,e);
    }
    if(h.getHp() > 0){
        std::cout << "Congratulations you beat the cave!!!" << std::endl;
        std::cout << "You found " << mGold << " at the end of the cave!!!" << std::endl;
        h.setGold(mGold);
        h.resetAfterFight();
        mGold = 0;
    }else{
        std::cout << "You perished in the cave!" << std::endl;
    }
}

void Caves::setCaveName(std::string name)
{
    mName = name;
}

void Caves::setGold(int gold)
{
    mGold = gold;
}

void Caves::setListOfEnemies(std::vector<Enemy> en)
{
    mListofEnemies = en; //
}

void Caves::addToEnemyVector(Enemy &e)
{
    mListofEnemies.push_back(e); //list of enemies in my cave
}

std::string Caves::getCaveName() const
{
    return mName;
}

int Caves::getGold() const
{
    return mGold;
}

std::vector<Enemy> Caves::getListOfEnemies() const
{
    return mListofEnemies;
}
