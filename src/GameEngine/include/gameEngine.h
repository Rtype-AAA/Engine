//
// Created by thibaultcampagne on 28/12/23.
//

#pragma once

#include "std.h"
#include "world.h"
#include "eventEngine.h"
#include "Sprite.h"

class GameEngine : protected World, protected EventEngine {
private:
    std::map<std::string, World*> worldMap{};
    std::map<std::string, std::unique_ptr<World>> worlds{};
    std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture{};
    World* currentWorld;

    std::variant<std::unique_ptr<sf::Window>, std::unique_ptr<sf::RenderWindow>> window;
    EventEngine event;
public:
    GameEngine() = default;
    explicit GameEngine(sf::VideoMode mode, std::string type, sf::String title, sf::Uint32 style=sf::Style::Default,
                        const sf::ContextSettings &settings=sf::ContextSettings());
    ~GameEngine() = default;


    void run(std::map<std::string, std::unique_ptr<World>> mapWorld,
             std::map<std::string, std::string> pathRessources, std::string firstScene);
    void run();
    void renderGameEngine();
    void eventGameEngine();
    bool isWindowOpen();
    void updateGameEngine();


    void initialize(std::map<std::string, std::unique_ptr<World>> mapWorld,
                    std::map<std::string, std::string> pathRessources, std::string firstScene);
    void initializeSprite();
    void initializeTexture(std::string path);
    void initializeWorldMap(std::map<std::string, std::unique_ptr<World>> mapWorld);


    const auto& getWindow() {return window;}
    void setWindow();
    EventEngine& getEventEngine() {return event;}
    void setCurrentWorld(World* world);
    World* getCurrentWorld() {return currentWorld;}
    World& addWorld(std::string nameWorld, std::unique_ptr<World> world);
    World& getWorld(std::string nameWorld);
    std::map<std::string, std::shared_ptr<sf::Texture>> getMapTexture() const {return mapTexture;}
    std::map<std::string, World*> getWorldMap() const {return worldMap;}
};

