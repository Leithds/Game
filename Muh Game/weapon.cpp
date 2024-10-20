#include "Weapon.h"

// Constructor
Weapon::Weapon(const std::string& desc, int val, int qty, int die, const std::string& mat, const std::string& qual)
    : Item(desc, val, qty), damageDie(die), material(mat), quality(qual) {}

// Getters
int Weapon::getDamageDie() const {
    return damageDie;
}

std::string Weapon::getMaterial() const {
    return material;
}

std::string Weapon::getQuality() const {
    return quality;
}