#include "gamestate.h"


GameState::GameState()
{

}

/*void GameState::fight(Hero &h, Enemy &e)
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

}*/

void GameState::fight(Hero &h, Enemy &e)
{
    char attack;
    int iterator=0;
    while (((h.getHp()>0) && (e.getHp()>0))){
        if ((iterator %2)==0){
            //hero attacks
            std::cout<<"How would you like to attack? Enter 'a' for a basic attack or 'm' for a magic attack!"<< std::endl;
            std::cin>>attack;
            if(attack=='a'){
                e.setHp(e.getHp()-h.getDamage());
                std:: cout << "Hero attacked for: " << h.getDamage() << " Enemy health: " << e.getHp() << " " << iterator << std::endl;
            }else if (attack=='m'){
                int iter = 0;
                auto list = h.getMagic();
                std::cout<<"Printing your spell book..."<<std::endl;
                for(int i = 0; i<list.size(); ++i){
                    iter = i+1;
                    std::cout<<iter<<": "<< list[i].getName()<<" Element: "<<list[i].getElement()<< " Damage: "<<list[i].getStrength()<<" Damage to self: "<<list[i].getSelfStrength()<<" Cost to cast: "<<list[i].getCastCost()<<std::endl;

                }int spellnr;
                std::cout<< "Enter the number of the spell you want: "<<std::endl;
                std::cin>> spellnr;
                Magic m = list[spellnr-1];
                if(h.getMagicLevel()>=m.getCastCost()){
                    e.setHp(e.getHp()-addDamageBuff(m,e));
                    h.setHp(h.getHp()-m.getSelfStrength());
                    h.setMagicLevel(h.getMagicLevel()-m.getCastCost());
                    std::cout<<"Magic worked! Damage dealt: "<< addDamageBuff(m,e)<< " with the spell: "<< m.getName()<<std::endl;
                }else{
                    std::cout<<"You tried to cast a spell but you forgot the words.. hahaha (insufficient mana to cast it)"<<std::endl;
                }

            }
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


void GameState::enterMagicShop(Hero &h, client &c)
{
    std::cout<<"Welcome to the magic shop" <<std::endl;
    auto list = c.printListOfMagic();
    int temp = 1;
    while(temp != 0){
        int iter=0;
        for(int i=0; i<list.size(); ++i){
            iter=i+1; //prints the most important characteristics of the magic i can buy
            std::cout<< iter << ": "<< list[i].getName()<< ", cost: "<<list[i].getGoldCost()<< ", required spells: "<<list[i].getRequiredSpell()<<std::endl;
        }
        std::cout<< "Enter the number of the spell you wanna buy, or '0' to exit the shop. "<<std::endl;
        std::cin>>temp;
        //Check recquirements
        auto hm=h.getMagic();
        if(hm.size() == 0){
            if(list[temp-1].getRequiredSpell() == ""){
                if(h.getGold()>=list[temp-1].getGoldCost()){
                    h.addToMagVec(list[temp-1]);
                    h.setGold(h.getGold()-list[temp-1].getGoldCost());
                    std::cout<<"Purchase made! You have " << h.getGold() << " gold remaining." <<std::endl;
                }else{
                    std::cout<<"You broke, go fight some caves!"<<std::endl;
                }
            }else{
                std::cout<<"You're missing the required spell: "<< list[temp-1].getRequiredSpell()<<std::endl;
            }
        }else{
            if(DoHeroHaveSpell(h, list[temp-1].getName())){
                std::cout << "You cannot buy the same spell twice!" << std::endl;
            }else{
                if(list[temp-1].getRequiredSpell() == ""){
                    if(h.getGold()>=list[temp-1].getGoldCost()){
                        h.addToMagVec(list[temp-1]);
                        h.setGold(h.getGold()-list[temp-1].getGoldCost());
                        std::cout<<"Purchase made! You have " << h.getGold() << " gold remaining." <<std::endl;
                    }else{
                        std::cout<<"You broke, go fight some caves!"<<std::endl;
                    }
                }else if(DoHeroHaveSpell(h, list[temp-1].getRequiredSpell())){
                    if(h.getGold()>=list[temp-1].getGoldCost()){
                        h.addToMagVec(list[temp-1]);
                        h.setGold(h.getGold()-list[temp-1].getGoldCost());
                        std::cout<<"Purchase made! You have " << h.getGold() << " gold remaining." <<std::endl;
                    }else{
                        std::cout<<"You broke, go fight some caves!"<<std::endl;
                    }
                }else{
                    std::cout<<"You're missing the required spell: "<< list[temp-1].getRequiredSpell()<<std::endl;
                }
            }
        }
        std::cout<< "Press '0' to exit shop or '1' to continue shopping! "<<std::endl;
        std::cin>>temp;
    }std::cout<<"Exiting shop..."<<std::endl;

}

double GameState::ElementBuff(Magic &m, Enemy &e)
{
    if(e.getElement()=="Woods"){
        if(m.getElement()=="Water"){
            return 0.5;
        } else if(m.getElement()=="Metal"){
            return 2;
        }
    } else if (e.getElement()=="Fire"){
        if(m.getElement()=="Woods"){
            return 0.5;
        }else if(m.getElement()=="Water"){
            return 2;
        }
    }else if (e.getElement()=="Earth"){
        if(m.getElement()=="Fire"){
            return 0.5;
        }else if(m.getElement()=="Woods"){
            return 2;
        }
    }else if (e.getElement()=="Metal"){
        if(m.getElement()=="Earth"){
            return 0.5;
        }else if(m.getElement()=="Fire"){
            return 2;
        }
    }else if (e.getElement()=="Water"){
        if(m.getElement()=="Metal"){
            return 0.5;
        }else if(m.getElement()=="Earth"){
            return 2;
        }
    }
    return 1;
}

int GameState::addDamageBuff(Magic &m, Enemy &e)
{
    return (m.getStrength()*ElementBuff(m,e));
}

bool GameState::DoHeroHaveSpell(Hero &h, std::string spell)
{
    auto list = h.getMagic();
    for(auto m : list){
        if(m.getName() == spell){
            return true;
        }
    }
    return false;
}
