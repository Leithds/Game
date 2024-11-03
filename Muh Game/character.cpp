#pragma once
#include "Character.h"
#include "Inventory.h"
#include "stance.h"
#include "AttackStance.h"
#include "DefenseStance.h"
#include <iostream>
#include <memory>

class AttackStance; // Forward declaration
class DefenseStance; // Forward declaration

// Constructor
Character::Character(const std::string& name, const std::string& clan, const std::string& species)
    : name(name), clan(clan), species(species),
    str(0), dex(0), con(0),
    will(0), foc(0), res(0),
    level(1), exp(0), realm(0), hp(100), relation_points(0) {
    initializeStarterStances();
}

// Getters and Setters Implementation

// Labels
std::string Character::getName() const { return name; }
void Character::setName(const std::string& n) { name = n; }
std::string Character::getClan() const { return clan; }
void Character::setClan(const std::string& c) { clan = c; }
std::string Character::getSpecies() const { return species; }
void Character::setSpecies(const std::string& s) { species = s; }

// Physical Stats
int Character::getStr() const { return str; }
void Character::setStr(int s) { str = s; }
int Character::getDex() const { return dex; }
void Character::setDex(int d) { dex = d; }
int Character::getCon() const { return con; }
void Character::setCon(int c) { con = c; }

// Mental Stats
int Character::getWill() const { return will; }
void Character::setWill(int w) { will = w; }
int Character::getFocus() const { return foc; }
void Character::setFocus(int f) { foc = f; }
int Character::getResilience() const { return res; }
void Character::setResilience(int r) { res = r; }

// Core Stats
int Character::getLevel() const { return level; }
void Character::setLevel(int l) { level = l; }
int Character::getExp() const { return exp; }
void Character::setExp(int e) { exp = e; }
int Character::getRealm() const { return realm; }
void Character::setRealm(int r) { realm = r; }
int Character::getHp() const { return hp; }
void Character::setHp(int h) { hp = h; }
int Character::getRelationPoints() const { return relation_points; }
void Character::setRelationPoints(int rp) { relation_points = rp; }

// Level Up and Experience
void Character::addExperience(int amount) { // example amount of exp. I need to figure this out later
    exp += amount;
    std::cout << name << " gains " << amount << " EXP.\n";
    while (exp >= 100) {
        exp -= 100;
        levelUp();
    }
}

void Character::levelUp() { // example level up, I want the player to choose what to level up from a point pool they get when they level up
    level++;
    str += 2; dex += 2; con += 2;
    will += 1; foc += 1; res += 1;
    hp += 20;
    std::cout << name << " has leveled up to Level " << level << "!\n";
}

// HP Management
void Character::heal(int amount) {
    hp += amount;
    std::cout << name << " heals " << amount << " HP.\n";
}

// Skills Management
std::vector<std::string> Character::getAttackSkills() const { return attack_skills; }
void Character::addAttackSkill(const std::string& skill) { attack_skills.push_back(skill); }
std::vector<std::string> Character::getDefenseSkills() const { return defense_skills; }
void Character::addDefenseSkill(const std::string& skill) { defense_skills.push_back(skill); }
std::vector<std::string> Character::getWeaponSkills() const { return weapon_skills; }
void Character::addWeaponSkill(const std::string& skill) { weapon_skills.push_back(skill); }
std::vector<std::string> Character::getStyleSkills() const { return style_skills; }
void Character::addStyleSkill(const std::string& skill) { style_skills.push_back(skill); }

// Stance Management
void Character::addAttackStance(std::shared_ptr<AttackStance> stance) {
    attackStancesKnown.push_back(stance);
}

void Character::equipAttackStance(std::shared_ptr<AttackStance> stance) {
    attackStancesEquipped.push_back(stance);
}

void Character::addDefenseStance(std::shared_ptr<DefenseStance> stance) {
    defenseStancesKnown.push_back(stance);
}

void Character::equipDefenseStance(std::shared_ptr<DefenseStance> stance) {
    defenseStancesEquipped.push_back(stance);
}

