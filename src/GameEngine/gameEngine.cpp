//
// Created by thibaultcampagne on 28/12/23.
//

#include "gameEngine.h"

#include <utility>

GameEngine::GameEngine(sf::VideoMode mode, const sf::String& title, sf::Uint32 style,
                       const sf::ContextSettings &settings) {
    window = std::make_unique<sf::RenderWindow>(mode, title, style, settings);
}

void GameEngine::run(std::map<std::string, std::unique_ptr<World>> mapWorld,
                     const std::map<std::string, std::vector<std::pair<std::string, std::string>>>& pathRessources,
                     const std::string& firstScene) {
    initialize(std::move(mapWorld), pathRessources, firstScene);
    while (isWindowOpen()) {
        deltaTime = clock.restart();
        eventGameEngine();
        updateGameEngine();
        renderGameEngine();
    }
}

void GameEngine::renderGameEngine() {
    window->clear();
    for (auto const& entityManager : getCurrentWorld()->getEntityManagerMap()) {
        for (auto const& entity : entityManager.second->getEntityMap()) {
            if (entity.second->getActive()) {
                entity.second->drawEntity(*window);
            }
        }
    }
    window->display();
}

void GameEngine::eventGameEngine() {
    while (window->pollEvent(event.getEvent())) {
        switch (event.getEvent().type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (!getEventEngine().getKeyStatesMap().empty()) {
                    auto it = getEventEngine().getKeyStatesMap().find(event.getEvent().key.code);
                    if (it != getEventEngine().getKeyStatesMap().end()) {
                        it->second = true;
                    }
                }
                break;
            case sf::Event::KeyReleased:
                if (!getEventEngine().getKeyStatesMap().empty()) {
                    auto it = getEventEngine().getKeyStatesMap().find(event.getEvent().key.code);
                    if (it != getEventEngine().getKeyStatesMap().end()) {
                        it->second = false;
                    }
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (!getEventEngine().getMouseButtonPressedMap().empty()) {
                    auto eventIt = getEventEngine().getMouseButtonPressedMap().find(event.getEvent().mouseButton.button);
                    if (eventIt != getEventEngine().getMouseButtonPressedMap().end()) {
                        eventIt->second();
                    }
                }
                break;
            case sf::Event::MouseMoved:
                if (!getEventEngine().getMouseMovedMap().empty()) {
                    for (auto const& entityManager : getCurrentWorld()->getEntityManagerMap()) {
                        for (auto const& entity : entityManager.second->getEntityMap()) {
                            for (auto const &mouseMoved: event.getMouseMovedMap()) {
                                if (entity.first == mouseMoved.first) {
                                    if (entity.second->getComponentBitset().test(1)) {
                                        sf::FloatRect bounds = entity.second->getComponent<Sprite>().getSprite().getGlobalBounds();
                                        auto mouseX = static_cast<float>(event.getEvent().mouseMove.x);
                                        auto mouseY = static_cast<float>(event.getEvent().mouseMove.y);
                                        if (bounds.contains(mouseX, mouseY)) {
                                            mouseMoved.second();
                                            break;
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
        }
    }
    for (auto const& keyPressed : getEventEngine().getKeyPressedMap()) {
        if (sf::Keyboard::isKeyPressed(keyPressed.first)) {
            auto it = getEventEngine().getKeyPressedMap().find(keyPressed.first);
            if (it != getEventEngine().getKeyPressedMap().end()) {
                it->second();
            }
        }
    }
}

void GameEngine::updateGameEngine() {
    for (auto const& entityManager : getCurrentWorld()->getEntityManagerMap()) {
        for (auto const& entity : entityManager.second->getEntityMap()) {
            entity.second->applyDeferredEntity();
            if (entity.second->getActive()) {
                entity.second->update(deltaTime);
            }
        }
    }
}

bool GameEngine::isWindowOpen() {
    return window->isOpen();
}

std::vector<std::string> GameEngine::getFilesRessources(const std::string& pathDirectory) {
    if (!std::filesystem::exists(pathDirectory) || !std::filesystem::is_directory(pathDirectory)) {
        std::cerr << "Folder not found or invalid path." << std::endl;
        exit(1);
    }
    std::vector<std::string> allFilesName;
    for (const auto& entry : std::filesystem::directory_iterator(pathDirectory)) {
        const auto& path = entry.path();
        allFilesName.push_back(path.filename().string());
    }
    return allFilesName;
}

void GameEngine::initialize(std::map<std::string, std::unique_ptr<World>> mapWorld,
                            const std::map<std::string, std::vector<std::pair<std::string, std::string>>>& pathRessources,
                            const std::string& firstScene) {
    initializeAllFiles(pathRessources);
    initializeWorldMap(std::move(mapWorld));
    for (const auto& element : worldMap) {
        const std::string key = element.first;

        if (key == firstScene) {
            currentWorld = worldMap[key];
            break;
        }
    }
    if (!mapTexture.empty()) {
        initializeSpriteFunction();
    }
    if (!mapSound.empty()) {
        initializeSoundFunction();
    }
    if (!mapMusic.empty()) {
        initializeMusicFunction();
    }
    if (!mapFont.empty()) {
        initializeTextFunction();
    }
}

void GameEngine::initializeSpriteFunction() const {
    for (auto const& world : getWorldMap()) {
        for (auto const& entityManager : world.second->getEntityManagerMap()) {
            for (auto const& entity : entityManager.second->getEntityMap()) {
                if (entity.second->getComponentBitset().test(1)) {
                    entity.second->getComponent<Sprite>().applyDeferredSprite();
                }
            }
        }
    }
}

void GameEngine::initializeSoundFunction() const {
    for (auto const& world : getWorldMap()) {
        for (auto const& entityManager : world.second->getEntityManagerMap()) {
            for (auto const& entity : entityManager.second->getEntityMap()) {
                if (entity.second->getComponentBitset().test(2)) {
                    entity.second->getComponent<Sound>().applyDeferredSound();
                }
            }
        }
    }
}

void GameEngine::initializeMusicFunction() const {
    for (auto const& world : getWorldMap()) {
        for (auto const& entityManager : world.second->getEntityManagerMap()) {
            for (auto const& entity : entityManager.second->getEntityMap()) {
                if (entity.second->getComponentBitset().test(3)) {
                    entity.second->getComponent<Music>().applyDeferredMusic();
                }
            }
        }
    }
}

void GameEngine::initializeTextFunction() const {
    for (auto const& world : getWorldMap()) {
        for (auto const& entityManager : world.second->getEntityManagerMap()) {
            for (auto const& entity : entityManager.second->getEntityMap()) {
                if (entity.second->getComponentBitset().test(4)) {
                    entity.second->getComponent<Text>().applyDeferredText();
                }
            }
        }
    }
}

void GameEngine::initializeAllFiles(const std::map<std::string, std::vector<std::pair<std::string, std::string>>>& pathRessources) {
    for (const auto& element : pathRessources) {
        if (element.first == "Textures" || element.first == "Texture") {
            initializeTexture(element.second);
        } else if (element.first == "Sound" || element.first == "Sounds") {
            initializeSound(element.second);
        } else if (element.first == "Music" || element.first == "Musics") {
            initializeMusic(element.second);
        } else if (element.first == "Font" || element.first == "Fonts") {
            initializeFont(element.second);
        } else {
            std::cout << "The resource type does not exist, please choose from the available options." << std::endl;
            exit(0);
        }
    }
}

void GameEngine::initializeTexture(const std::vector<std::pair<std::string, std::string>>& files) {
    sf::Texture texture;
    for (const auto& file : files) {
        if (!texture.loadFromFile(file.second)) {
            std::cerr << "Error loading texture: " << file.second << std::endl;
            exit(1);
        } else {
            std::cout << "Texture loaded successfully: " << file.second << std::endl;
        }
        mapTexture[file.first] = std::make_shared<sf::Texture>(texture);
    }
}

void GameEngine::initializeSound(const std::vector<std::pair<std::string, std::string>>& files) {
    sf::SoundBuffer soundBuffer;
    for (const auto& file : files) {
        if (!soundBuffer.loadFromFile(file.second)) {
            std::cerr << "Error loading texture: " << file.second << std::endl;
            exit(1);
        }
        else {
            std::cout << "Texture loaded successfully: " << file.second << std::endl;
        }
        mapSound[file.first] = std::make_shared<sf::SoundBuffer>(soundBuffer);
    }
}

void GameEngine::initializeMusic(const std::vector<std::pair<std::string, std::string>>& files) {
    for (const auto& file : files) {
        std::shared_ptr<sf::Music> music = std::make_shared<sf::Music>();
        if (!music->openFromFile(file.second)) {
            std::cerr << "Error loading music: " << file.second << std::endl;
            exit(1);
        } else {
            std::cout << "Music loaded successfully: " << file.second << std::endl;
        }
        mapMusic[file.first] = music;
    }
}

void GameEngine::initializeFont(const std::vector<std::pair<std::string, std::string>>& files) {
    sf::Font font;
    for (const auto& file : files) {
        if (!font.loadFromFile(file.second)) {
            std::cerr << "Error loading texture: " << file.second << std::endl;
            exit(1);
        }
        else {
            std::cout << "Texture loaded successfully: " << file.second << std::endl;
        }
        mapFont[file.first] = std::make_shared<sf::Font>(font);
    }
}

void GameEngine::initializeWorldMap(std::map<std::string, std::unique_ptr<World>> mapWorld) {
    for (auto& element : mapWorld) {
        const std::string key = element.first;
        addWorld(key, std::move(element.second));
    }
}

sf::RenderWindow& GameEngine::getWindow() {
    return *window;
}

EventEngine& GameEngine::getEventEngine() {
    return event;
}

void GameEngine::setCurrentWorld(World* world) {
    currentWorld = world;
}

World* GameEngine::getCurrentWorld() const {
    return currentWorld;
}

World& GameEngine::addWorld(const std::string& nameWorld, std::unique_ptr<World> world) {
    if (!world->init()) {
        throw std::runtime_error("Echec de l'initialisation de World : " + nameWorld);
    }
    World *comp = world.get();
    worlds.insert(std::make_pair(nameWorld, std::move(world)));
    worldMap.insert(std::make_pair(nameWorld, comp));
    return *comp;
}

World& GameEngine::getWorld(const std::string& nameWorld) {
    auto it = worldMap.find(nameWorld);
    if (it != worldMap.end()) {
        auto ptr = worldMap[nameWorld];
        return *static_cast<World*>(ptr);
    } else {
        throw std::runtime_error("Le world que vous voulez récupérer n'existe pas ou n'a pas été trouvé.");
    }
}

std::map<std::string, std::shared_ptr<sf::Texture>> GameEngine::getMapTexture() const {
    return mapTexture;
}

std::map<std::string, World *> GameEngine::getWorldMap() const {
    return worldMap;
}

std::map<std::string, std::shared_ptr<sf::Music>> GameEngine::getMapMusic() const {
    return mapMusic;
}

std::map<std::string, std::shared_ptr<sf::SoundBuffer>> GameEngine::getMapSound() const {
    return mapSound;
}

std::map<std::string, std::shared_ptr<sf::Font>> GameEngine::getMapFont() const {
    return mapFont;
}

sf::Clock GameEngine::getClock() const {
    return clock;
}

sf::Time GameEngine::getDeltaTime() const {
    return deltaTime;
}

void GameEngine::setDeltaTime(sf::Time newTimeDelta) {
    deltaTime = newTimeDelta;
}