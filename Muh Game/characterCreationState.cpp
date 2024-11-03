#include "characterCreationState.h"
#include <iostream>

CharacterCreationState::CharacterCreationState()
    : selectedOption(0), character(std::make_shared<Character>()) {
}

void CharacterCreationState::createCharacter() {
    std::string name, clan, species;

    // Get character details from the player
    std::cout << "Enter character name: ";
    std::getline(std::cin, name);
    std::cout << "Enter character clan: ";
    std::getline(std::cin, clan);
    std::cout << "Enter character species: ";
    std::getline(std::cin, species);

    // Create the character with the provided details
    character = std::make_shared<Character>(name, clan, species);

    // Display the available attack stances
    std::cout << "Select 4 Attack Stances:\n";
    for (size_t i = 0; i < character->getAttackStancesKnown().size(); ++i) {
        std::cout << i + 1 << ". " << character->getAttackStancesKnown()[i]->getName() << "\n";
    }

    // Selecting attack stances
    for (int i = 0; i < 4; ++i) {
        int stanceIndex;
        std::cout << "Choose attack stance " << (i + 1) << ": ";
        std::cin >> stanceIndex;
        if (stanceIndex > 0 && stanceIndex <= character->getAttackStancesKnown().size()) {
            character->equipAttackStance(character->getAttackStancesKnown()[stanceIndex - 1]);
        }
    }

    // Display the available defense stances
    std::cout << "Select 4 Defense Stances:\n";
    for (size_t i = 0; i < character->getDefenseStancesKnown().size(); ++i) {
        std::cout << i + 1 << ". " << character->getDefenseStancesKnown()[i]->getName() << "\n";
    }

    // Selecting defense stances
    for (int i = 0; i < 4; ++i) {
        int stanceIndex;
        std::cout << "Choose defense stance " << (i + 1) << ": ";
        std::cin >> stanceIndex;
        if (stanceIndex > 0 && stanceIndex <= character->getDefenseStancesKnown().size()) {
            character->equipDefenseStance(character->getDefenseStancesKnown()[stanceIndex - 1]);
        }
    }

    // Confirmation message
    std::cout << "Character created successfully!\n";
    std::cout << "Character Name: " << character->getName() << "\n";
    std::cout << "Clan: " << character->getClan() << "\n";
    std::cout << "Species: " << character->getSpecies() << "\n";
}

void CharacterCreationState::handleInput(sf::RenderWindow& window) {
    
}

void CharacterCreationState::update() {
    
}

void CharacterCreationState::render(sf::RenderWindow& window) {
    
}

GameState* CharacterCreationState::nextState() {
    return nullptr;
}