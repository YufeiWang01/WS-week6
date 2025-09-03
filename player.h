
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
protected:
    std::string name;
    int health;
    int damage;
public:
    Player(std::string n="", int h=0, int d=0);
    std::string getName() const;
    int getHealth() const;
    int getDamage() const;
    void setName(const std::string& n);
    void setHealth(int h);
    void setDamage(int d);
    void takeDamage(int amt);
    virtual void attack(Player& opponent);
    virtual ~Player() {}
};

class Wizard : public Player{
    int mana;
public:
    Wizard(std::string n="", int h=0, int d=0, int m=0);
    int getMana() const;
    void setMana(int m);
    void castSpell(Player& opponent);
};

class Warrior : public Player{
    std::string weapon;
public:
    Warrior(std::string n="", int h=0, int d=0, std::string w="");
    std::string getWeapon() const;
    void setWeapon(const std::string& w);
    void useWeapon(Player& opponent);
};

#endif