#include "Inventory.h"

// Add a weapon to the inventory
void Inventory::addWeapon(const std::string& weapon) {
    weapons.push_back(weapon);
}

// Add a consumable to the inventory
void Inventory::addConsumable(const std::string& consumable) {
    consumables.push_back(consumable);
}

// Add a miscellaneous item to the inventory
void Inventory::addWearable(const std::string& item) {
    wearables.push_back(item);
}

// Remove a weapon from the inventory
bool Inventory::removeWeapon(const std::string& weapon) {
    auto it = std::find(weapons.begin(), weapons.end(), weapon);
    if (it != weapons.end()) {
        weapons.erase(it);
        return true;
    }
    return false;
}

// Remove a consumable from the inventory
bool Inventory::removeConsumable(const std::string& consumable) {
    auto it = std::find(consumables.begin(), consumables.end(), consumable);
    if (it != consumables.end()) {
        consumables.erase(it);
        return true;
    }
    return false;
}

// Remove a wearable item from the inventory
bool Inventory::removeWearable(const std::string& item) {
    auto it = std::find(wearables.begin(), wearables.end(), item);
    if (it != wearables.end()) {
        wearables.erase(it);
        return true;
    }
    return false;
}

// List all weapons in the inventory
void Inventory::listWeapons() const {
    std::cout << "Weapons in inventory:\n";
    for (const auto& weapon : weapons) {
        std::cout << "- " << weapon << std::endl;
    }
}

// List all consumables in the inventory
void Inventory::listConsumables() const {
    std::cout << "Consumables in inventory:\n";
    for (const auto& consumable : consumables) {
        std::cout << "- " << consumable << std::endl;
    }
}

// List all wearable items in the inventory
void Inventory::listWearable() const {
    std::cout << "Miscellaneous items in inventory:\n";
    for (const auto& item : wearables) {
        std::cout << "- " << item << std::endl;
    }
}

// Check if a weapon is in the inventory
bool Inventory::hasWeapon(const std::string& weapon) const {
    return std::find(weapons.begin(), weapons.end(), weapon) != weapons.end();
}

// Check if a consumable is in the inventory
bool Inventory::hasConsumable(const std::string& consumable) const {
    return std::find(consumables.begin(), consumables.end(), consumable) != consumables.end();
}

// Check if a wearable item is in the inventory
bool Inventory::hasWearable(const std::string& item) const {
    return std::find(wearables.begin(), wearables.end(), item) != wearables.end();
}