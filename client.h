#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include "hero.h"
#include "enemy.h"

class client
{
public:
    client();
    std::vector<Hero> printListofHero();
    std::vector<Enemy> printListofEnemies();
    void saveGame(Hero &h);
    void deleteFromTable(Hero h);
    bool doesHeroExist(const QString &heroName);
};

#endif // CLIENT_H
