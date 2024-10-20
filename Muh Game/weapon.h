#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "Item.h"

class Weapon : public Item {
private:
    int damageDie;
    std::string material;
    std::string quality;

public:
    // Constructor to initialize a Weapon object
    Weapon(const std::string& desc, int val, int qty, int die, const std::string& mat, const std::string& qual);

    // Getters for weapon attributes
    int getDamageDie() const;
    std::string getMaterial() const;
    std::string getQuality() const;
};

#endif 