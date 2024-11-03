#pragma once

#include "Stance.h"
#include <string>

class DefenseStance : public Stance {
public:
    // Constructor
    DefenseStance(const std::string& name, Stance::isTag type, Stance::hasTag countsAsType, const std::string& primaryStat, const std::string& secondaryStat);

    // Damage mitigation calculation
    float calculateMitigation(float incomingDamage) const;
};