const std::vector<std::shared_ptr<AttackStance>>& Character::getAttackStancesEquipped() const {
    return attackStancesEquipped;
}

const std::vector<std::shared_ptr<DefenseStance>>& Character::getDefenseStancesEquipped() const {
    return defenseStancesEquipped;
}

const std::vector<std::shared_ptr<AttackStance>>& Character::getAttackStancesKnown() const {
    return attackStancesKnown;
}

const std::vector<std::shared_ptr<DefenseStance>>& Character::getDefenseStancesKnown() const {
    return defenseStancesKnown;
}

// Initialize the stances
void Character::initializeStarterStances() {
    // Attack Stances
    attackStancesKnown.push_back(std::make_shared<AttackStance>("Caressing Strikes", Stance::isTag::Softness, Stance::hasTag::Softness, "Constitution", "Dexterity"));
    attackStancesKnown.push_back(std::make_shared<AttackStance>("Rapid Assault", Stance::isTag::Speed, Stance::hasTag::Speed, "Dexterity", "Strength"));
    attackStancesKnown.push_back(std::make_shared<AttackStance>("Furious Assault", Stance::isTag::Strength, Stance::hasTag::Strength, "Strength", "Constitution"));
    attackStancesKnown.push_back(std::make_shared<AttackStance>("Pinpoint Assault", Stance::isTag::Precision, Stance::hasTag::Precision, "Strength", "Dexterity"));
    attackStancesKnown.push_back(std::make_shared<AttackStance>("Flowing Strikes", Stance::isTag::Fluidity, Stance::hasTag::Fluidity, "Constitution", "Strength"));
    attackStancesKnown.push_back(std::make_shared<AttackStance>("Feinting Strikes", Stance::isTag::Deception, Stance::hasTag::Deception, "Dexterity", "Constitution"));

    // Defense Stances
    defenseStancesKnown.push_back(std::make_shared<DefenseStance>("Gliding Steps", Stance::isTag::Softness, Stance::hasTag::Softness, "Constitution", "Dexterity"));
    defenseStancesKnown.push_back(std::make_shared<DefenseStance>("Instant Guard", Stance::isTag::Speed, Stance::hasTag::Speed, "Dexterity", "Strength"));
    defenseStancesKnown.push_back(std::make_shared<DefenseStance>("Sturdy Guard", Stance::isTag::Strength, Stance::hasTag::Strength, "Strength", "Constitution"));
    defenseStancesKnown.push_back(std::make_shared<DefenseStance>("Precision Parry", Stance::isTag::Precision, Stance::hasTag::Precision, "Strength", "Dexterity"));
    defenseStancesKnown.push_back(std::make_shared<DefenseStance>("Seamless Transition", Stance::isTag::Fluidity, Stance::hasTag::Fluidity, "Constitution", "Strength"));
    defenseStancesKnown.push_back(std::make_shared<DefenseStance>("False Opening", Stance::isTag::Deception, Stance::hasTag::Deception, "Dexterity", "Constitution"));
}

// Get Stats for Stances
int Character::getStatFromStance(const std::string& statName) const {
    if (statName == "Str") {
        return str;  // Return the strength value
    }
    else if (statName == "Dex") {
        return dex;  // Return the dexterity value
    }
    else if (statName == "Con") {
        return con;  // Return the constitution value
    }
    // Add more cases as needed for additional stats

    return 0;  // Default return value if no match found
}

// Equipment Management
void Character::equipWeapon(const std::string& weapon) { equipped_weapons.push_back(weapon); }
void Character::unequipWeapon() { if (!equipped_weapons.empty()) equipped_weapons.pop_back(); }
void Character::addEquipment(const std::string& equipment) { equipment_slots.push_back(equipment); }
void Character::removeEquipment(const std::string& equipment) {
    auto it = std::find(equipment_slots.begin(), equipment_slots.end(), equipment);
    if (it != equipment_slots.end()) equipment_slots.erase(it);
}

// Combat-Related Methods
int Character::draw() const { return dex + foc; }
int Character::damageDie() const { return 6 + str; } // example for now, I want to call the instance of a weapon to fully get its damage