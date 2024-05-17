#include "hero.h"
#include "enemy.h"

Hero::Hero()
{
    mName = "";
    mLevel = 1;
    mXp = 0;
    mDamage = 2;
    mHp = 10;
    mGold =0;
}

void Hero::setName(std::string name)
{
    mName=name;
}

void Hero::setHp(int Hp)
{
    mHp = Hp;
}

void Hero::setXp(int Xp)
{
    mXp = Xp;
}

void Hero::setLevel(int Level)
{
    mLevel = Level;
}

void Hero::setDamage(int Damage)
{
    mDamage = Damage;
}

void Hero::upOnLevel()
{//we go up one level when the xp is equal to the players level * 1000
    if (mXp>=mLevel * 1000){
        mLevel++;
        mXp = 0; //xp becomes 0 again to start counting over
        mHp=(mHp+2);
        mDamage++;
        std::cout << "Level up!!! Hero level: " << this->getLevel() << std::endl;
    }

}

std::string Hero::getName() const
{
    return mName;
}

int Hero::getXp() const
{
    return mXp;
}

int Hero::getLevel() const
{
    return mLevel;
}

int Hero::getHp() const
{
    return mHp;
}

int Hero::getDamage() const
{
    return mDamage;
}

Hero &Hero::operator=(const Hero& rhs)
{
    if (this->mName != rhs.mName){
        this->mName = rhs.mName;
        this->mHp = rhs.mHp;
        this->mLevel = rhs.mLevel;
        this->mXp = rhs.mXp;
        this->mDamage = rhs.mDamage;
        this->mGold = rhs.mGold;
    }
}

void Hero::setGold(int g)
{
    mGold = g;
}

int Hero::getGold() const
{
    return mGold;
}
