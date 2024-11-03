#include "MainMenuState.h"
#include "CharacterCreationState.h"
#include <iostream>

MainMenuState::MainMenuState() : selectedOption(0) {  // Initialize selectedOption
    if (!font.loadFromFile("fonts/PressStart2P-Regular.ttf")) {
        std::cerr << "Error loading font\n";
        // Consider handling this more gracefully (e.g., fallback font)
    }

    startText.setFont(font);
    startText.setString("Start");
    startText.setCharacterSize(50);
    startText.setFillColor(sf::Color::Yellow);
    startText.setPosition(400, 300);

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(50);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(400, 400);
}

void MainMenuState::handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
            case sf::Keyboard::Up:
                selectedOption = (selectedOption - 1 + 2) % 2;
                break;
            case sf::Keyboard::Down:
                selectedOption = (selectedOption + 1) % 2;
                break;
            case sf::Keyboard::Enter:
                if (selectedOption == 0) {
                    std::cout << "Start Game Selected\n";
                }
                else if (selectedOption == 1) {
                    window.close();  // Exit
                }
                break;
            default:
                break;
            }
        }
    }
}

void MainMenuState::update() {
    if (selectedOption == 0) {
        startText.setFillColor(sf::Color::Yellow);
        exitText.setFillColor(sf::Color::White);
    }
    else {
        startText.setFillColor(sf::Color::White);
        exitText.setFillColor(sf::Color::Yellow);
    }
}

void MainMenuState::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(startText);
    window.draw(exitText);
    window.display();
}

GameState* MainMenuState::nextState() {
    if (selectedOption == 0) {
        return new characterCreationState();
    }
    else if (selectedOption == 1) {
        return nullptr;
    }
    return nullptr;
}