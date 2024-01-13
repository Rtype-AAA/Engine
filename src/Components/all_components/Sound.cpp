//
// Created by thibaultcampagne on 30/11/23.
//

#include "Sound.h"

int Sound::getBit() {
    return bit;
}

void Sound::update(sf::Time timeDelta) {
}

bool Sound::init() {
    return true;
}

void Sound::setSound(const sf::Sound& newSound) {
    sound = newSound;
}

void Sound::setSound(std::map <std::string, std::shared_ptr<sf::SoundBuffer>> mapSound, const std::string& nameSound) {
    if (!mapSound.empty()) {
        auto it = mapSound.find(nameSound);
        if (it != mapSound.end()) {
            sound.setBuffer(*it->second);
        }
    }
}

void Sound::setDeferredSound(std::function<void()> setter) {
    deferredSound = std::move(setter);
}

void Sound::applyDeferredSound() {
    if (deferredSound) {
        deferredSound();
    }
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

bool Sound::getLoop() const {
    return sound.getLoop();
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
