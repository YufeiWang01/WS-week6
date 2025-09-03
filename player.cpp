#include "Player.h"
#include <iostream>
#include <cstdlib>

static int vary(int base){
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