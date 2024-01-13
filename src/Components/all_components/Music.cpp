//
// Created by thibaultcampagne on 12/01/24.
//

#include "Music.h"

void Music::setMusic(std::map<std::string, std::shared_ptr<sf::Music>> mapMusic, std::string nameMusic) {
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
    deferredMusic = setter;
}

void Music::applyDeferredMusic() {
    if (deferredMusic) {
        deferredMusic();
    }
}