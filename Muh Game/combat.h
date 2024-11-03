#pragma once

#include <string>
#include <utility>
#include "Character.h"
#include "stance.h"
#include "attackStance.h"
#include "defenseStance.h"
#include "Roll.h"

// Combat class declaration
class Combat {
public:
    Combat();

    // Main combat loop
    void combatLoop(Character& combatantA, Character& combatantB);

private:
    // Unified function to get stats from stance
    int getStats(Character& combatant, const std::string& stanceName, bool isAttack);

    // Get attack and defense choices
    std::pair<std::string, std::string> getChoices(Character& combatant);

    // Determine which combatant acts first
    std::string determineFirst(Character& combatantA, Character& combatantB);

    // Calculate the damage
    int calculateDamage(const Character& attacker, const std::string& stanceType);

    // Process the attack
    void processAttack(Character& attacker, Character& defender, int attackRoll, int defenseRoll, const std::string& stanceType);

    // Roll class for dice rolling
    Roll dice;
};