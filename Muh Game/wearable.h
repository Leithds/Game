#ifndef WEARABLE_H
#define WEARABLE_H

#include "Item.h"

class Wearable : public Item {
private:
    int defenseBonus;
    std::string material;
    std::string quality;

public:
    Wearable(const std::string& desc, int val, int qty, int defense, const std::string& mat, const std::string& qual);

    // Getters
    int getDefenseBonus() const;
    std::string getMaterial() const;
    std::string getQuality() const;
};

#endif // WEARABLE_H