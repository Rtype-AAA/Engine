//
// Created by thibaultcampagne on 12/01/24.
//

#pragma once

#include "sfml.h"
#include "Components.h"
#include "std.h"

/**
 * @brief Music class: Music is a class that represents the music in the world.
 *
 * The music class manages the music from an Entity using SFML.
 */

class Music : public Components {
private:
    std::shared_ptr<sf::Music> music; /// < Shared ptr of Music.
    std::function<void()> deferredMusic; /// < Deferred function for Music

    int bit = 3; /// < Bit of the Music
public:
    /**
     * @brief Default Music constructor.
     *
     * Set the default value to "Default".
     */
    Music() = default;

    /**
     * @brief Default override Music destructor.
     *
     * Set the default value to "Default".
     */
    ~Music() override = default;

    /**
     * @brief getBit(): Get the bit of the Music.
     * @return int: The bit of the Music.
     */
    int getBit() override;

    /**
     * @brief update(sf::Time): Update the component Music
     * @param timeDelta: sf::Time of the game.
     */
    void update(sf::Time timeDelta) override;

    /**
     * @brief init(): Initialize the component.
     * @return bool: true if the component is initialized, false otherwise
     */
    bool init() override;

    /// @brief setMusic(std::map<std::string, std::shared_ptr<sf::Music>>, const std::string&):
    /// Initialize the sf::Music of the class.
    /// @param mapMusic: Map of all the music loaded.
    /// @param nameMusic: Name of the music loaded.
    /// @return void
    void setMusic(std::map<std::string, std::shared_ptr<sf::Music>> mapMusic, const std::string& nameMusic);

    /// @brief setDeferredMusic(std::function<void()>): Set the deferred function for Music.
    /// @param setter: Function that will use Music.
    /// @return void
    void setDeferredMusic(std::function<void()> setter);

    /// @brief applyDeferredMusic(): Apply the deferred function for Music
    /// @param void
    /// @return void
    void applyDeferredMusic();

    /// @brief getMusic(): Get the music.
    /// @param void
    /// @return std::shared_ptr<sf::Music>: The shared ptr of the music.
    [[nodiscard]] std::shared_ptr<sf::Music> getMusic() const;

    /// @brief play(): Play the music.
    /// @param void
    /// @return void
    void play();

    /// @brief pause(): Pause the music.
    /// @param void
    /// @return void
    void pause();

    /// @brief stop(): Stop the music.
    /// @param void
    /// @return void
    void stop();

    /// @brief setLoop(bool): Set the loop of the music.
    /// @param loop: True or False.
    /// @return void
    void setLoop(bool loop);

    /// @brief getLoop(): Get if the loop is set to True or False.
    /// @param void
    /// @return bool: True or False.
    [[nodiscard]] bool getLoop() const;

    /// @brief setVolume(float): Set the volume of the music.
    /// @param volume: Float number that represents the volume between 0 and 100 of the music.
    /// @return void
    void setVolume(float volume);

    /// @brief getVolume(): Get the volume of the music.
    /// @param void
    /// @return float: Float number that represents the volume between 0 and 100 of the music.
    [[nodiscard]] float getVolume() const;

    /// @brief getStatus(): Get the status of the music. Playing, pause or stop.
    /// @param void
    /// @return sf::SoundSource::Status: Enumerator of sf::SoundSource::Status which is (Stopped, Paused, Playing).
    [[nodiscard]] sf::SoundSource::Status getStatus() const;
};