#include "magic.h"

Magic::Magic()
{

}

void Magic::setName(std::string name)
{
    mName = name;
}

void Magic::setStrength(int strength)
{
    mStrength = strength;
}

void Magic::setSelfStrength(int sstrength)
{
    mSelfStrength = sstrength;
}

void Magic::setCastCost(int ccost)
{
    mCastCost = ccost;
}

void Magic::setElement(std::string elem)
{
    mElement = elem;
}

void Magic::setGoldCost(int gcost)
{
    mGoldCost = gcost;
}

void Magic::setRequiredSpell(std::string spell)
{
    mRequiredSpell = spell;
}

std::string Magic::getName() const
{
    return mName;
}

int Magic::getStrength() const
{
    return mStrength;
}

int Magic::getSelfStrength() const
{
    return mSelfStrength;
}

int Magic::getCastCost() const
{
    return mCastCost;
}

std::string Magic::getElement() const
{
    return mElement;
}

int Magic::getGoldCost() const
{
    return mGoldCost;
}

std::string Magic::getRequiredSpell() const
{
    return mRequiredSpell;
}
