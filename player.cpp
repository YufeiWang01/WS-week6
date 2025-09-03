#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

static int vary(int base) {
    int pct = (std::rand() % 41) - 20;
    int v = base + base * pct / 100;
    if (v < 0) v = 0;
    return v;
}

Player::Player(std::string n, int h, int d) : name(n), health(h), damage(d) {}
std::string Player::getName() const { return name; }
int Player::getHealth() const { return health; }
int Player::getDamage() const { return damage; }
void Player::setName(const std::string& n) { name = n; }
void Player::setHealth(int h) { health = h; }
void Player::setDamage(int d) { damage = d; }
void Player::takeDamage(int amt) { health = (health - amt < 0 ? 0 : health - amt); }

void Player::attack(Player& opponent) {
    int dmg = vary(damage);
    opponent.takeDamage(dmg);
    std::cout << name << " attacks " << opponent.getName()
              << " for " << dmg << " damage. "
              << opponent.getName() << "'s health: "
              << opponent.getHealth() << "\n";
}

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