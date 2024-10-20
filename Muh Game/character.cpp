#include "Character.h"

// Constructor implementation
Character::Character(const std::string& name,
    const std::string& clan,
    const std::string& species)
    : name(name), clan(clan), species(species),
    str(0), dex(0), con(0),
    will(0), foc(0), res(0),
    level(1), exp(0), realm(0), hp(100), relation_points(0) {}

// Getters and Setters

// Labels
std::string Character::getName() const {
    return name;
}

void Character::setName(const std::string& n) {
    name = n;
}

std::string Character::getClan() const {
    return clan;
}

void Character::setClan(const std::string& c) {
    clan = c;
}

std::string Character::getSpecies() const {
    return species;
}

void Character::setSpecies(const std::string& s) {
    species = s;
}

// Physical Stats
int Character::getStr() const {
    return str;
}

void Character::setStr(int s) {
    str = s;
}

int Character::getDex() const {
    return dex;
}

void Character::setDex(int d) {
    dex = d;
}

int Character::getCon() const {
    return con;
}

void Character::setCon(int c) {
    con = c;
}

// Mental Stats
int Character::getWill() const {
    return will;
}

void Character::setWill(int w) {
    will = w;
}

int Character::getFocus() const {
    return foc;
}

void Character::setFocus(int f) {
    foc = f;
}

int Character::getResilience() const {
    return res;
}

void Character::setResilience(int r) {
    res = r;
}

// Core Stats
int Character::getLevel() const {
    return level;
}

void Character::setLevel(int l) {
    level = l;
}

int Character::getExp() const {
    return exp;
}

void Character::setExp(int e) {
    exp = e;
}

int Character::getRealm() const {
    return realm;
}

void Character::setRealm(int r) {
    realm = r;
}

int Character::getHp() const {
    return hp;
}

void Character::setHp(int h) {
    hp = h;
}

int Character::getRelationPoints() const {
    return relation_points;
}

void Character::setRelationPoints(int rp) {
    relation_points = rp;
}

// Level Up and Experience
void Character::addExperience(int amount) {
    exp += amount;
    std::cout << name << " gains " << amount << " EXP.\n";
    // Example: Level up at 100 EXP (I need to add logic for inceasing the exp amount or some other method like this)
    while (exp >= 100) {
        exp -= 100;
        levelUp();
    }
}

void Character::levelUp() {
    level++;
    // Example: Increase stats by a fixed amount (I'm not sure if I want the player to pick the stats they raise or if they raise those though ingame actions and levelup give set things)
    // easy to see standin for now
    str += 2;
    dex += 2;
    con += 2;
    will += 1;
    foc += 1;
    res += 1;
    hp += 20; // Increase HP on level up
    std::cout << name << " has leveled up to Level " << level << "!\n";
    std::cout << "Stats increased: Strength, Dexterity, Constitution by 2 each; Will, Focus, Resilience by 1 each.\n";
}

// HP Management
void Character::heal(int amount) {
    hp += amount;
    std::cout << name << " heals " << amount << " HP.\n";
    // I need to make sure this does not go over their max amount
    // or I need to add a mothed so only some things can "over-heal"
}

// Inventory Management
void Character::equipWeapon(const std::string& weapon) {
    inventory.equipWeapon(weapon);
}

void Character::unequipWeapon() {
    inventory.unequipWeapon();
}

void Character::useConsumable(const std::string& consumable) {
    inventory.useConsumable(consumable);
}

void Character::listInventory() const {
    inventory.listAllItems();
}

// Skills Management
// Weapon Skills
std::vector<std::string> Character::getWeaponSkills() const {
    return weapon_skills;
    // I'll need to add a way to get a skill needed not jus the whole list so bonues can be applied
}

void Character::addWeaponSkill(const std::string& skill) {
    weapon_skills.push_back(skill);
}

// Defense Skills
std::vector<std::string> Character::getDefenseSkills() const {
    return defense_skills;
    // I'll need to add a way to get a skill needed not jus the whole list so bonues can be applied
}

void Character::addDefenseSkill(const std::string& skill) {
    defense_skills.push_back(skill);
}

// Other Skills
std::vector<std::string> Character::getMysticSkills() const {
    return mystic_skills;
    // I'll need to add a way to get a skill needed not jus the whole list so bonues can be applied
}

void Character::addMysticSkill(const std::string& skill) {
    mystic_skills.push_back(skill);
}

// Moves Management
// Attack Moves
std::vector<std::string> Character::getAttackMoves() const {
    return attack_moves;
}

void Character::addAttackMove(const std::string& move) {
    attack_moves.push_back(move);
}

// Defense Moves
std::vector<std::string> Character::getDefenseMoves() const {
    return defense_moves;
}

void Character::addDefenseMove(const std::string& move) {
    defense_moves.push_back(move);
}

// Mystic Moves
std::vector<std::string> Character::getMysticMoves() const {
    return mystic_moves;
}

void Character::addMysticMove(const std::string& move) {
    mystic_moves.push_back(move);
}

// Combat-Related Methods
// Draw method
int Character::draw() const {
    // Example: Base bonus from Dexterity and Focus
    // I'll probably change this to somthing other than this for balance
    return dex + foc;
}

// Damge Die method
int Character::damageDie() const {
    // Get the die rolled for that weapon
    // Placeholder for now, this should look at the equipped weapon's damage die
    int weapon_die = 6;  // would look somthing like this I think int weapon_die = equipped_weapon.damage_die (I think the equipped_weapon class would hanndle any skills that may adjust the damage die, so that that modifer is nor checked every loop)
}