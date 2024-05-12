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
        vec.push_back(h);
    }
    return vec;
}


std::vector<Enemy> client::printListofEnemies()//print content of function
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
        QString sqlQuery = "UPDATE heroes "
                          "SET HP = :new_hp_value, "
                          "    XP = :new_xp_value, "
                          "    Damage = :new_damage_value, "
                          "    Level = :new_level_value "
                          "WHERE name = :name";
        query.prepare(sqlQuery);
        query.bindValue(":new_hp_value", Hp); // Replace with actual value
        query.bindValue(":new_xp_value", xp); // Replace with actual value
        query.bindValue(":new_damage_value", dmg); // Replace with actual value
        query.bindValue(":new_level_value", level); // Replace with actual value
        query.bindValue(":name", str);
        query.exec();

    }else{

    QSqlQuery query;
    auto name = h.getName();
    QString str = QString::fromStdString(name);
    auto Hp = h.getHp();
    auto level = h.getLevel();
    auto xp = h.getXp();
    auto dmg = h.getDamage();
    query.prepare("INSERT INTO heroes (name, hp, level, xp, damage) "
                  "VALUES (:name, :hp, :level, :xp, :damage)");
    query.bindValue(":name", str);
    query.bindValue(":hp", Hp);
    query.bindValue(":level", level);
    query.bindValue(":xp", xp);
    query.bindValue(":damage", dmg);
    qDebug() << query.lastError();
    query.exec();
    qDebug() << "Insert succesful";
    }
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

