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
    if (music != nullptr) {
        music->play();
    } else {
        std::cerr << "Please set the music before playing it." << std::endl;
    }
}

void Music::pause() {
    if (music != nullptr) {
        music->pause();
    } else {
        std::cerr << "Please set the music before pausing it." << std::endl;
    }
}

void Music::stop() {
    if (music != nullptr) {
        music->stop();
    } else {
        std::cerr << "Please set the music before stopping it." << std::endl;
    }
}

void Music::setLoop(bool loop) {
    if (music != nullptr) {
        music->setLoop(loop);
    } else {
        std::cerr << "Please set the music before setting its loop." << std::endl;
    }}

bool Music::getLoop() const {
    if (music != nullptr) {
        return music->getLoop();
    } else {
        return false;
    }
}

void Music::setVolume(float volume) {
    if (music != nullptr) {
        music->setVolume(volume);
    } else {
        std::cerr << "Please set the music before setting its volume." << std::endl;
    }
}

float Music::getVolume() const {
    if (music != nullptr) {
        return music->getVolume();
    } else {
        return -100;
    }
}

sf::SoundSource::Status Music::getStatus() const {
    if (music != nullptr) {
        return music->getStatus();
    } else {
        return sf::SoundSource::Status::Stopped;
    }
}