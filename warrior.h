#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"

class Warrior : public Player{
    std::string weapon;
public:
    Warrior(std::string n="", int h=0, int d=0, std::string w="");
    std::string getWeapon() const;
    void setWeapon(const std::string& w);
    void useWeapon(Player& opponent);
};

#endif