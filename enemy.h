#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>


class Enemy
{
public:
    Enemy();
    void setName(std::string name);
    void setHp(int hp);
    void setXp(int xp);
    void setDamage(int damage);
    std::string getName() const;
    int getHp() const;
    int getXp() const;
    int getDamage() const;

private:
    std::string mName;
    int mHp;
    int mXp;
    int mDamage;
};

#endif // ENEMY_H
