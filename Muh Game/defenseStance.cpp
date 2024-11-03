#include "DefenseStance.h"

// Constructor
DefenseStance::DefenseStance(const std::string& name, Stance::isTag type, Stance::hasTag countsAsType, const std::string& primaryStat, const std::string& secondaryStat)
    : Stance(name, type, countsAsType, primaryStat, secondaryStat) {}

// Damage mitigation calculation
float DefenseStance::calculateMitigation(float incomingDamage) const {
    float mitigationFactor = 0.1f; // Example: 10% damage mitigation
    return incomingDamage * (1 - mitigationFactor);
}