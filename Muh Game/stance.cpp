#include "Stance.h"

// Constructor
Stance::Stance(const std::string& name, isTag type, hasTag countsAsType, const std::string& primaryStat, const std::string& secondaryStat)
    : name(name), tagType(type), hasTagType(countsAsType), primaryStat(primaryStat), secondaryStat(secondaryStat) {}

// Getters
std::string Stance::getName() const { return name; }
Stance::isTag Stance::getIsTag() const { return tagType; }
Stance::hasTag Stance::getHasTag() const { return hasTagType; }
std::string Stance::getPrimaryStat() const { return primaryStat; }
std::string Stance::getSecondaryStat() const { return secondaryStat; }