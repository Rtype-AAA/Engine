//
// Created by thibaultcampagne on 12/01/24.
//

#include "Music.h"

int Music::getBit() {
    return bit;
}

void Music::update(sf::Time timeDelta) {
}

bool Music::init() {
    return true;
}

void Music::setMusic(std::map<std::string, std::shared_ptr<sf::Music>> mapMusic, const std::string& nameMusic) {
    if (!mapMusic.empty()) {
        auto it = mapMusic.find(nameMusic);
        if (it != mapMusic.end()) {
            music = it->second;
        }
    }
}

void Music::play() {
    music->play();
}

void Music::stop() {
    music->stop();
}

void Music::setDeferredMusic(std::function<void()> setter) {
    deferredMusic = std::move(setter);
}

void Music::applyDeferredMusic() {
    if (deferredMusic) {
        deferredMusic();
    }
}

std::shared_ptr<sf::Music> Music::getMusic() const {
    return music;
}

void Music::play() {
    music->play();
}

void Music::pause() {
    music->pause();
}

void Music::stop() {
    music->stop();
}

void Music::setLoop(bool loop) {
    music->setLoop(loop);
}

bool Music::getLoop() const {
    return music->getLoop();
}

void Music::setVolume(float volume) {
    music->setVolume(volume);
}

float Music::getVolume() const {
    return music->getVolume();
}

sf::SoundSource::Status Music::getStatus() const {
    return music->getStatus();
}