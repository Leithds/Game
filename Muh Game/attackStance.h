#pragma once

#include "Stance.h"
#include "DefenseStance.h"
#include <string>

class AttackStance : public Stance {
public:
    // Constructor
    AttackStance(const std::string& name, Stance::isTag type, Stance::hasTag countsAsType, const std::string& primaryStat, const std::string& secondaryStat);

    // Display attack information
    void displayAttackInfo() const;

    // Determine if this attack stance has advantage over the opponent
    bool determineAdvantage(const DefenseStance& opponent) const;

private:
    // Advantage calculation logic
    bool hasAdvantage(Stance::isTag opponentIsTag, Stance::hasTag opponentHasTag) const;
};