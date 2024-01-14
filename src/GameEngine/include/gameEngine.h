//
// Created by thibaultcampagne on 28/12/23.
//

#pragma once

#include "std.h"
#include "world.h"
#include "eventEngine.h"
#include "Sprite.h"
#include "Rect.h"
#include "Sound.h"
#include "Music.h"

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
    std::map<std::string, std::shared_ptr<sf::SoundBuffer>> mapSound{}; /// < Map of the sounds.
    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic{}; /// < Map of the musics.
    std::map<std::string, std::shared_ptr<sf::Font>> mapFont{}; /// < Map of the fonts.
    World *currentWorld{}; ///< Current world.

    std::unique_ptr<sf::RenderWindow> window; /// < Window of the game. It can be a sf::Window or a sf::RenderWindow.
    EventEngine event;                                                                   /// < EventEngine class which manages the events.

    sf::Clock clock; /// < Clock of the game.
    sf::Time deltaTime; /// < Time of the game. Using with the Clock.
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
    GameEngine(sf::VideoMode mode, const sf::String& title, sf::Uint32 style = sf::Style::Default,
                        const sf::ContextSettings &settings = sf::ContextSettings());

    /// @brief GameEngine destructor.
    /// @param void
    /// @return void
    ~GameEngine() override = default;

    /// @brief run(): Run the game engine (with parameters).
    /// @param mapWorld: Map of World classes' unique pointers.
    /// @param pathRessources: Map of the path of the ressources (assets).
    /// @param firstScene: Name of the first scene.
    /// @return void
    void run(std::map<std::string, std::unique_ptr<World>> mapWorld,
             const std::map<std::string, std::string>& pathRessources, const std::string& firstScene);

    /// @brief renderGameEngine(): Render the game engine.
    /// @param void
    /// @return void
    void renderGameEngine();

    /// @brief eventGameEngine(): Manage the events of the game engine.
    /// @param void
    /// @return void
    void eventGameEngine();

    /// @brief updateGameEngine(): Update the game engine.
    /// @param void
    /// @return void
    void updateGameEngine();

    /// @brief isWindowOpen(): Check if the window is open.
    /// @param void
    /// @return bool: True if the window is open, false otherwise.
    bool isWindowOpen();

    /// @brief getFilesRessources(): Get all the ressources type files in the given directory.
    /// @param pathDirectory: Path of the directory.
    /// @return std::vector<std::string>: Vector of the ressources type files' names.
    static std::vector<std::string> getFilesRessources(const std::string& pathDirectory);

    /// @brief initialize(): Initialize the game engine.
    /// @param mapWorld: Map of World classes' unique pointers.
    /// @param pathRessources: Map of the path of the ressources (assets).
    /// @param firstScene: Name of the first scene.
    /// @return void
    void initialize(std::map<std::string, std::unique_ptr<World>> mapWorld,
                    const std::map<std::string, std::string>& pathRessources, const std::string& firstScene);

    /// @brief initializeSpriteFunction(): Initialize the sprites function.
    /// @param void
    /// @return void
    void initializeSpriteFunction() const;

    /// @brief initializeSoundFunction(): Initialize the sound function.
    /// @param void
    /// @return void
    void initializeSoundFunction() const;

    /// @brief initializeMusicFunction(): Initialize the music function.
    /// @param void
    /// @return void
    void initializeMusicFunction() const;

    /// @brief initializeFontFunction(): Initialize the font function.
    /// @param void
    /// @return void
    void initializeTextFunction() const;

    /// @brief initializeAllFiles(): Initialize all the ressources files the engine need.
    /// @param pathRessources: Map of the path of the ressources (assets).
    /// @return void
    void initializeAllFiles(const std::map<std::string, std::string>& pathRessources);

    /// @brief initializeTexture(): Initialize the textures with their path.
    /// @param path: Path of the texture.
    /// @return void
    void initializeTexture(std::string path);

    /// @brief initializeSound(): Initialize the sound with their path.
    /// @param path: Path of the sound file.
    /// @return void
    void initializeSound(std::string path);

    /// @brief initializeMusic(): Initialize the music with their path.
    /// @param path: Path of the music file.
    /// @return void
    void initializeMusic(std::string path);

    /// @brief initializeFont(): Initialize the font with their path.
    /// @param path: Path of the font file.
    /// @return void
    void initializeFont(std::string path);

    /// @brief initializeWorldMap(): Initialize the world map.
    /// @param mapWorld: Map of World classes' unique pointers.
    /// @return void
    void initializeWorldMap(std::map<std::string, std::unique_ptr<World>> mapWorld);

    /// @brief getWindow(): Get the window.
    /// @param void
    /// @return sf::RenderWindow&: GameEngine's window.
    sf::RenderWindow &getWindow();

    /// @brief getEventEngine(): Get the event engine.
    /// @param void
    /// @return EventEngine&: GameEngine's EventEngine.
    EventEngine &getEventEngine();

    /// @brief setCurrentWorld(): Set GameEngine's current world.
    /// @param world: World to set.
    /// @return void
    void setCurrentWorld(World *world);

    /// @brief getCurrentWorld(): Get GameEngine's current world.
    /// @param void
    /// @return World*: GameEngine's current world.
    [[nodiscard]] World* getCurrentWorld() const;

    /// @brief addWorld(): Add a world to the world map.
    /// @param nameWorld: Name of the world.
    /// @param world: World to add.
    /// @return World&: The world.
    World &addWorld(const std::string& nameWorld, std::unique_ptr<World> world);

    /// @brief getWorld(): Get a world from the world map with its name.
    /// @param nameWorld: Name of the world.
    /// @return World&: GameEngine's world.
    World &getWorld(const std::string& nameWorld);

    /// @brief getMapTexture(): Get GameEngine's map of the textures.
    /// @param void
    /// @return std::map<std::string, std::shared_ptr<sf::Texture>>: GameEngine's map of the textures.
    [[nodiscard]] std::map<std::string, std::shared_ptr<sf::Texture>> getMapTexture() const;

    /// @brief getWorldMap(): Get GameEngine's map of the worlds.
    /// @param void
    /// @return std::map<std::string, World*>: GameEngine's map of the worlds.
    [[nodiscard]] std::map<std::string, World *> getWorldMap() const;

    /// @brief getMapMusic(): Get GameEngine's map of the music.
    /// @param void
    /// @return std::map<std::string, std::shared_ptr<sf::Music>>: GameEngine's map of the musics.
    [[nodiscard]] std::map<std::string, std::shared_ptr<sf::Music>> getMapMusic() const;

    /// @brief getMapSound(): Get GameEngine's map of the sound.
    /// @param void
    /// @return std::map<std::string, std::shared_ptr<sf::SoundBuffer>>: GameEngine's map of the musics.
    [[nodiscard]] std::map<std::string, std::shared_ptr<sf::SoundBuffer>> getMapSound() const;

    /// @brief getMapFont(): Get GameEngine's map of the font.
    /// @param void
    /// @return std::map<std::string, std::shared_ptr<sf::Font>>: GameEngine's map of the musics.
    [[nodiscard]] std::map<std::string, std::shared_ptr<sf::Font>> getMapFont() const;

    /// @brief getClock(): Get GameEngine's clock.
    /// @param void
    /// @return sf::Clock: GameEngine's clock.
    [[nodiscard]] sf::Clock getClock() const;

    /// @brief getDeltaTime(): Get GameEngine's deltaTime.
    /// @param void
    /// @return sf::Time: GameEngine's deltaTimes.
    [[nodiscard]] sf::Time getDeltaTime() const;

    /// @brief setDeltaTime(): Set GameEngine's deltaTime.
    /// @param newTimeDelta: New deltaTime for GameEngine's deltaTime.
    /// @return void
    void setDeltaTime(sf::Time newTimeDelta);
};
