//
// Created by thibaultcampagne on 31/12/23.
//

#pragma once

#include "std.h"
#include "sfml.h"
#include "Sprite.h"

/**
 * @brief EventEngine class: EventEngine is a class that represents the event engine of the game.
 *
 * The EventEngine class manages the events of the game.
 */
class EventEngine {
private:
    std::map<sf::Keyboard::Key, std::function<void()>> keyPressedMap{}; ///< Map of the key pressed.
    std::map<sf::Mouse::Button, std::function<void()>> mouseButtonPressedMap{}; /// < Map of the button pressed.
    std::map<std::string, std::function<void()>> mouseMovedMap{}; /// < Map of the mouse moved.
    sf::Event event; ///< SFML Event.
public:
    /// @brief Default EventEngine constructor.
    /// @param void
    /// @return void
    EventEngine() = default;

    /// @brief EventEngine destructor.
    /// @param void
    /// @return void
    virtual ~EventEngine() = default;

    /// @brief init(): Initialize the EventEngine.
    /// @param void
    /// @return bool: True if the EventEngine is initialized, false otherwise.
    bool init() const {return true;}

    /// @brief getEvent(): Get the SFML Event.
    /// @param void
    /// @return sf::Event: The SFML Event.
    sf::Event& getEvent() {return event;}

    /// @brief addKeyPressed(): Add a key pressed to the map.
    /// @param keyboard: SFML Keyboard::Key of the key pressed.
    /// @param function: Function to execute when the key is pressed.
    /// @return void
    void addKeyPressed(sf::Keyboard::Key keyboard, std::function<void()> function);

    /// @brief addMouseButtonPressed(): Add a mouse button pressed to the map.
    /// @param mouse: SFML Mouse::Button of the mouse button pressed.
    /// @param function: Function to execute when the mouse button is pressed.
    /// @return void
    void addMouseButtonPressed(sf::Mouse::Button mouse, std::function<void()> function);

    /// @brief addMouseMoved(): Add a mouse moved to the map.
    /// @param nameEntity : Name of the Entity you want.
    /// @param function: Function to execute when the mouse moved on entity.
    /// @return void
    void addMouseMoved(std::string nameEntity, std::function<void()> function);

    /// @brief getKeyPressedMap(): Get the map of the key pressed.
    /// @param void
    /// @return std::map<sf::Keyboard::Key, std::function<void()>>: The map of the key pressed.
    std::map<sf::Keyboard::Key, std::function<void()>>& getKeyPressedMap() {return keyPressedMap;}

    /// @brief getMouseButtonPressedMap(): Get the map of the mouse button pressed.
    /// @param void
    /// @return std::map<sf::Mouse::Button, std::function<void()>>: The map of the mouse button pressed.
    std::map<sf::Mouse::Button, std::function<void()>>& getMouseButtonPressedMap() {return mouseButtonPressedMap;}

    /// @brief getMouseMovedPressedMap(): Get the map of the key pressed.
    /// @param void
    /// @return std::map<std::string, std::function<void()>>: The map of the mouse moved.
    std::map<std::string, std::function<void()>>& getMouseMovedMap() {return mouseMovedMap;}
};

