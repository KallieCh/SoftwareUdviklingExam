#include "client.h"
#include <QString>


client::client() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("game"); // Ret til det schema navn du har valgt
    db.setUserName("sammy");       // Ret brugernavn
    db.setPassword("password");   // Ret password
    db.open();
}

std::vector<Hero> client::printListofHero()
{
    Hero h;
    std::vector<Hero> vec;
    QSqlQuery query;//? the constent of the function
    query.exec("SELECT * FROM heroes"); // tasks er her navnet på en tabel, ikke et schema
    while (query.next()) {
        /*
        QString name = query.value(0).toString();
        int hp = query.value(1).toInt();
        int level = query.value(2).toInt();
        int xp = query.value(3).toInt();
        int damage = query.value(4).toInt();
        */
        h.setName(query.value(0).toString().toStdString());
        h.setHp(query.value(1).toInt());
        h.setLevel(query.value(2).toInt());
        h.setXp(query.value(3).toInt());
        h.setDamage(query.value(4).toInt());
        h.setGold(query.value(5).toInt());
        vec.push_back(h);
    }
    return vec;
}


std::vector<Enemy> client::printListofEnemies()//print content of enemy table and returns it in a vector
{
    Enemy e;
    std::vector<Enemy> vec;
    QSqlQuery query;
    query.exec("SELECT * FROM enemies" ); // tasks er her navnet på en tabel, ikke et schema
    while (query.next()) {
        /*QString name = query.value(0).toString();
        int hp = query.value(1).toInt();
        int xp = query.value(2).toInt();
        int damage = query.value(3).toInt();
        qDebug() << "Name: " << name << "Hp: " << hp << "Xp: " << xp << "Damage: " << damage;
        */
        e.setName(query.value(0).toString().toStdString());
        e.setHp(query.value(1).toInt());
        e.setXp(query.value(2).toInt());
        e.setDamage(query.value(3).toInt());
        e.setElement(query.value(4).toString().toStdString());
        vec.push_back(e);
    }
    return vec;
}


void client::saveGame(Hero& h)//check content of function
{
    if(doesHeroExist(QString::fromStdString(h.getName()))){
        QSqlQuery query;
        auto name = h.getName();
        QString str = QString::fromStdString(name);
        auto Hp = h.getHp();
        auto level = h.getLevel();
        auto xp = h.getXp();
        auto dmg = h.getDamage();
        int gl =h.getGold();
        QString sqlQuery = "UPDATE heroes "
                          "SET HP = :new_hp_value, "
                          "    XP = :new_xp_value, "
                          "    Damage = :new_damage_value, "
                          "    Level = :new_level_value, "
                          "    gold = :gld "
                          "WHERE name = :name";
        query.prepare(sqlQuery);
        query.bindValue(":new_hp_value", Hp); // Replace with actual value
        query.bindValue(":new_xp_value", xp); // Replace with actual value
        query.bindValue(":new_damage_value", dmg); // Replace with actual value
        query.bindValue(":new_level_value", level); // Replace with actual value
        query.bindValue(":gld", gl);
        query.bindValue(":name", str);
        query.exec();
        //qDebug() << query.lastError();

    }else{

    QSqlQuery query;
    auto name = h.getName();
    QString str = QString::fromStdString(name);
    auto Hp = h.getHp();
    auto level = h.getLevel();
    auto xp = h.getXp();
    auto dmg = h.getDamage();
    auto gl = h.getGold();
    query.prepare("INSERT INTO heroes (name, hp, level, xp, damage, gold) "
                  "VALUES (:name, :hp, :level, :xp, :damage, :gld)");
    query.bindValue(":name", str);
    query.bindValue(":hp", Hp);
    query.bindValue(":level", level);
    query.bindValue(":xp", xp);
    query.bindValue(":damage", dmg);
    query.bindValue(":gld", gl);
    //qDebug() << query.lastError();
    query.exec();
    //qDebug() << "Insert succesful";
    }
    saveHeroMagic(h);
}

/*void client::deleteFromTable(Hero h)//check conent of function
{
    QSqlQuery query;
        query.exec("DELETE FROM heroes WHERE name = " + TaskId);
        qDebug() << "Deleting succesful";
}*/

bool client::doesHeroExist(const QString &heroName) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM heroes WHERE name = :name");
    query.bindValue(":name", heroName);
    query.exec();

    if (query.next()) {
        int rowCount = query.value(0).toInt();
        return rowCount > 0; // Return true if entry exists, false otherwise
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }
}

