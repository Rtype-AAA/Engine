//
// Created by thibaultcampagne on 31/12/23.
//

#ifndef R_TYPE_EVENTENGINE_H
#define R_TYPE_EVENTENGINE_H

#include <string>
#include <map>
#include <SFML/Window.hpp>
#include <functional>

class EventEngine {
private:
    std::map<sf::Keyboard::Key, std::function<void()>> keyPressedMap{};
    sf::Event event;
public:
    EventEngine() = default;

    virtual ~EventEngine() = default;

    bool init() const {return true;}

    sf::Event& getEvent() {return event;}

    void addKeyPressed(sf::Keyboard::Key keyboard, std::function<void()> function);
    std::map<sf::Keyboard::Key, std::function<void()>>& getKeyPressedMap() {return keyPressedMap;}
};


#endif //R_TYPE_EVENT_H
