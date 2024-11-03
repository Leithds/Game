#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

class GameEngine {
public:
    GameEngine();
    void run();

private:
    sf::RenderWindow window;
    GameState* currentState;

    void changeState(GameState* newState);
};