#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include "hero.h"
#include "enemy.h"
#include <utility>
#include "magic.h"

class client
{
public:
    client();
    std::vector<Hero> printListofHero();
    std::vector<Enemy> printListofEnemies();
    void saveGame(Hero &h);
    void deleteFromTable(Hero h);
    bool doesHeroExist(const QString &heroName);
    std::vector<Enemy> getEnemiesInCave(std::string caveName);
    std::vector<std::pair<std::string, int >> printCave();
    void getMagic(Hero& h);
    bool doesHeroHaveMagic(const QString &MagicName, const QString &HeroName);
    void saveHeroMagic(Hero& h);
    void loadHeroMagic(Hero& h);
    std::vector<Magic> printListOfMagic();
};

#endif // CLIENT_H
