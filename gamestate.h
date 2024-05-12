#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "hero.h"
#include "enemy.h"

class GameState
{
public:
    GameState();
    void chooseHero();
    void setHero(Hero h);
    void fight(Hero& h, Enemy& e);


private:
};

#endif // GAMESTATE_H
