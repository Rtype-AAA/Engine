//
// Created by thibaultcampagne on 28/12/23.
//

#pragma once

#include "std.h"
#include "world.h"
#include "eventEngine.h"
#include "Sprite.h"

/**
 * @brief GameEngine class: GameEngine is a class that represents the game engine.
 *
 * The GameEngine class manages the game engine.
 */
class GameEngine : protected World, protected EventEngine
{
private:
    std::map<std::string, World *> worldMap{}; ///< Map of World classes.
    std::map<std::string, std::unique_ptr<World>> worlds{}; ///< Map of World classes' unique pointers.
    std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture{}; ///< Map of the textures.
    World *currentWorld; ///< Current world.

    std::variant<std::unique_ptr<sf::Window>, std::unique_ptr<sf::RenderWindow>> window; /// < Window of the game. It can be a sf::Window or a sf::RenderWindow.
    EventEngine event;                                                                   /// < EventEngine class which manages the events.

    sf::Clock clock;
    sf::Time deltaTime;
public:
    /// @brief Default GameEngine constructor.
    /// @param void
    /// @return void
    GameEngine() = default;

    /// @brief GameEngine constructor with parameters.
    /// @param mode: Video mode.
    /// @param type: Type of the graphics ("2D" or "3D").
    /// @param title: Title of the window.
    /// @param style: Style of the window (sf::Style::Default by default).
    /// @param settings: Settings of the window.
    /// @return void
    explicit GameEngine(sf::VideoMode mode, std::string type, sf::String title, sf::Uint32 style = sf::Style::Default,
                        const sf::ContextSettings &settings = sf::ContextSettings());

    /// @brief GameEngine destructor.
    /// @param void
    /// @return void
    ~GameEngine() = default;

    /// @brief run(): Run the game engine (with parameters).
    /// @param mapWorld: Map of World classes' unique pointers.
    /// @param pathRessources: Map of the path of the ressources (assets).
    /// @param firstScene: Name of the first scene.
    /// @return void
    void run(std::map<std::string, std::unique_ptr<World>> mapWorld,
             std::map<std::string, std::string> pathRessources, std::string firstScene);

    /// @brief run(): Run the game engine (without parameters).
    /// @param void
    /// @return void
    void run();

    /// @brief renderGameEngine(): Render the game engine.
    /// @param void
    /// @return void
    void renderGameEngine();

    /// @brief eventGameEngine(): Manage the events of the game engine.
    /// @param void
    /// @return void
    void eventGameEngine();

    /// @brief isWindowOpen(): Check if the window is open.
    /// @param void
    /// @return bool: True if the window is open, false otherwise.
    bool isWindowOpen();

    /// @brief updateGameEngine(): Update the game engine.
    /// @param void
    /// @return void
    void updateGameEngine();

    /// @brief getFilesTexture(): Get all the textures files in the given directory.
    /// @param pathDirectory: Path of the directory.
    /// @return std::vector<std::string>: Vector of the textures files' names.
    std::vector<std::string> getFilesTexture(std::string pathDirectory);

    /// @brief initialize(): Initialize the game engine.
    /// @param mapWorld: Map of World classes' unique pointers.
    /// @param pathRessources: Map of the path of the ressources (assets).
    /// @param firstScene: Name of the first scene.
    /// @return void
    void initialize(std::map<std::string, std::unique_ptr<World>> mapWorld,
                    std::map<std::string, std::string> pathRessources, std::string firstScene);

    /// @brief initializeSprite(): Initialize the sprites.
    /// @param void
    /// @return void
    void initializeSprite();

    /// @brief initializeTexture(): Initialize the textures with their path.
    /// @param path: Path of the texture.
    /// @return void
    void initializeTexture(std::string path);

    /// @brief initializeWorldMap(): Initialize the world map.
    /// @param mapWorld: Map of World classes' unique pointers.
    /// @return void
    void initializeWorldMap(std::map<std::string, std::unique_ptr<World>> mapWorld);

    /// @brief getWindow(): Get the window.
    /// @param void
    /// @return std::variant<std::unique_ptr<sf::Window>, std::unique_ptr<sf::RenderWindow>>: The GameEngine's window
    const auto &getWindow() { return window; }

    /// @brief setWindow(): Set the window.
    /// @param void
    /// @return void
    void setWindow();

    /// @brief getEventEngine(): Get the event engine.
    /// @param void
    /// @return EventEngine&: GameEngine's EventEngine.
    EventEngine &getEventEngine() { return event; }

    /// @brief setCurrentWorld(): Set GameEngine's current world.
    /// @param world: World to set.
    /// @return void
    void setCurrentWorld(World *world);

    /// @brief getCurrentWorld(): Get GameEngine's current world.
    /// @param void
    /// @return World*: GameEngine's current world.
    World *getCurrentWorld() { return currentWorld; }

    /// @brief addWorld(): Add a world to the world map.
    /// @param nameWorld: Name of the world.
    /// @param world: World to add.
    /// @return World&: The world.
    World &addWorld(std::string nameWorld, std::unique_ptr<World> world);

    /// @brief getWorld(): Get a world from the world map with its name.
    /// @param nameWorld: Name of the world.
    /// @return World&: GameEngine's world.
    World &getWorld(std::string nameWorld);

    /// @brief getMapTexture(): Get GameEngine's map of the textures.
    /// @param void
    /// @return std::map<std::string, std::shared_ptr<sf::Texture>>: GameEngine's map of the textures.
    std::map<std::string, std::shared_ptr<sf::Texture>> getMapTexture() const { return mapTexture; }

    /// @brief getWorldMap(): Get GameEngine's map of the worlds.
    /// @param void
    /// @return std::map<std::string, World*>: GameEngine's map of the worlds.
    std::map<std::string, World *> getWorldMap() const { return worldMap; }
};
