//
// Created by thibaultcampagne on 31/12/23.
//

#include "eventEngine.h"

sf::Event& EventEngine::getEvent() {
    return event;
}

void EventEngine::addKeyPressed(sf::Keyboard::Key keyboard, const std::function<void()>& function) {
    keyPressedMap.insert(std::make_pair(keyboard, function));
    keyStatesMap.insert(std::make_pair(keyboard, false));
}

void EventEngine::addMouseButtonPressed(sf::Mouse::Button mouse, const std::function<void()>& function) {
    mouseButtonPressedMap.insert(std::make_pair(mouse, function));
}

void EventEngine::addMouseMoved(const std::string& nameEntity, const std::function<void()>& function) {
    mouseMovedMap.insert(std::make_pair(nameEntity, function));
}

std::map<sf::Keyboard::Key, std::function<void()>>& EventEngine::getKeyPressedMap() {
    return keyPressedMap;
}

std::map<sf::Mouse::Button, std::function<void()>>& EventEngine::getMouseButtonPressedMap() {
    return mouseButtonPressedMap;
}

std::map<std::string, std::function<void()>>& EventEngine::getMouseMovedMap() {
    return mouseMovedMap;
}

std::map<sf::Keyboard::Key, bool>& EventEngine::getKeyStatesMap() {
    return keyStatesMap;
}

void EventEngine::setKeyStatesMap(sf::Keyboard::Key key) {
    keyStatesMap.insert(std::make_pair(key, true));
}
