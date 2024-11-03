#include "Combat.h"
#include "Character.h"
#include "Roll.h"
#include "AttackStance.h"
#include "DefenseStance.h"
#include "stance.h"
#include <iostream>
#include <algorithm>

// Initialize Roll
Roll dice;

// Constructor for Combat
Combat::Combat() {}

// Unified function to get stats for a stance
int Combat::getStats(Character& combatant, const std::string& stanceName, bool isAttack) {
    if (isAttack) {
        const auto& equippedAttacks = combatant.getAttackStancesEquipped();
        for (const auto& stance : equippedAttacks) {
            if (stance->getName() == stanceName) {
                int stat1 = combatant.getStatFromStance(stance->getPrimaryStat());
                int stat2 = combatant.getStatFromStance(stance->getSecondaryStat());
                return stat1 + stat2 + dice.roll(20);
            }
        }
    }
    else {
        const auto& equippedDefenses = combatant.getDefenseStancesEquipped();
        for (const auto& stance : equippedDefenses) {
            if (stance->getName() == stanceName) {
                int stat1 = combatant.getStatFromStance(stance->getPrimaryStat());
                int stat2 = combatant.getStatFromStance(stance->getSecondaryStat());
                return stat1 + stat2 + dice.roll(20);
            }
        }
    }
    return 0; // If no matching stance is found
}


// Main combat loop
void Combat::combatLoop(Character& combatantA, Character& combatantB) {
    int round = 0;
    while (combatantA.getHp() > 0 && combatantB.getHp() > 0) {
        round++;
        std::cout << "=== Round " << round << " ===" << std::endl;

        std::pair<std::string, std::string> choicesA = getChoices(combatantA);
        std::pair<std::string, std::string> choicesB = getChoices(combatantB);
        std::string attackA = choicesA.first; // Removed toLowerCase
        std::string defenseA = choicesA.second; // Removed toLowerCase
        std::string attackB = choicesB.first; // Removed toLowerCase
        std::string defenseB = choicesB.second; // Removed toLowerCase

        // Determine initiative
        std::string first = determineFirst(combatantA, combatantB);

        // Attack and defense calculations
        int attackStatA = getStats(combatantA, attackA, true);
        int defenseStatB = getStats(combatantB, defenseB, false);
        int attackStatB = getStats(combatantB, attackB, true);
        int defenseStatA = getStats(combatantA, defenseA, false);

        // Combat based on initiative
        if (first == "A") {
            processAttack(combatantA, combatantB, attackStatA, defenseStatB, attackA);
            if (combatantB.getHp() > 0) {
                processAttack(combatantB, combatantA, attackStatB, defenseStatA, attackB);
            }
        }
        else {
            processAttack(combatantB, combatantA, attackStatB, defenseStatA, attackB);
            if (combatantA.getHp() > 0) {
                processAttack(combatantA, combatantB, attackStatA, defenseStatB, attackA);
            }
        }

        // Display health after round
        std::cout << combatantA.getName() << " Health: " << combatantA.getHp()
            << " | " << combatantB.getName() << " Health: " << combatantB.getHp() << std::endl;
        std::cout << "-----------------------------" << std::endl;

        // Check if the fight is over
        if (combatantA.getHp() <= 0) {
            std::cout << combatantB.getName() << " wins!" << std::endl;
            break;
        }
        if (combatantB.getHp() <= 0) {
            std::cout << combatantA.getName() << " wins!" << std::endl;
            break;
        }
    }
}

// Get and validate attack/defense choices for a combatant
std::pair<std::string, std::string> Combat::getChoices(Character& combatant) {
    std::string attack;
    std::string defense;
    bool valid;

    // Validate attack choice
    while (true) {
        std::cout << combatant.getName() << ", choose your attack stance: ";
        std::getline(std::cin, attack);

        // Check if the attack stance is valid
        const auto& equippedAttacks = combatant.getAttackStancesEquipped();
        valid = std::any_of(equippedAttacks.begin(), equippedAttacks.end(),
            [&attack](const std::shared_ptr<AttackStance>& stance) {
                return stance && stance->getName() == attack; // Dereference the shared pointer
            });

        if (valid) {
            break; // Valid choice
        }
        else {
            std::cout << "Invalid attack stance! Please choose a valid stance." << std::endl;
        }
    }

    // Validate defense choice
    while (true) {
        std::cout << combatant.getName() << ", choose your defense stance: ";
        std::getline(std::cin, defense);

        // Check if the defense stance is valid
        const auto& equippedDefenses = combatant.getDefenseStancesEquipped();
        valid = std::any_of(equippedDefenses.begin(), equippedDefenses.end(),
            [&defense](const std::shared_ptr<DefenseStance>& stance) {
                return stance && stance->getName() == defense; // Dereference the shared pointer
            });

        if (valid) {
            break; // Valid choice
        }
        else {
            std::cout << "Invalid defense stance! Please choose a valid stance." << std::endl;
        }
    }

    return { attack, defense }; // Return the chosen attack and defense
}

// Determine which combatant acts first based on initiative roll
std::string Combat::determineFirst(Character& combatantA, Character& combatantB) {
    int rollA = dice.roll(20);
    int rollB = dice.roll(20);

    std::cout << combatantA.getName() << " initiative roll: " << rollA << std::endl;
    std::cout << combatantB.getName() << " initiative roll: " << rollB << std::endl;

    return rollA > rollB ? "A" : "B";
}

// Get the damage for the attack
int Combat::calculateDamage(const Character& attacker, const std::string& stanceType) {
    int dieSize = attacker.damageDie();
    int roll = dice.roll(dieSize);
    int damage = roll + 3; // Example bonus, adjust later
    return damage;
}

// Process the attack for a combatant
void Combat::processAttack(Character& attacker, Character& defender, int attackRoll, int defenseRoll, const std::string& stanceType) {
    if (attackRoll >= defenseRoll) {
        int damage = calculateDamage(attacker, stanceType);
        defender.setHp(defender.getHp() - damage);
        std::cout << attacker.getName() << " hits! " << defender.getName() << " takes " << damage << " damage." << std::endl;
    }
    else {
        std::cout << attacker.getName() << " misses!" << std::endl;
    }
}
// I have not added the advantages system here yet so that needs to get done at some point