//
// Created by thibaultcampagne on 30/11/23.
//

#include "Audio.h"

Audio::Audio(const sf::SoundBuffer& buffer) : soundBuffer(buffer) {
    sound.setBuffer(soundBuffer);
}

bool Audio::loadSoundBuffer(const std::string& filePath) {
    if (soundBuffer.loadFromFile(filePath)) {
        sound.setBuffer(soundBuffer);
        return true;
    } else {
        std::cerr << "Error: Sound file not found" << std::endl;
        return false;
    }
}

bool Audio::setSoundBuffer(const sf::SoundBuffer& buffer) {
    soundBuffer = buffer;
    sound.setBuffer(soundBuffer);
    return true;
}

const sf::SoundBuffer& Audio::getSoundBuffer() const {
    return soundBuffer;
}

bool Audio::setSound(const sf::Sound& sound) {
    this->sound = sound;
    return true;
}

const sf::Sound& Audio::getSound() const {
    return sound;
}

void Audio::play() {
    sound.play();
}

void Audio::pause() {
    sound.pause();
}

void Audio::stop() {
    sound.stop();
}

void Audio::setLoop(bool loop) {
    sound.setLoop(loop);
}

void Audio::setVolume(float volume) {
    sound.setVolume(volume);
}

float Audio::getVolume() const {
    return sound.getVolume();
}

bool Audio::isPlaying() const {
    return sound.getStatus() == sf::Sound::Playing;
}
