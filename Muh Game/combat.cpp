#include "combat.h"
#include "Character.h"
#include "Roll.h"
#include <iostream>
#include <unordered_map>
#include <algorithm>

// Initialize the Roll class
Roll dice;

// Constructor for Combat class to initialize the attack and defense moves
Combat::Combat() {
    // Attack and defense move definitions
    attackMoves = {
        {"strong", {"con", "str"}},
        {"fast", {"dex", "str"}},
        {"accurate", {"con", "dex"}}
    };

    defenseMoves = {
        {"dodge", {"dex", "con"}},
        {"block", {"str", "con"}},
        {"parry", {"dex", "str"}}
    };
}

// Function to convert input to lowercase for normalization
std::string toLowerCase(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Helper function to trim leading and trailing spaces
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

// Function to get the specified stat for a combatant
int Combat::getStat(const Character& combatant, const std::string& statName) {
    if (statName == "con") return combatant.getCon();
    else if (statName == "dex") return combatant.getDex();
    else if (statName == "str") return combatant.getStr();
    return 0; // Default case
}

// Unified function to get stats for attack or defense
int Combat::getStats(Character& combatant, std::string moveChoice, bool isAttack) {
    moveChoice = toLowerCase(moveChoice);  // Normalize input
    int stat1 = 0, stat2 = 0;

    if (isAttack && attackMoves.find(moveChoice) != attackMoves.end()) {
        std::pair<std::string, std::string> stats = attackMoves[moveChoice];
        stat1 = getStat(combatant, stats.first);
        stat2 = getStat(combatant, stats.second);
        return stat1 + stat2 + dice.roll(20); // Add roll for attacks
    }
    else if (!isAttack && defenseMoves.find(moveChoice) != defenseMoves.end()) {
        std::pair<std::string, std::string> stats = defenseMoves[moveChoice];
        stat1 = getStat(combatant, stats.first);
        stat2 = getStat(combatant, stats.second);
        return stat1 + stat2 + 10; // No roll for defense (static bonus)
    }

    return 0; // Invalid move case
}

// Main combat loop
void Combat::combatLoop(Character& combatantA, Character& combatantB) {
    int round = 0;
    while (combatantA.getHp() > 0 && combatantB.getHp() > 0) {
        round++;
        std::cout << "=== Round " << round << " ===" << std::endl;

        std::pair<std::string, std::string> choicesA = getChoices(combatantA);
        std::pair<std::string, std::string> choicesB = getChoices(combatantB);
        std::string attackA = toLowerCase(choicesA.first);
        std::string defenseA = toLowerCase(choicesA.second);
        std::string attackB = toLowerCase(choicesB.first);
        std::string defenseB = toLowerCase(choicesB.second);

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

    // Validate attack choice
    while (true) {
        std::cout << combatant.getName() << ", choose your attack action (Strong, Fast, Accurate): ";
        std::getline(std::cin, attack); // Use getline to avoid leftover characters

        // Trim whitespace and normalize input to lowercase
        attack = toLowerCase(trim(attack));

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
        std::getline(std::cin, defense); // Use getline to avoid leftover characters

        // Trim whitespace and normalize input to lowercase
        defense = toLowerCase(trim(defense));

        if (defenseMoves.find(defense) != defenseMoves.end()) {
            break; // Valid choice
        }
        else {
            std::cout << "Invalid defense choice! Please choose Dodge, Block, or Parry." << std::endl;
        }
    }

    return { attack, defense };
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
int Combat::calculateDamage(const Character& attacker, const std::string& attackType) {
    int dieSize = attacker.damageDie();
    int roll = dice.roll(dieSize);
    int damage = roll + 3; // Example bonus, adjust later
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