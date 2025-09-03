#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"

class Wizard : public Player {
    int mana;
public:
    Wizard(std::string n="", int h=0, int d=0, int m=0);
    int getMana() const;
    void setMana(int m);
    void castSpell(Player& opponent);
};

#endif