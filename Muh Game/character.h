#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Inventory.h"
#include "Stance.h"
#include "AttackStance.h"
#include "DefenseStance.h"

class Character {
private:
    // Labels
    std::string name;
    std::string clan;
    std::string species;

    // Physical Stats
    int str;  // Strength
    int dex;  // Dexterity
    int con;  // Constitution

    // Mental Stats
    int will; // Will
    int foc;  // Focus
    int res;  // Resilience

    // Core Stats
    int level;
    int exp;
    int realm;
    int hp;
    int relation_points;

    // Skill Types
    std::vector<std::string> attack_skills;
    std::vector<std::string> defense_skills;
    std::vector<std::string> weapon_skills;
    std::vector<std::string> style_skills;
    
    // Vectors for managing stances
    std::vector<std::shared_ptr<AttackStance>> attackStancesKnown;
    std::vector<std::shared_ptr<AttackStance>> attackStancesEquipped;
    std::vector<std::shared_ptr<DefenseStance>> defenseStancesKnown;
    std::vector<std::shared_ptr<DefenseStance>> defenseStancesEquipped;

    // Inventory & Equipment
    Inventory inventory;
    std::vector<std::string> equipped_weapons;  // Primary, secondary, etc.
    std::vector<std::string> equipment_slots;   // Helmet, armor, etc.

public:
    // Constructor
    Character(const std::string& name, const std::string& clan, const std::string& species);

    void initializeStarterStances();

    // Getters and Setters

    // Labels
    std::string getName() const;
    void setName(const std::string& n);
    std::string getClan() const;
    void setClan(const std::string& c);
    std::string getSpecies() const;
    void setSpecies(const std::string& s);

    // Physical Stats
    int getStr() const;
    void setStr(int s);
    int getDex() const;
    void setDex(int d);
    int getCon() const;
    void setCon(int c);

    // Mental Stats
    int getWill() const;
    void setWill(int w);
    int getFocus() const;
    void setFocus(int f);
    int getResilience() const;
    void setResilience(int r);

    // Core Stats
    int getLevel() const;
    void setLevel(int l);
    int getExp() const;
    void setExp(int e);
    int getRealm() const;
    void setRealm(int r);
    int getHp() const;
    void setHp(int h);
    int getRelationPoints() const;
    void setRelationPoints(int rp);

    // Level Up and Experience
    void addExperience(int amount);
    void levelUp();

    // HP Management
    void heal(int amount);

    // Skills Management
    std::vector<std::string> getAttackSkills() const;
    void addAttackSkill(const std::string& skill);
    std::vector<std::string> getDefenseSkills() const;
    void addDefenseSkill(const std::string& skill);
    std::vector<std::string> getWeaponSkills() const;
    void addWeaponSkill(const std::string& skill);
    std::vector<std::string> getStyleSkills() const;
    void addStyleSkill(const std::string& skill);

    // Get Stats for Stances
    int getStatFromStance(const std::string& statName) const;

    // Stance Management
    void addAttackStance(std::shared_ptr<AttackStance> stance);
    void equipAttackStance(std::shared_ptr<AttackStance> stance);
    void addDefenseStance(std::shared_ptr<DefenseStance> stance);
    void equipDefenseStance(std::shared_ptr<DefenseStance> stance);

    const std::vector<std::shared_ptr<AttackStance>>& getAttackStancesEquipped() const;
    const std::vector<std::shared_ptr<DefenseStance>>& getDefenseStancesEquipped() const;
    const std::vector<std::shared_ptr<AttackStance>>& getAttackStancesKnown() const;
    const std::vector<std::shared_ptr<DefenseStance>>& getDefenseStancesKnown() const;

    // Equipment Management
    void equipWeapon(const std::string& weapon);
    void unequipWeapon();
    void addEquipment(const std::string& equipment);
    void removeEquipment(const std::string& equipment);

    // Combat-Related Methods
    int draw() const;
    int damageDie() const;
};