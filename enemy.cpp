#include "enemy.h"

Enemy::Enemy()
{

}

void Enemy::setName(std::string name)
{
    mName = name;
}

void Enemy::setHp(int hp)
{
    mHp = hp;
}

void Enemy::setXp(int xp)
{
    mXp = xp;
}

void Enemy::setDamage(int damage)
{
    mDamage = damage;
}

std::string Enemy::getName() const
{
    return mName;
}

int Enemy::getHp() const
{
    return mHp;
}

int Enemy::getXp() const
{
    return mXp;
}

int Enemy::getDamage() const
{
    return mDamage;
}

void Enemy::setElement(std::string elem)
{
    mElement = elem;
}

std::string Enemy::getElement() const
{
    return mElement;
}
