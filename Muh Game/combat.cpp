#include "combat.h"
#include "Character.h"
#include "Roll.h"
#include <iostream>
#include <unordered_map>

// Initialize the Roll class
Roll dice;

// Attack and defense move definitions
    std::unordered_map<std::string, std::pair<std::string, std::string>> attackMoves = {
        {"Strong", {"con", "str"}},
        {"Fast", {"dex", "str"}},
        {"Accurate", {"con", "dex"}}
    };

    std::unordered_map<std::string, std::pair<std::string, std::string>> defenseMoves = {
        {"Dodge", {"dex", "con"}},
        {"Block", {"str", "con"}},
        {"Parry", {"dex", "str"}}
    };


// Function to get the specified stat for a combatant
int Combat::getStat(const Character& combatant, const std::string& statName) {
    if (statName == "con") return combatant.getCon();
    else if (statName == "dex") return combatant.getDex();
    else if (statName == "str") return combatant.getStr();
    return 0; // Default case
}

// Unified function to get stats for attack or defense
int Combat::getStats(Character& combatant, const std::string& moveChoice, bool isAttack) {
    int stat1 = 0, stat2 = 0;

    if (isAttack && attackMoves.find(moveChoice) != attackMoves.end()) {
        // Get the pair directly
        std::pair<std::string, std::string> stats = attackMoves[moveChoice];
        std::string stat1Name = stats.first;
        std::string stat2Name = stats.second;

        // Fetch relevant stats using the new getStat function
        stat1 = getStat(combatant, stat1Name);
        stat2 = getStat(combatant, stat2Name);

        return stat1 + stat2 + dice.roll(20); // Add roll for attacks
    }
    else if (!isAttack && defenseMoves.find(moveChoice) != defenseMoves.end()) {
        // Get the pair directly
        std::pair<std::string, std::string> stats = defenseMoves[moveChoice];
        std::string stat1Name = stats.first;
        std::string stat2Name = stats.second;

        // Fetch relevant stats using the new getStat function
        stat1 = getStat(combatant, stat1Name);
        stat2 = getStat(combatant, stat2Name);

        return stat1 + stat2 + 10; // No roll for defense (It's Just a stat)
    }

    return 0; // Default return in case of invalid input
}

// Main combat loop
void Combat::combatLoop(Character& combatantA, Character& combatantB) {
    int round = 0;
    while (combatantA.getHp() > 0 && combatantB.getHp() > 0) {
        round++;
        std::cout << "=== Round " << round << " ===" << std::endl;

        // Get choices for both combatants
        std::pair<std::string, std::string> choicesA = getChoices(combatantA);
        std::pair<std::string, std::string> choicesB = getChoices(combatantB);
        std::string attackA = choicesA.first;
        std::string defenseA = choicesA.second;
        std::string attackB = choicesB.first;
        std::string defenseB = choicesB.second;

        // Determine initiative
        std::string first = determineFirst(combatantA, combatantB);

        // Attack and defense calculations for combatant A
        int attackStatA = getStats(combatantA, attackA, true);
        int defenseStatB = getStats(combatantB, defenseB, false) + 10;

        // Attack and defense calculations for combatant B
        int attackStatB = getStats(combatantB, attackB, true);
        int defenseStatA = getStats(combatantA, defenseA, false) + 10;

        // Perform combat based on initiative
        if (first == "A") {
            processAttack(combatantA, combatantB, attackStatA, defenseStatB, attackA);
            if (combatantB.getHp() > 0) { // Only attack if still alive
                processAttack(combatantB, combatantA, attackStatB, defenseStatA, attackB);
            }
        }
        else {
            processAttack(combatantB, combatantA, attackStatB, defenseStatA, attackB);
            if (combatantA.getHp() > 0) { // Only attack if still alive
                processAttack(combatantA, combatantB, attackStatA, defenseStatB, attackA);
            }
        }

        // Display current health
        std::cout << combatantA.getName() << " Health: " << combatantA.getHp()
            << " | " << combatantB.getName() << " Health: " << combatantB.getHp() << std::endl;
        std::cout << "-----------------------------" << std::endl;

        // Check for end of combat
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

// Get attack and defense choices for a combatant with validation
std::pair<std::string, std::string> getChoices(Character& combatant) {
    std::string attack;
    std::string defense;

    // Validate attack choice
    while (true) {
        std::cout << combatant.getName() << ", choose your attack action (Strong, Fast, Accurate): ";
        std::cin >> attack;

        if (attackMoves.find(attack) != attackMoves.end()) {
            break; // Valid choice
        }
        else {
            std::cout << "Invalid attack choice! Please choose Strong, Fast, or Accurate." << std::endl;
        }
    }

    // Validate defense choice
    while (true) {
        std::cout << combatant.getName() << ", choose your defense action (Dodge, Block, Parry): ";
        std::cin >> defense;

        if (defenseMoves.find(defense) != defenseMoves.end()) {
            break; // Valid choice
        }
        else {
            std::cout << "Invalid defense choice! Please choose Dodge, Block, or Parry." << std::endl;
        }
    }

    return { attack, defense };
}

// Determine which combatant acts first based on initiative
std::string determineFirst(Character& combatantA, Character& combatantB) {
    int rollA = dice.roll(20);
    int rollB = dice.roll(20);

    std::cout << combatantA.getName() << " initiative roll: " << rollA << std::endl;
    std::cout << combatantB.getName() << " initiative roll: " << rollB << std::endl;

    if (rollA > rollB) {
        return "A";
    }
    else {
        return "B";
    }
}

// Get the damage for the attack
int Combat::calculateDamage(const Character& attacker, const std::string& attackType) {
    int dieSize = attacker.damageDie();
    int roll = dice.roll(dieSize);
    int damage = roll + 3; // The 3 will be changed to somthing better later on
    return damage;
}

// Process the attack for a combatant
void Combat::processAttack(Character& attacker, Character& defender, int attackRoll, int defenseRoll, const std::string& attackType) {
    if (attackRoll >= defenseRoll) {
        int damage = calculateDamage(attacker, attackType);
        defender.setHp(defender.getHp() - damage);
        std::cout << attacker.getName() << " hits! " << defender.getName() << " takes " << damage << " damage." << std::endl;
    }
    else {
        std::cout << attacker.getName() << " misses!" << std::endl;
    }
}

// Apply damage to a Character
void Combat::applyDamage(Character& target, int damage) {
    target.setHp(target.getHp() - damage);
}