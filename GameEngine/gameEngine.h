//
// Created by thibaultcampagne on 28/12/23.
//

#ifndef R_TYPE_GAMEENGINE_H
#define R_TYPE_GAMEENGINE_H

#include <variant>
#include "../World/world.h"

class GameEngine : protected World {
private:
    std::variant<std::unique_ptr<sf::Window>, std::unique_ptr<sf::RenderWindow>> window;
    std::map<std::string, std::unique_ptr<World>> worldMap{};
public:
    GameEngine() = default;
    explicit GameEngine(sf::VideoMode mode, std::string type, sf::String title, sf::Uint32 style=sf::Style::Default,
                        const sf::ContextSettings &settings=sf::ContextSettings());
    ~GameEngine() = default;
    void run(std::map<std::string, std::unique_ptr<World>> mapWorld, std::string);
    const auto& getWindow() {return window;}
    void setWindow();
    void renderGameEngine();
    bool isWindowOpen();
    void updateGameEngine();
    void initialize(std::string pathRessources);
    void initializeTexture();
};


#endif //R_TYPE_GAMEENGINE_H
