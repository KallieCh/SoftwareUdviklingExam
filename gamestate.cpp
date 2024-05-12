#include "gamestate.h"


GameState::GameState()
{

}

void GameState::chooseHero()
{

}

void GameState::setHero(Hero h)
{
    //remember to add it to the table so that it's saved there
    //delete automatically if hp=0;
}

void GameState::fight(Hero &h, Enemy &e)
{
    int iterator=0;
    while (((h.getHp()>0) && (e.getHp()>0))){
        if ((iterator %2)==0){
            //hero attacks
            int dam=h.getDamage();//dam is equal to what i get from my funciton getDamage
            e.setHp(e.getHp()-dam);
            std:: cout << "Hero attacked for: " << h.getDamage() << " Enemy health: " << e.getHp() << " " << iterator << std::endl;
        } else if ((iterator %2) !=0){
            //enemy's turn to attack
            int dam=e.getDamage();
            h.setHp(h.getHp()-dam);
            std::cout << "Enemy attacked for: " << e.getDamage() << " Hero health: " << h.getHp() << " " << iterator << std::endl;
        } iterator++;
    } if (e.getHp()<=0){
        h.setXp(h.getXp()+e.getXp());
        std::cout << "Hero Xp: " << h.getXp() << std::endl;
        h.upOnLevel();
        std::cout << "Congratulations! You won the fight! " << h.getName() << " gained " << e.getXp() << " Xp" << std::endl;
    }   else if ( h.getHp()<=0){
        std::cout << "You lost the fight... GAME OVER" << std::endl;
    }

}
