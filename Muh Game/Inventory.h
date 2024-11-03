#pragma once

#include <string>
#include <vector>
#include <iostream>

class Inventory {
private:
    // Vectors to hold different types of items
    std::vector<std::string> weapons;
    std::vector<std::string> consumables;
    std::vector<std::string> wearables;

public:
    // Add items to the inventory
    void addWeapon(const std::string& weapon);
    void addConsumable(const std::string& consumable);
    void addWearable(const std::string& item);

    // Remove items from inventory
    bool removeWeapon(const std::string& weapon);
    bool removeConsumable(const std::string& consumable);
    bool removeWearable(const std::string& item);

    // List items in the inventory
    void listWeapons() const;
    void listConsumables() const;
    void listWearable() const;

    // Inventory Management Methods
    bool hasWeapon(const std::string& weapon) const;
    bool hasConsumable(const std::string& consumable) const;
    bool hasWearable(const std::string& item) const;
};