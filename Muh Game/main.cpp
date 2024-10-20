#include <iostream>
#include "Combat.h"
#include "Character.h"
#include "Weapon.h"

int main() {
    // Create instances of characters with the new constructor
    Character player("Hero", "Warriors", "Human"); // (name, clan, species)
    Character enemy("Goblin", "Monsters", "Goblin");

    // Create a sword weapon using the appropriate constructor
    Weapon sword("Iron Sword", 50, 1, 8, "Iron", "Standard"); // (desc, val, qty, die, mat, qual)

    // Create a combat instance
    Combat combat;

    // Start the combat loop
    combat.combatLoop(player, enemy);

    return 0;
}