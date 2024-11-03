#pragma once

#include <memory>
#include <string>
#include "Character.h"
#include "GameState.h"

class CharacterCreationState : public GameState {
public:
    CharacterCreationState();

    void handleInput(sf::RenderWindow& window) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    GameState* nextState() override;

    void createCharacter();

private:
    std::shared_ptr<Character> character;
    int selectedOption;
};