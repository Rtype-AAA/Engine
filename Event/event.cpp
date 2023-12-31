//
// Created by thibaultcampagne on 31/12/23.
//

#include "event.h"

void EventEngine::addKeyPressed(sf::Keyboard::Key keyboard, std::function<void()> function) {
    keyPressedMap.insert(std::make_pair(keyboard, function));
}