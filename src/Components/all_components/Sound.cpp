//
// Created by thibaultcampagne on 30/11/23.
//

#include "Sound.h"

Sound::Sound(const sf::SoundBuffer& buffer) : soundBuffer(buffer) {
    sound.setBuffer(soundBuffer);
}

void Sound::update(sf::Time timeDelta) {
    return;
}

bool Sound::loadSoundBuffer(const std::string& filePath) {
    if (soundBuffer.loadFromFile(filePath)) {
        sound.setBuffer(soundBuffer);
        return true;
    } else {
        std::cerr << "Error: Sound file not found" << std::endl;
        return false;
    }
}

bool Sound::setSoundBuffer(const sf::SoundBuffer& buffer) {
    soundBuffer = buffer;
    sound.setBuffer(soundBuffer);
    return true;
}

const sf::SoundBuffer& Sound::getSoundBuffer() const {
    return soundBuffer;
}

void Sound::setSound(std::map <std::string, std::shared_ptr<sf::SoundBuffer>> mapSound, std::string nameSound) {
    if (!mapSound.empty()) {
        auto it = mapSound.find(nameSound);
        if (it != mapSound.end()) {
            sound.setBuffer(*it->second);
        }
    }
}

bool Sound::setSound(const sf::Sound& sound) {
    this->sound = sound;
    this->soundBuffer = *sound.getBuffer();
    return true;
}

const sf::Sound& Sound::getSound() const {
    return sound;
}

void Sound::play() {
    sound.play();
}

void Sound::pause() {
    sound.pause();
}

void Sound::stop() {
    sound.stop();
}

void Sound::setLoop(bool loop) {
    sound.setLoop(loop);
}

void Sound::setVolume(float volume) {
    sound.setVolume(volume);
}

float Sound::getVolume() const {
    return sound.getVolume();
}

bool Sound::isPlaying() const {
    return sound.getStatus() == sf::Sound::Playing;
}

void Sound::setDeferredSound(std::function<void()> setter) {
    deferredSound = setter;
}

void Sound::applyDeferredSound() {
    if (deferredSound) {
        deferredSound();
    }
}