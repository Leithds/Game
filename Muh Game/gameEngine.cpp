#include "GameEngine.h"
#include "MainMenuState.h"

GameEngine::GameEngine()
    : window(sf::VideoMode(800, 600), "My Game"), currentState(new MainMenuState()) {}

void GameEngine::run() {
    while (window.isOpen()) {
        currentState->handleInput(window);
        currentState->update();

        window.clear();
        currentState->render(window);
        window.display();

        GameState* nextState = currentState->nextState();
        if (nextState != nullptr) {
            changeState(nextState);
        }
    }
}

void GameEngine::changeState(GameState* newState) {
    delete currentState;
    currentState = newState;
}