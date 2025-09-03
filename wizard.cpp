#include "Wizard.h"
#include <iostream>
#include <cstdlib>

extern int vary(int base);

Wizard::Wizard(std::string n, int h, int d, int m) : Player(n,h,d), mana(m) {}
int Wizard::getMana() const { return mana; }
void Wizard::setMana(int m) { mana = m; }
void Wizard::castSpell(Player& opponent) {
    int dmg = vary(mana);
    opponent.takeDamage(dmg);
    std::cout << name << " casts a spell on " << opponent.getName()
              << " for " << dmg << " damage. "
              << opponent.getName() << "'s health: "
              << opponent.getHealth() << "\n";
}