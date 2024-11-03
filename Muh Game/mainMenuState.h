#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>

class CharacterCreationState; // Forward declaration

class MainMenuState : public GameState {
public:
    MainMenuState();
    void handleInput(sf::RenderWindow& window) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    GameState* nextState() override;

private:
    int selectedOption = 0;
    sf::Font font;
    sf::Text startText;
    sf::Text exitText;
};