//
// Created by thibaultcampagne on 28/12/23.
//

#ifndef R_TYPE_GAMEENGINE_H
#define R_TYPE_GAMEENGINE_H

#include <variant>
#include <iostream>
#include <filesystem>
#include "../World/world.h"

class GameEngine : protected World {
private:
    std::variant<std::unique_ptr<sf::Window>, std::unique_ptr<sf::RenderWindow>> window;
    std::map<std::string, std::unique_ptr<World>> worldMap{};
    std::map<std::string, std::unique_ptr<sf::Texture>> mapTexture{};
    sf::Event event;
public:
    GameEngine() = default;
    explicit GameEngine(sf::VideoMode mode, std::string type, sf::String title, sf::Uint32 style=sf::Style::Default,
                        const sf::ContextSettings &settings=sf::ContextSettings());
    ~GameEngine() = default;
    void run(std::map<std::string, std::unique_ptr<World>> mapWorld,
             std::map<std::string, std::string> pathRessources);
    const auto& getWindow() {return window;}
    void setWindow();
    void renderGameEngine();
    void eventGameEngine();
    bool isWindowOpen();
    void updateGameEngine();
    void initialize(std::map<std::string, std::string> pathRessources);
    void initializeTexture(std::string path);

    sf::Event getEvent() const {return event;}
};


#endif //R_TYPE_GAMEENGINE_H
