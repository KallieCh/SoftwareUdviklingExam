#include <iostream>
#include "hero.h"
#include "gamestate.h"
#include "client.h"
#include "enemy.h"
#include "caves.h"

int main()
{
    Hero h;
    GameState g;
    client c;
    Enemy e;
    Caves ca;
    std::cout << "Press s to start an adventure! " << std::endl;
    char key;
    int tmp;
    std::string str;
    std::cin >> key;
    if (key=='s'){
        std::cout << "Do you wanna choose a character or create your own?"<< std::endl;
        std::cout << "To choose a preexisting character press 1 & to create your own press 2" << std::endl;
        std::cin >> tmp;
        if (tmp==1){
            //print the table of heroes with the different names and hp and stuff
            std::cout << "These are the heroes " << std::endl;
            auto listOfHeroes = c.printListofHero();
            int iterator = 0;
            for(int i = 0; i < listOfHeroes.size(); ++i){
                iterator = i + 1;
                std::cout << iterator << ": " << listOfHeroes[i].getName() << "\n"
                << "Hp: " << listOfHeroes[i].getHp() << "\n"
                << "Level: "<< listOfHeroes[i].getLevel() <<"\n"
                << "Xp: " << listOfHeroes[i].getXp() <<"\n"
                << "Damage: " <<listOfHeroes[i].getDamage() << "\n"
                << "Gold: " << listOfHeroes[i].getGold() << "\n" << std::endl;

            }
            std::cout << "Enter hero number to choose them:" << std::endl;
            int num;
            std::cin >> num;
            h = listOfHeroes[num-1];
            c.loadHeroMagic(h);
            std::cout << "The character you chose is: " <<h.getName()<<std::endl;

        } else if (tmp==2){
            std::string name;
            std::cout<< "Enter the name of the hero:"<< std::endl;
            std::cin >> name;
            h = Hero(name);
            std::cout << "The player's name is: "<< h.getName()<< std::endl;
        }
    }else{
        std::cout<< "Please follow the suggested format..." << std::endl;
    }
    char fe;
    while(fe != 'e'){
        std::cout << "Press 'f' to fight an enemy, press 'q' to go on a quest in a cave, press 's' to go to the magic strore, or 'e' to save and exit:"<< std::endl;
        int i=0;
        std::cin>>fe;
        if (fe == 'f'){
            std::cout<< "Choose an enemy to fight:"<< std::endl;
            auto listOfEnemies = c.printListofEnemies();
            int iterator = 0;
            for(int i = 0; i < listOfEnemies.size(); ++i){
                iterator = i + 1;
                std::cout << iterator << ": " << listOfEnemies[i].getName() << "\n"
                << "Hp: " << listOfEnemies[i].getHp() << "\n"
                << "Xp: " << listOfEnemies[i].getXp() <<"\n"
                << "Damage: " <<listOfEnemies[i].getDamage() << "\n"
                << "Element: "<<listOfEnemies[i].getElement() << "\n" << std::endl;


            }
            std::cin>>i;
                e.setDamage(listOfEnemies[i-1].getDamage());
                e.setHp(listOfEnemies[i-1].getHp());
                e.setXp(listOfEnemies[i-1].getXp());
                e.setName(listOfEnemies[i-1].getName());
                e.setElement(listOfEnemies[i-1].getElement());
                g.fight(h,e);
            }else if(fe == 'e'){
            std::cout << "Saving and exiting" << std::endl;
        }else if (fe == 'q'){
            std::cout<< "Choose a cave to enter:"<< std::endl;
            std::vector<std::pair<std::string, int>> caves = c.printCave();
            int iterator = 0;
            for (int i=0; i<caves.size(); ++i){
                iterator = i+1;
                std::cout<< iterator<< ": " << caves[i].first <<std::endl;
            }
            int num;
            std::cin>> num;
            ca.setCaveName(caves[num-1].first);
            ca.setGold(caves[num-1].second);
            auto enemies = c.getEnemiesInCave(ca.getCaveName());
            ca.setListOfEnemies(enemies);
            ca.enterTheCave(h, g);
        } else if(fe=='s'){
            g.enterMagicShop(h,c);
        }
        else{
            std::cout<< "Please follow the suggested format..." << std::endl;
        }
        //std::cout << "Do you wanna keep fighting? Press f, otherwise press e to save and exit." << std:: endl;
    }
    /*std::cout << "Press 'f' to fight an enemy or 'e' to save and exit:"<< std::endl;
    int i=0;
    std::cin>>fe;
    if (fe == 'f'){
        std::cout<< "Choose an enemy to fight:"<< std::endl;
        auto listOfEnemies = c.printListofEnemies();
        int iterator = 0;
        for(int i = 0; i < listOfEnemies.size(); ++i){
            iterator = i + 1;
            std::cout << iterator << ": " << listOfEnemies[i].getName() << "\n"
            << "Hp: " << listOfEnemies[i].getHp() << "\n"
            << "Xp: " << listOfEnemies[i].getXp() <<"\n"
            << "Damage: " <<listOfEnemies[i].getDamage() << "\n" << std::endl;


        }
        std::cin>>i;
            e.setDamage(listOfEnemies[i-1].getDamage());
            e.setHp(listOfEnemies[i-1].getHp());
            e.setXp(listOfEnemies[i-1].getXp());
            e.setName(listOfEnemies[i-1].getName());
            g.fight(h,e);
        }
    std::cout << "Do you wanna keep fighting? Press f, otherwise press e to save and exit." << std:: endl;
    */ if (fe == 'e'){
        std::cout<< "Exiting the game..." << std::endl;
        c.saveGame(h);
        std::cout << "Updated list of heroes " << std::endl;
        auto listOfHeroes = c.printListofHero();
        int iterator = 0;
        for(int i = 0; i < listOfHeroes.size(); ++i){
            iterator = i + 1;
            std::cout << iterator << ": " << listOfHeroes[i].getName() << std::endl;

        }
    }
    return 0;
}