std::vector<Enemy> client::getEnemiesInCave(std::string caveName)
{//get names of enemies in order to create a vector containing enemies that go in a cave
    auto enemies = printListofEnemies();
    Enemy e;
    std::vector<Enemy> vec;
    //create a separate query that returns the names of enemies that go in a cave
    QSqlQuery query;
    query.prepare("SELECT enemies_name FROM cave_enemies WHERE cave_name = :name");
    query.bindValue(":name", QString::fromStdString(caveName));
    query.exec();
    while (query.next()) {
        e.setName(query.value(0).toString().toStdString());
        for (int i=0; i<enemies.size(); i++){
            if (enemies[i].getName()==e.getName()){
                e.setHp(enemies[i].getHp());
                e.setXp(enemies[i].getXp());
                e.setDamage(enemies[i].getDamage());
                vec.push_back(e);
            }
        }
    }
    return vec;
}


std::vector<std::pair<std::string, int>> client::printCave()
{
    std::vector<std::pair<std::string, int>> vec;
    QSqlQuery query;
    query.exec("SELECT * FROM cave" ); // tasks er her navnet på en tabel, ikke et schema
    while (query.next()) {
        std::string name = query.value(0).toString().toStdString();
        int gold = query.value(1).toInt();
        vec.push_back(std::make_pair(name,gold));
        //qDebug() << query.value(0).toString();
    }
    return vec;
}

void client::getMagic(Hero &h)
{
    QSqlQuery query;
    query.prepare("SELECT magic_name FROM heroes_magic WHERE heroes_name = :name");
    query.bindValue(":name", QString::fromStdString(h.getName()));
    query.exec();
    std::vector<std::string> magicNames;
    while (query.next()){
        magicNames.push_back(query.value(0).toString().toStdString());
    }
    Magic m;
    for(auto names : magicNames){
        query.prepare("SELECT * FROM magic WHERE name = :name");
        query.bindValue(":name", QString::fromStdString(names));
        query.exec();
        while (query.next()){
            m.setName(query.value(0).toString().toStdString());
            m.setStrength(query.value(1).toInt());
            m.setSelfStrength(query.value(2).toInt());
            m.setCastCost(query.value(3).toInt());
            m.setElement(query.value(4).toString().toStdString());
            m.setGoldCost(query.value(5).toInt());
            m.setRequiredSpell(query.value(6).toString().toStdString());
            h.addToMagVec(m);
        }
    }
}

bool client::doesHeroHaveMagic(const QString &MagicName, const QString &HeroName)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM heroes_magic WHERE heroes_name = :hname AND magic_name = :mname");
    query.bindValue(":hname", HeroName);
    query.bindValue(":mname", MagicName);
    query.exec();
    if (query.next()) {
        //int rowCount = query.value(0).toInt();
        return true; // Return true if entry exists, false otherwise
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }
}

void client::saveHeroMagic(Hero &h)
{
    QSqlQuery query;
    auto magic = h.getMagic();
    for(auto m : magic){
        if(!doesHeroHaveMagic(QString::fromStdString(m.getName()),QString::fromStdString(h.getName()))){
            //query.prepare("INSERT INTO heroes_magic (heroes_name, magic_name) "
            //              "VALUES (:hname, :mname)");
            query.prepare("INSERT INTO heroes_magic (heroes_name, magic_name) "
                          "VALUES (:hname, :mname)");
            query.bindValue(":hname", QString::fromStdString(h.getName()));
            query.bindValue(":mname", QString::fromStdString(m.getName()));
            query.exec();
        }
    }
    qDebug() << "Magic saved!";
}

void client::loadHeroMagic(Hero &h)
{
    QSqlQuery query;
    std::vector<std::string> mnames;
    query.prepare("SELECT * FROM heroes_magic WHERE heroes_name = :hname");
    query.bindValue(":hname", QString::fromStdString(h.getName()));
    query.exec();
    while(query.next()){
        mnames.push_back(query.value(1).toString().toStdString());
    }
    auto list = printListOfMagic();
    std::vector<Magic> hmagic;
    for(int i = 0; i < mnames.size(); ++i){
        for(int j = 0; j < list.size(); ++j){
            if(mnames[i] == list[j].getName()){
                hmagic.push_back(list[j]);
            }
        }
    }
    h.setMagic(hmagic);
}

std::vector<Magic> client::printListOfMagic()
{
    Magic m;
    std::vector<Magic> mag;
    QSqlQuery query;//? the constent of the function
    query.exec("SELECT * FROM magic"); // tasks er her navnet på en tabel, ikke et schema
    while (query.next()) {
        m.setName(query.value(0).toString().toStdString());
        m.setStrength(query.value(1).toInt());
        m.setSelfStrength(query.value(2).toInt());
        m.setCastCost(query.value(3).toInt());
        m.setElement(query.value(4).toString().toStdString());
        m.setGoldCost(query.value(5).toInt());
        m.setRequiredSpell(query.value(6).toString().toStdString());
        mag.push_back(m);
    }
    return mag;
}

