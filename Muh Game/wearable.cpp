#include "Wearable.h"

Wearable::Wearable(const std::string& desc, int val, int qty, int defense, const std::string& mat, const std::string& qual)
    : Item(desc, val, qty), defenseBonus(defense), material(mat), quality(qual) {}

// Getters
int Wearable::getDefenseBonus() const {
    return defenseBonus;
}

std::string Wearable::getMaterial() const {
    return material;
}

std::string Wearable::getQuality() const {
    return quality;
}