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

std::vector<std::string> GameEngine::getFilesTexture(std::string pathDirectory) {
    if (!std::filesystem::exists(pathDirectory) || !std::filesystem::is_directory(pathDirectory)) {
        std::cerr << "Dossier non trouvé ou chemin non valide." << std::endl;
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
    allFilesName = getFilesTexture(path);
    path += "/";
    for (const auto& element : allFilesName) {
        if (!texture.loadFromFile(path + element)) {
            std::cerr << "Erreur lors du chargement de la texture : " + path + element << std::endl;
            exit(1);
        } else {
            std::cout << "Chargement de la texture avec succès : " + path + element << std::endl;
        }
        mapTexture[element] = std::make_shared<sf::Texture>(texture);
    }
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

void GameEngine::initializeSprite() {
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

void GameEngine::initialize(std::map<std::string, std::unique_ptr<World>> mapWorld,
                            std::map<std::string, std::string> pathRessources,
                            std::string firstScene) {
    for (const auto& element : pathRessources) {
        if (element.first == "Textures" || element.first == "Texture") {
            initializeTexture(element.second);
        } else {
            std::cout << "Le type de ressource n'existe pas, veuillez choisir parmis ceux disponible." << std::endl;
            exit(0);
        }
    }
    initializeWorldMap(std::move(mapWorld));
    for (const auto& element : worldMap) {
        const std::string key = element.first;

        if (key == firstScene) {
            currentWorld = worldMap[key];
            break;
        }
    }
    if (!mapTexture.empty()) {
        initializeSprite();
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
                                                break;
                                            }
                                        }
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