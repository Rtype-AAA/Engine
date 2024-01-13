//
// Created by thibaultcampagne on 30/11/23.
//

#pragma once

#include "Components.h"
#include "sfml.h"

/**
 * @brief Sound class: Sound is a class that represents the sound properties of a Component.
 *
 * The Sound class manages the sound representation of a Component using SFML.
 */
class Sound : public Components {
private:
    sf::Sound sound; /// < SFML Sound for playing sound.
    std::function<void()> deferredSound; /// < Deferred function for Sound.

    int bit = 2; /// < Bit of the Sound.
public:
    /**
     * @brief Default Sound constructor.
     *
     * Set the default value to "Default".
     */
    Sound() = default;

    /**
     * @brief Default override Sound destructor.
     *
     * Set the default value to "Default".
     */
    ~Sound() override = default;

    /**
     * @brief getBit(): Get the bit of the Sound.
     * @return int: The bit of the Sound.
     */
    int getBit() override;

    /**
     * @brief update(sf::Time): Update the component Sound
     * @param timeDelta: sf::Time of the game.
     */
    void update(sf::Time timeDelta) override;

    /**
     * @brief init(): Initialize the component.
     * @return bool: true if the component is initialized, false otherwise
     */
    bool init() override;

    /**
     * @brief setSound(const sf::Sound&): Set the sound with an existing one. Automatically set the component sound buffer.
     * @param sound: SFML Sound for sound.
     */
    void setSound(const sf::Sound& sound);

    /**
     * @brief setSound(std::map<std::string, std::shared_ptr<sf::SoundBuffer>>, const std::string&):
     * Initialize the sf::Sound of the class.
     * @param mapSound: Map of all the sound loaded.
     * @param nameSound: Name of the sound loaded.
     */
    void setSound(std::map<std::string, std::shared_ptr<sf::SoundBuffer>> mapSound, const std::string& nameSound);

    /**
     * @brief setDeferredSound(std::function<void()>): Set the deferred function for Sound.
     * @param setter: Function that will use Sound.
     */
    void setDeferredSound(std::function<void()> setter);

    /**
     * @brief applyDeferredSound(): Apply the deferred function for Sound
     */
    void applyDeferredSound();

    /**
     * @brief getSound(): Get the sound.
     * @return const sf::Sound&: The shared ptr of the sound.
     */
    [[nodiscard]] const sf::Sound& getSound() const;

    /**
     * @brief play(): Play the sound.
     */
    void play();

    /**
     * @brief pause(): Pause the sound.
     */
    void pause();

    /**
     * @brief stop(): Stop the sound.
     */
    void stop();

    /**
     * @brief setLoop(bool): Set the loop of the sound.
     * @param loop: True or False.
     */
    void setLoop(bool loop);

    /**
     * @brief getLoop(): Get if the loop is set to True or False.
     * @return bool: True or False.
     */
    [[nodiscard]] bool getLoop() const;

    /**
     * @brief setVolume(float): Set the volume of the sound.
     * @param volume: Float number that represents the volume between 0 and 100 of the sound.
     */
    void setVolume(float volume);

    /**
     * @brief getVolume(): Get the volume of the sound.
     * @return float: Float number that represents the volume between 0 and 100 of the sound.
     */
    [[nodiscard]] float getVolume() const;

    /**
     * @brief isPlaying(): Check if the sound is currently playing.
     * @return bool: True if the sound is playing, false otherwise.
     */
    [[nodiscard]] bool isPlaying() const;
};
