#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"

class Character {
private:
    // Labels
    std::string name;
    std::string clan;
    std::string species;

    // Physical Stats
    int str; // Strength
    int dex; // Dexterity
    int con; // Constitution

    // Mental Stats
    int will;// will (duh)
    int foc; // focus
    int res; // resilience

    // Core Stats
    int level;
    int exp;
    int realm;
    int hp;
    int relation_points;

    // Skills
    std::vector<std::string> weapon_skills;
    std::vector<std::string> defense_skills;
    std::vector<std::string> mystic_skills;

    // Moves Known
    std::vector<std::string> attack_moves;
    std::vector<std::string> defense_moves;
    std::vector<std::string> mystic_moves;

public:
    // Inventory class
    Inventory inventory;

    // Constructor
    Character(const std::string& name,
        const std::string& clan,
        const std::string& species);

    // Getters and setters

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

    // Inventory Management
    void equipWeapon(const std::string& weapon);
    void unequipWeapon();
    void useConsumable(const std::string& consumable);
    void listInventory() const;

    // Skills Management
    // Weapon Skills
    std::vector<std::string> getWeaponSkills() const;
    void addWeaponSkill(const std::string& skill);

    // Defense Skills
    std::vector<std::string> getDefenseSkills() const;
    void addDefenseSkill(const std::string& skill);

    // Mystic Skills
    std::vector<std::string> getMysticSkills() const;
    void addMysticSkill(const std::string& skill);

    // Moves Management
    // Attack Moves
    std::vector<std::string> getAttackMoves() const;
    void addAttackMove(const std::string& move);

    // Defense Moves
    std::vector<std::string> getDefenseMoves() const;
    void addDefenseMove(const std::string& move);

    // Mystic Moves
    std::vector<std::string> getMysticMoves() const;
    void addMysticMove(const std::string& move);

    // Combat-Related Methods
    // Draw method
    int draw() const;

    // Damage Die method
    int damageDie() const;
};

#endif // CHARACTER_H