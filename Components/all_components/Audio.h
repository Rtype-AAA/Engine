//
// Created by thibaultcampagne on 30/11/23.
//

// Audio.h
#ifndef R_TYPE_AUDIO_H
#define R_TYPE_AUDIO_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../Components.h"

/**
 * @brief Audio class: Audio is a class that represents the audio properties of a Component.
 *
 * The Audio class manages the audio representation of a Component using SFML.
 */
class Audio : public Components {
private:
    sf::SoundBuffer soundBuffer; ///< SFML SoundBuffer for audio.
    sf::Sound sound; ///< SFML Sound for playing audio.

public:
    /// @brief Default Audio constructor.
    /// @param void
    /// @return void
    Audio() = default;

    /// @brief Audio constructor with an existing sound buffer.
    /// @param buffer: SFML SoundBuffer for audio.
    /// @return void
    explicit Audio(const sf::SoundBuffer& buffer);

    /// @brief Audio destructor.
    /// @param void
    /// @return void
    ~Audio() override = default;

    /// @brief loadSoundBuffer(): Load the sound buffer from a file. /!\ Only supports .wav, .ogg and FLAC files.
    /// @param filePath: Path to the audio file.
    /// @return bool: True if the sound buffer has been loaded, false otherwise.
    bool loadSoundBuffer(const std::string& filePath);

    /// @brief setSoundBuffer(): Set the sound buffer with an existing one.
    /// @param buffer: SFML SoundBuffer for audio.
    /// @return bool: True if the sound buffer has been set, false otherwise.
    bool setSoundBuffer(const sf::SoundBuffer& buffer);

    /// @brief getSoundBuffer(): Get the current sound buffer.
    /// @param void
    /// @return sf::SoundBuffer: SFML SoundBuffer for audio.
    const sf::SoundBuffer& getSoundBuffer() const;

    /// @brief setSound(): Set the sound with an existing one.
    /// @param sound: SFML Sound for audio.
    /// @return bool: True if the sound has been set, false otherwise.
    bool setSound(const sf::Sound& sound);

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
};

#endif //R_TYPE_AUDIO_H
