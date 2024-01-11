//
// Created by thibaultcampagne on 31/12/23.
//

#include "eventEngine.h"

void EventEngine::addKeyPressed(sf::Keyboard::Key keyboard, std::function<void()> function) {
    keyPressedMap.insert(std::make_pair(keyboard, function));
}

void EventEngine::addMouseButtonPressed(sf::Mouse::Button mouse, std::function<void()> function) {
    mouseButtonPressedMap.insert(std::make_pair(mouse, function));
}

void EventEngine::addMouseMoved(std::string nameEntity, std::function<void()> function) {
    mouseMovedMap.insert(std::make_pair(nameEntity, function));
}
