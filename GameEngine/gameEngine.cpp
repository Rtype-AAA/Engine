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

std::vector<std::string> getFilesTexture(std::string pathDirectory) {
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
        mapTexture[element] = std::make_unique<sf::Texture>();
        if (!mapTexture[element]->loadFromFile(path + element)) {
            std::cerr << "Erreur lors du chargement de la texture : " + path + element << std::endl;
            exit(1);
        } else {
            std::cout << "Chargement de la texture avec succès : " + path + element << std::endl;
        }
    }
}

void GameEngine::initialize(std::map<std::string, std::string> pathRessources) {
    for (const auto& element : pathRessources) {
        if (element.first == "Textures" || element.first == "Texture") {
            initializeTexture(element.second);
        } else {
            std::cout << "Le type de ressource n'existe pas, veuillez choisir parmis ceux disponible." << std::endl;
            exit(0);
        }
    }
}

bool GameEngine::isWindowOpen() {
    return std::visit([](const auto& w) -> bool {
        return w->isOpen();
    }, window);
}

void GameEngine::updateGameEngine() {
    return;
}

void GameEngine::renderGameEngine() {
    std::visit([](auto& w) {
        if constexpr (std::is_same_v<std::decay_t<decltype(*w)>, sf::RenderWindow>) {
            w->clear();
            w->display();
        }
    }, window);
}

void GameEngine::eventGameEngine() {
    std::visit([this](auto& w) {
        while (w->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    w->close();
                    break;
            }
        }
    }, window);
}

void GameEngine::run(std::map<std::string, std::unique_ptr<World>> mapWorld,
                     std::map<std::string, std::string> pathRessources) {
    initialize(pathRessources);
//    while (isWindowOpen()) {
//        eventGameEngine();
//        updateGameEngine();
//        renderGameEngine();
//    }
}
