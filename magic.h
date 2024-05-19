#ifndef MAGIC_H
#define MAGIC_H
#include <iostream>
#include <string>


class Magic
{
public:
    Magic();
    void setName(std::string name);
    void setStrength(int strength);
    void setSelfStrength(int sstrength);
    void setCastCost(int ccost);
    void setElement(std::string elem);
    void setGoldCost(int gcost);
    void setRequiredSpell(std::string spell);
    std::string getName() const;
    int getStrength() const;
    int getSelfStrength() const;
    int getCastCost() const;
    std::string getElement() const;
    int getGoldCost() const;
    std::string getRequiredSpell() const;
private:
    std::string mName;
    int mStrength;
    int mSelfStrength;
    int mCastCost;
    std::string mElement;
    int mGoldCost;
    std::string mRequiredSpell;
};

#endif // MAGIC_H
