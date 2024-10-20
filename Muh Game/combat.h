#ifndef COMBAT_H
#define COMBAT_H

#include <string>
#include <utility>
#include <unordered_map>
#include "Character.h"
#include "Roll.h"

// Combat class declaration
class Combat {
public:
    // Main combat loop
    void combatLoop(Character& combatantA, Character& combatantB);

private:
    // Function to get the specified stat for a combatant
    int getStat(const Character& combatant, const std::string& statName);

    // Unified function to get stats for attack or defense
    int getStats(Character& combatant, const std::string& moveChoice, bool isAttack);

    // Get attack and defense choices for a combatant
    std::pair<std::string, std::string> getChoices(Character& combatant);

    // Determine which combatant acts first based on initiative
    std::string determineFirst(Character& combatantA, Character& combatantB);

    // Calculate the damage for the attack
    int calculateDamage(const Character& attacker, const std::string& attackType);

    // Process the attack for a combatant
    void processAttack(Character& attacker, Character& defender, int attackRoll, int defenseRoll, const std::string& attackType);

    // Apply damage to a Character
    void applyDamage(Character& target, int damage);

    // Roll class instance for dice rolling
    Roll dice;

    // Maps for attack and defense moves
    std::unordered_map<std::string, std::pair<std::string, std::string>> attackMoves;
    std::unordered_map<std::string, std::pair<std::string, std::string>> defenseMoves;
};

#endif // COMBAT_H