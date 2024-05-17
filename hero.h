#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <string>

class Hero
{
public:
    Hero();
    Hero(std::string name){mName = name; mHp = 10; mLevel = 1; mXp=0; mDamage=2; mGold=0;};
    void setName (std::string name);
    void setHp (int Hp);
    void setXp (int Xp);
    void setLevel (int Level);
    void setDamage (int Damage);
    void upOnLevel ();
    std::string getName() const;
    int getXp () const;
    int getLevel () const;
    int getHp() const;
    int getDamage() const;
    Hero& operator=(const Hero& rhs);
    void setGold(int g);
    int getGold() const;
private:
    std::string mName;
    int mXp;
    int mLevel;
    int mHp;
    int mDamage;
    int mGold;

};

#endif // HERO_H
