//
// Created by thibaultcampagne on 12/01/24.
//

#pragma once

#include "sfml.h"
#include "Components.h"
#include "std.h"

class Music : public Components {
private:
    std::shared_ptr<sf::Music> music;
    std::function<void()> deferredMusic;

    int bit = 3;
public:
    Music() = default;

    ~Music() = default;

    void setMusic(std::map<std::string, std::shared_ptr<sf::Music>> mapMusic, std::string nameMusic);

    void setDeferredMusic(std::function<void()> setter);

    void applyDeferredMusic();

    std::shared_ptr<sf::Music> getMusic() const {return music;}

    void play();

    void play(int seconds);

    void stop();

    int getBit() const {return bit;}
};