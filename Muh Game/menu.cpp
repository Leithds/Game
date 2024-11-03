#include "menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("fonts/PressStart2P-Regular.ttf")) {
        std::cerr << "Error loading font\n";
    }

    // Initialize menu items
    menuItems.push_back(sf::Text("Start", font, 50));
    menuItems.push_back(sf::Text("Exit", font, 50));

    // Position text items centered horizontally and spaced vertically
    for (size_t i = 0; i < menuItems.size(); ++i) {
        menuItems[i].setPosition(
            (width - menuItems[i].getGlobalBounds().width) / 2,
            height / (menuItems.size() + 1) * (i + 1)
        );
    }

    // Highlight the first item initially
    selectedItemIndex = 0;
    menuItems[selectedItemIndex].setFillColor(sf::Color::Red); // Highlight color
}

void Menu::draw(sf::RenderWindow& window) {
    for (size_t i = 0; i < menuItems.size(); ++i) {
        window.draw(menuItems[i]); // Draw only the text
    }
}

void Menu::moveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if (selectedItemIndex + 1 < menuItems.size()) {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int Menu::getSelectedOption() const {
    return selectedItemIndex;
}
