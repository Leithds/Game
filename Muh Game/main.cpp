#include <SFML/Graphics.hpp>
#include "MainMenuState.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Main Menu");

    GameState* currentState = new MainMenuState();

    while (window.isOpen()) {
        currentState->handleInput(window);
        currentState->update();
        currentState->render(window);

        // Transition to the next state if needed (not implemented here)
        GameState* nextState = currentState->nextState();
        if (nextState != nullptr) {
            delete currentState;
            currentState = nextState;
        }
    }

    delete currentState; // Clean up
    return 0;
}