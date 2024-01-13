//
// Created by thibaultcampagne on 30/11/23.
//

#pragma once

#include "Components.h"
#include "sfml.h"

/**
 * @brief Sound class: Sound is a class that represents the audio properties of a Component.
 *
 * The Sound class manages the audio representation of a Component using SFML.
 */
class Sound : public Components {
private:
    sf::SoundBuffer soundBuffer;
    sf::Sound sound; ///< SFML Sound for playing audio.
    std::function<void()> deferredSound;

    int bit = 2;
public:
    /// @brief Default Sound constructor.
    /// @param void
    /// @return void
    Sound() = default;

    /// @brief Sound constructor with an existing sound buffer. Automatically set the sound.
    /// @param buffer: SFML SoundBuffer for audio.
    /// @return void
    explicit Sound(const sf::SoundBuffer& buffer);

    /// @brief Sound destructor.
    /// @param void
    /// @return void
    ~Sound() override = default;

    void update(sf::Time timeDelta) override;

    /// @brief loadSoundBuffer(): Load the sound buffer from a file. Automatically set the component sound. /!\ Only supports .wav, .ogg and FLAC files.
    /// @param filePath: Path to the audio file.
    /// @return bool: True if the sound buffer has been loaded, false otherwise.
    bool loadSoundBuffer(const std::string& filePath);

    /// @brief setSoundBuffer(): Set the sound buffer with an existing one. Automatically set the component sound.
    /// @param buffer: SFML SoundBuffer for audio.
    /// @return bool: True if the sound buffer has been set, false otherwise.
    bool setSoundBuffer(const sf::SoundBuffer& buffer);

    /// @brief getSoundBuffer(): Get the current sound buffer.
    /// @param void
    /// @return sf::SoundBuffer: SFML SoundBuffer for audio.
    const sf::SoundBuffer& getSoundBuffer() const;

    /// @brief setSound(): Set the sound with an existing one. Automatically set the component sound buffer.
    /// @param sound: SFML Sound for audio.
    /// @return bool: True if the sound has been set, false otherwise.
    bool setSound(const sf::Sound& sound);

    void setSound(std::map<std::string, std::shared_ptr<sf::SoundBuffer>> mapSound, std::string nameSound);

    void setDeferredSound(std::function<void()> setter);

    void applyDeferredSound();

    /// @brief getSound(): Get the current sound.
    /// @param void
    /// @return sf::Sound: SFML Sound for audio.
    const sf::Sound& getSound() const;

    /// @brief play(): Play the audio.
    /// @param void
    /// @return void
    void play();

    /// @brief pause(): Pause the audio.
    /// @param void
    /// @return void
    void pause();

    /// @brief stop(): Stop the audio.
    /// @param void
    /// @return void
    void stop();

    /// @brief setLoop(): Set whether the audio should loop or not.
    /// @param loop: True to enable looping, false to disable.
    /// @return void
    void setLoop(bool loop);

    /// @brief setVolume(): Set the volume of the audio.
    /// @param volume: Volume level (0 to 100).
    /// @return void
    void setVolume(float volume);

    /// @brief getVolume(): Get the current volume level.
    /// @param void
    /// @return float: Volume level (0 to 100).
    float getVolume() const;

    /// @brief isPlaying(): Check if the audio is currently playing.
    /// @param void
    /// @return bool: True if the audio is playing, false otherwise.
    bool isPlaying() const;

    int getBit() const {return bit;}
};
