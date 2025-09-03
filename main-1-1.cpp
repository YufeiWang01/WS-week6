#include <iostream>
#include "player.h"
#include "wizard.h"
#include "warrior.h"

int main() {
    Wizard wizard("Gandalf", 100, 20, 50);
    Warrior warrior("Aragorn", 120, 25, "Sword");

    std::cout << "Let the battle begin!" << std::endl;

    while (wizard.getHealth() > 0 && warrior.getHealth() > 0) {
        wizard.castSpell(warrior);
        if (warrior.getHealth() > 0) {
            warrior.useWeapon(wizard);
        }
    }

    if (wizard.getHealth() > 0) {
        std::cout << wizard.getName() << " wins!" << std::endl;
    } else {
        std::cout << warrior.getName() << " wins!" << std::endl;
    }

    return 0;
}