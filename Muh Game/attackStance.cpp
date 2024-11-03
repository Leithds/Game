#include "AttackStance.h"
#include "character.h"
#include <iostream>

// Constructor
AttackStance::AttackStance(const std::string& name, Stance::isTag type, Stance::hasTag countsAsType, const std::string& primaryStat, const std::string& secondaryStat)
    : Stance(name, type, countsAsType, primaryStat, secondaryStat) {}

// Display attack information
void AttackStance::displayAttackInfo() const {
    std::cout << "The name of this Technique is: " << getName() << std::endl;
    std::cout << "This Technique uses isTag: " << static_cast<int>(getIsTag()) << std::endl;
    std::cout << "This Technique also counts as having hasTag: " << static_cast<int>(getHasTag()) << std::endl;
    std::cout << "Primary Stat: " << getPrimaryStat() << ", Secondary Stat: " << getSecondaryStat() << std::endl;
}

// Determine if this attack stance has advantage
bool AttackStance::determineAdvantage(const DefenseStance& opponent) const {
    return hasAdvantage(opponent.getIsTag(), opponent.getHasTag());
}

// Advantage calculation logic
bool AttackStance::hasAdvantage(Stance::isTag opponentIsTag, Stance::hasTag opponentHasTag) const {
    switch (getIsTag()) {
    case Stance::isTag::Softness:
        return (opponentIsTag == Stance::isTag::Strength || opponentIsTag == Stance::isTag::Precision);
    case Stance::isTag::Speed:
        return (opponentIsTag == Stance::isTag::Softness || opponentIsTag == Stance::isTag::Deception);
    case Stance::isTag::Strength:
        return (opponentIsTag == Stance::isTag::Fluidity || opponentIsTag == Stance::isTag::Speed);
    case Stance::isTag::Fluidity:
        return (opponentIsTag == Stance::isTag::Deception || opponentIsTag == Stance::isTag::Softness);
    case Stance::isTag::Deception:
        return (opponentIsTag == Stance::isTag::Strength || opponentIsTag == Stance::isTag::Precision);
    case Stance::isTag::Precision:
        return (opponentIsTag == Stance::isTag::Speed || opponentIsTag == Stance::isTag::Fluidity);
    default:
        return false;
    }
}