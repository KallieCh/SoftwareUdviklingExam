#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "hero.h"
#include "enemy.h"
#include "client.h"

class GameState
{
public:
    GameState();
    void fight(Hero& h, Enemy& e);
    void enterMagicShop(Hero& h, client& c);
    double ElementBuff(Magic& m, Enemy& e);
    int addDamageBuff(Magic& m, Enemy& e);
    bool DoHeroHaveSpell(Hero& h, std::string spell);

private:
};

#endif // GAMESTATE_H
