//
// Created by thibaultcampagne on 31/12/23.
//

#ifndef R_TYPE_EVENTENGINE_H
#define R_TYPE_EVENTENGINE_H

#include "std.h"
#include "sfml.h"

/**
 * @brief EventEngine class: EventEngine is a class that represents the event engine of the game.
 *
 * The EventEngine class manages the events of the game.
 */
class EventEngine {
private:
    std::map<sf::Keyboard::Key, std::function<void()>> keyPressedMap{}; ///< Map of the key pressed.
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

    /// @brief getKeyPressedMap(): Get the map of the key pressed.
    /// @param void
    /// @return std::map<sf::Keyboard::Key, std::function<void()>>: The map of the key pressed.
    std::map<sf::Keyboard::Key, std::function<void()>>& getKeyPressedMap() {return keyPressedMap;}
};


#endif //R_TYPE_EVENT_H
