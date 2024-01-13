//
// Created by thibaultcampagne on 28/12/23.
//

#include "gameEngine.h"

GameEngine::GameEngine(sf::VideoMode mode, std::string type, sf::String title, sf::Uint32 style,
                       const sf::ContextSettings &settings) {
    if (type == "2D" or type == "2d") {
        window = std::make_unique<sf::RenderWindow>(mode, title, style, settings);
    } else if (type == "3D" or type == "3d") {
        std::cout << "Veuillez choisir la 2D, la 3D n'est pas encore fonctionnel" << std::endl;
    } else {
        std::cout << "Veuillez choisir un type de graphisme entre 2D et 3D" << std::endl;
        exit(0);
    }
}

void GameEngine::setWindow() {
    return;
}

void GameEngine::setCurrentWorld(World* world) {
    currentWorld = world;
}

World& GameEngine::addWorld(std::string nameWorld, std::unique_ptr<World> world) {
    if (!world->initWorld()) {
        throw std::runtime_error("Echec de l'initialisation de World : " + nameWorld);
    }
    World *comp = world.get();
    worlds.insert(std::make_pair(nameWorld, std::move(world)));
    worldMap.insert(std::make_pair(nameWorld, comp));
    return *comp;
}

World& GameEngine::getWorld(std::string nameWorld) {
    auto it = worldMap.find(nameWorld);
    if (it != worldMap.end()) {
        auto ptr = worldMap[nameWorld];
        return *static_cast<World*>(ptr);
    } else {
        throw std::runtime_error("Le world que vous voulez récupérer n'existe pas ou n'a pas été trouvé.");
    }
}

void GameEngine::initializeWorldMap(std::map<std::string, std::unique_ptr<World>> mapWorld) {
    for (auto& element : mapWorld) {
        const std::string key = element.first;
        addWorld(key, std::move(element.second));
    }
}

void GameEngine::initializeSpriteFunction() {
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

void GameEngine::initializeSoundFunction() {
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

void GameEngine::initializeMusicFunction() {
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

void GameEngine::initializeTextFunction() {
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

std::vector<std::string> GameEngine::getFilesRessources(std::string pathDirectory) {
    if (!std::filesystem::exists(pathDirectory) || !std::filesystem::is_directory(pathDirectory)) {
        std::cerr << "Folder not found or invalid path." << std::endl;
        exit(1);
    }
    std::vector<std::string> allFilesName;
    for (const auto& entry : std::filesystem::directory_iterator(pathDirectory)) {
        const auto& path = entry.path();
        allFilesName.push_back(path.filename());
    }
    return allFilesName;
}

void GameEngine::initializeTexture(std::string path) {
    sf::Texture texture;
    std::vector<std::string> allFilesName;
    allFilesName = getFilesRessources(path);
    path += "/";
    for (const auto& element : allFilesName) {
        if (!texture.loadFromFile(path + element)) {
            std::cerr << "Error loading texture: " + path + element << std::endl;
            exit(1);
        } else {
            std::cout << "Texture loaded successfully: " + path + element << std::endl;
        }
        mapTexture[element] = std::make_shared<sf::Texture>(texture);
    }
}

void GameEngine::initializeSound(std::string path) {
    sf::SoundBuffer soundBuffer;
    std::vector<std::string> allFilesName;
    allFilesName = getFilesRessources(path);
    path += "/";
    for (const auto& element : allFilesName) {
        if (!soundBuffer.loadFromFile(path + element)) {
            std::cerr << "Error loading sound: " + path + element << std::endl;
            exit(1);
        } else {
            std::cout << "Sound loaded successfully: " + path + element << std::endl;
        }
        mapSound[element] = std::make_shared<sf::SoundBuffer>(soundBuffer);
    }
}

void GameEngine::initializeMusic(std::string path) {
    std::vector<std::string> allFilesName;
    allFilesName = getFilesRessources(path);
    path += "/";
    for (const auto& element : allFilesName) {
        std::shared_ptr<sf::Music> music = std::make_shared<sf::Music>();
        if (!music->openFromFile(path + element)) {
            std::cerr << "Error loading music: " + path + element << std::endl;
            exit(1);
        } else {
            std::cout << "Music loaded successfully: " + path + element << std::endl;
        }
        mapMusic[element] = music;
    }
}

void GameEngine::initializeFont(std::string path) {
    sf::Font font;
    std::vector<std::string> allFilesName;
    allFilesName = getFilesRessources(path);
    path += "/";
    for (const auto& element : allFilesName) {
        if (!font.loadFromFile(path + element)) {
            std::cerr << "Error loading font: " + path + element << std::endl;
            exit(1);
        } else {
            std::cout << "Font loaded successfully: " + path + element << std::endl;
        }
        mapFont[element] = std::make_shared<sf::Font>(font);
    }
}

void GameEngine::initializeAllFiles(std::map <std::string, std::string> pathRessources) {
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

void GameEngine::initialize(std::map<std::string, std::unique_ptr<World>> mapWorld,
                            std::map<std::string, std::string> pathRessources,
                            std::string firstScene) {
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

bool GameEngine::isWindowOpen() {
    return std::visit([](const auto& w) -> bool {
        if (w) {
            return w->isOpen();
        } else {
            return false;
        }
    }, window);
}

void GameEngine::updateGameEngine() {
    for (auto const& entityManager : getCurrentWorld()->getEntityManagerMap()) {
        for (auto const& entity : entityManager.second->getEntityMap()) {
            entity.second->update(deltaTime);
        }
    }
    return;
}

void GameEngine::renderGameEngine() {
    std::visit([&](auto& w) {
        if constexpr (std::is_same_v<std::decay_t<decltype(*w)>, sf::RenderWindow>) {
            w->clear();
            for (auto const& entityManager : getCurrentWorld()->getEntityManagerMap()) {
                for (auto const& entity : entityManager.second->getEntityMap()) {
                    entity.second->drawEntity(*w);
                }
            }
            w->display();
        }
    }, window);
}

void GameEngine::eventGameEngine() {
    std::visit([this](auto& w) {
        while (w->pollEvent(event.getEvent())) {
            switch (event.getEvent().type) {
                case sf::Event::Closed:
                    w->close();
                    break;
                case sf::Event::KeyPressed:
                    if (!getEventEngine().getKeyPressedMap().empty()) {
                        auto eventIt = getEventEngine().getKeyPressedMap().find(event.getEvent().key.code);
                        if (eventIt != getEventEngine().getKeyPressedMap().end()) {
                            eventIt->second();
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
                                            Rect<float> bounds = entity.second->getComponent<Sprite>().getBounds();
                                            float mouseX = static_cast<float>(event.getEvent().mouseMove.x);
                                            float mouseY = static_cast<float>(event.getEvent().mouseMove.y);
                                            if (bounds.contains(mouseX, mouseY)) {
                                                mouseMoved.second();
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    break;
            }
        }
    }, window);
}

void GameEngine::run(std::map<std::string, std::unique_ptr<World>> mapWorld,
                     std::map<std::string, std::string> pathRessources,
                     std::string firstScene) {
    initialize(std::move(mapWorld), pathRessources, firstScene);
    while (isWindowOpen()) {
        deltaTime = clock.restart();
        eventGameEngine();
        updateGameEngine();
        renderGameEngine();
    }
}