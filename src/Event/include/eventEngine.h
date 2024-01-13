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
    std::map<sf::Keyboard::Key, bool> keyStatesMap{}; /// < Map of the key states.
    sf::Event event{}; ///< SFML Event.
public:
    /// @brief Default EventEngine constructor.
    /// @param void
    /// @return void
    EventEngine() = default;

    /// @brief EventEngine destructor.
    /// @param void
    /// @return void
    virtual ~EventEngine() = default;

    /// @brief getEvent(): Get the SFML Event.
    /// @param void
    /// @return sf::Event: The SFML Event.
    sf::Event& getEvent();

    /// @brief addKeyPressed(): Add a key pressed to the map.
    /// @param keyboard: SFML Keyboard::Key of the key pressed.
    /// @param function: Function to execute when the key is pressed.
    /// @return void
    void addKeyPressed(sf::Keyboard::Key keyboard, const std::function<void()>& function);

    /// @brief addMouseButtonPressed(): Add a mouse button pressed to the map.
    /// @param mouse: SFML Mouse::Button of the mouse button pressed.
    /// @param function: Function to execute when the mouse button is pressed.
    /// @return void
    void addMouseButtonPressed(sf::Mouse::Button mouse, const std::function<void()>& function);

    /// @brief addMouseMoved(): Add a mouse moved to the map.
    /// @param nameEntity : Name of the Entity you want.
    /// @param function: Function to execute when the mouse moved on entity.
    /// @return void
    void addMouseMoved(const std::string& nameEntity, const std::function<void()>& function);

    /// @brief getKeyPressedMap(): Get the map of the key pressed.
    /// @param void
    /// @return std::map<sf::Keyboard::Key, std::function<void()>>: The map of the key pressed.
    std::map<sf::Keyboard::Key, std::function<void()>>& getKeyPressedMap();

    /// @brief getMouseButtonPressedMap(): Get the map of the mouse button pressed.
    /// @param void
    /// @return std::map<sf::Mouse::Button, std::function<void()>>: The map of the mouse button pressed.
    std::map<sf::Mouse::Button, std::function<void()>>& getMouseButtonPressedMap();

    /// @brief getMouseMovedPressedMap(): Get the map of the key pressed.
    /// @param void
    /// @return std::map<std::string, std::function<void()>>: The map of the mouse moved.
    std::map<std::string, std::function<void()>>& getMouseMovedMap();

    /**
     * @brief getKeyStatesMap(): Get the map of the key states.
     * @return std::map<sf::Keyboard::Key, bool>&: The map of the key states.
     */
    std::map<sf::Keyboard::Key, bool>& getKeyStatesMap();

    /**
     * @brief setKeyStatesMap(sf::Keyboard::Key): Initialize the map of the key states for the parameter value to false
     * @param key: The touch of the keyboard with using SFML.
     */
    void setKeyStatesMap(sf::Keyboard::Key key);
};

