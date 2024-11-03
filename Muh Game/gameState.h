#pragma once
#include <SFML/Graphics.hpp>

class GameState {
public:
    virtual ~GameState() {}

    virtual void handleInput(sf::RenderWindow& window) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual GameState* nextState() = 0; // Declaration only
};