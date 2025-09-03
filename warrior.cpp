#include "Warrior.h"
#include <iostream>
#include <cstdlib>

extern int vary(int base);

Warrior::Warrior(std::string n, int h, int d, std::string w) : Player(n,h,d), weapon(w) {}
std::string Warrior::getWeapon() const { return weapon; }
void Warrior::setWeapon(const std::string& w) { weapon = w; }
void Warrior::useWeapon(Player& opponent) {
    int dmg = vary(damage);
    opponent.takeDamage(dmg);
    std::cout << name << " swings their " << weapon
              << " at " << opponent.getName()
              << " for " << dmg << " damage. "
              << opponent.getName() << "'s health: "
              << opponent.getHealth() << "\n";
}