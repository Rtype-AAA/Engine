//
// Created by thibaultcampagne on 29/11/23.
//

#include "main.h"

std::unique_ptr<World> worldMenu(GameEngine &gameEngine) {
    std::unique_ptr<World> menuWorld = std::make_unique<World>();
    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Image"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Background"});
    mapEntityManager["Text"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Title"});
    mapEntityManager["Button"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Play", "Option", "Quit"});
    mapEntityManager["Music"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Music"});
    menuWorld->setNameWorld("Menu");
    menuWorld->createEntities(mapEntityManager);
    menuWorld->getEntityManager("Image").getEntity("Background").addComponent<Transform>();
    menuWorld->getEntityManager("Image").getEntity("Background").addComponent<Sprite>()
            .setDeferredSprite([&]() {
                gameEngine.getWorld("Menu").getEntityManager("Image").getEntity("Background").getComponent<Sprite>().setSprite(gameEngine.getMapTexture(), "background.jpg", false);
            });
    menuWorld->getEntityManager("Music").getEntity("Music").addComponent<Music>()
            .setDeferredMusic([&]() {
                gameEngine.getWorld("Menu").getEntityManager("Music").getEntity("Music").getComponent<Music>().setMusic(gameEngine.getMapMusic(), "Music.wav");
                gameEngine.getWorld("Menu").getEntityManager("Music").getEntity("Music").getComponent<Music>().play();
            });
    menuWorld->getEntityManager("Text").getEntity("Title").addComponent<Transform>();
    menuWorld->getEntityManager("Text").getEntity("Title").addComponent<Text>()
            .setDeferredText([&]() {
                gameEngine.getWorld("Menu").getEntityManager("Text").getEntity("Title").getComponent<Text>().setText(
                        gameEngine.getMapFont(), "font1.ttf", "Nebula Strike", 150, Color::Green);
            });
    menuWorld->getEntityManager("Menu").getEntity("Background").addComponent<Sound>()
            .setDeferredSound([&]() {
                gameEngine.getWorld("Menu").getEntityManager("Menu").getEntity("Background").getComponent<Sound>().setSound(gameEngine.getMapSound(), "Laser.flac");

            });
    return menuWorld;
}

std::unique_ptr<World> worldLevel1(GameEngine &gameEngine) {
    std::unique_ptr<World> level1World = std::make_unique<World>();
    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Image"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Background"});
    mapEntityManager["Text"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Paragraph"});
    mapEntityManager["Player"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Player1"});
    level1World->setNameWorld("Level1");
    level1World->createEntities(mapEntityManager);
    level1World->getEntityManager("Image").getEntity("Background").addComponent<Transform>();
    level1World->getEntityManager("Image").getEntity("Background").addComponent<Sprite>()
            .setDeferredSprite([&]() {
                gameEngine.getWorld("Level1").getEntityManager("Image").getEntity("Background").getComponent<Sprite>().setSprite(gameEngine.getMapTexture(), "background2.jpg");
            });
    level1World->getEntityManager("Player").getEntity("Player1").addComponent<Transform>().setPosition(Vector2<float>(400.0f, 500.0f));
    level1World->getEntityManager("Player").getEntity("Player1").addComponent<Sprite>()
            .setDeferredSprite([&]() {
                std::vector<Rect<int>> frames;
                frames.emplace_back(0, 0, 33, 36);
                frames.emplace_back(33, 0, 33, 36);
                frames.emplace_back(66, 0, 33, 36);
                frames.emplace_back(99, 0, 33, 36);
                frames.emplace_back(132, 0, 33, 36);
                frames.emplace_back(165, 0, 33, 36);
                frames.emplace_back(198, 0, 33, 36);
                frames.emplace_back(231, 0, 33, 36);
                frames.emplace_back(264, 0, 33, 36);
                frames.emplace_back(297, 0, 33, 36);
                frames.emplace_back(330, 0, 33, 36);
                frames.emplace_back(363, 0, 33, 36);
                frames.emplace_back(396, 0, 33, 36);
                frames.emplace_back(429, 0, 33, 36);
                frames.emplace_back(462, 0, 33, 36);
                frames.emplace_back(495, 0, 33, 36);
                gameEngine.getWorld("Level1").getEntityManager("Player").getEntity("Player1").getComponent<Sprite>().setSprite(gameEngine.getMapTexture(), "r-typesheet5.gif", true, frames, 100);
            });
    level1World->getEntityManager("Player").getEntity("Player1").addComponent<Sound>()
            .setDeferredSound([&]() {
                gameEngine.getWorld("Level1").getEntityManager("Player").getEntity("Player1").getComponent<Sound>().setSound(gameEngine.getMapSound(), "Laser.flac");

    });
    level1World->getEntityManager("Player").getEntity("Player1").getComponent<Transform>()
            .setDeferredTransform([&]() {
                auto& transform = gameEngine.getWorld("Level1").getEntityManager("Player").getEntity("Player1").getComponent<Transform>();
                Vector2<float> position;
                position.setX(static_cast<float>(transform.getPosition().getX() + 20 * gameEngine.getDeltaTime().asSeconds()));
                position.setY(static_cast<float>(transform.getPosition().getY() + 0 * gameEngine.getDeltaTime().asSeconds()));
//                transform.setPosition(position);
            });
    return level1World;
}

std::unique_ptr<World> worldLevel2(GameEngine& gameEngine) {
    std::unique_ptr<World> level2World = std::make_unique<World>();
    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Image"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Background"});
    mapEntityManager["Text"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Paragraph"});
    mapEntityManager["Player"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Player1"});
    mapEntityManager["Enemy"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Robot", "Alien"});
    level2World->setNameWorld("Level2");
    level2World->createEntities(mapEntityManager);
    return level2World;
}

void event(GameEngine &gameEngine) {
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::A, [&]() {
        gameEngine.setCurrentWorld(&gameEngine.getWorld("Menu"));
        gameEngine.getCurrentWorld()->getEntityManager("Music").getEntity("Music").getComponent<Music>().play();
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::W, [&]() {
        if (gameEngine.getCurrentWorld()->getNameWorld() == "Menu") {
            gameEngine.getCurrentWorld()->getEntityManager("Music").getEntity(
                    "Music").getComponent<Music>().stop();
        }
        gameEngine.setCurrentWorld(&gameEngine.getWorld("Level1"));
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::E, [&]() {
        gameEngine.setCurrentWorld(&gameEngine.getWorld("Level2"));
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::Escape, [&]() {
        gameEngine.getWindow().close();
    });

<<<<<<< HEAD
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::R, [&]() {
        if (gameEngine.getCurrentWorld()->getNameWorld() == "Menu") {
            Entity& title = gameEngine.getWorld("Menu").getEntityManager("Text").getEntity("Title");
            if (title.getComponentBitset().test(title.getComponentTypeID<Text>())) {
                title.removeComponent<Text>();
            }
            gameEngine.getWorld("Menu").getEntityManager("Image").getEntity("Background").setActive(true);
        }
    });

    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::T, [&]() {
        if (gameEngine.getCurrentWorld()->getNameWorld() == "Menu") {
            Entity& title = gameEngine.getWorld("Menu").getEntityManager("Text").getEntity("Title");
            if (!title.getComponentBitset().test(title.getComponentTypeID<Text>())) {
                gameEngine.getWorld("Menu").getEntityManager("Text").getEntity("Title").addComponent<Text>();
                gameEngine.getWorld("Menu").getEntityManager("Text").getEntity(
                                    "Title").getComponent<Text>().setText(
                                    gameEngine.getMapFont(), "font1.ttf", "Nebula Strike", 150, Color::Green);
            }
            gameEngine.getWorld("Menu").getEntityManager("Image").getEntity("Background").setActive(false);
        }
    });
=======

>>>>>>> a81756f4 ([m] Engine:)

    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::Z, [&]() {
        auto &transform = gameEngine.getWorld("Level1").getEntityManager("Player").getEntity(
                "Player1").getComponent<Transform>();
        Vector2<float> position;
        position.setX(
                static_cast<float>(transform.getPosition().getX() +
                                   0 * gameEngine.getDeltaTime().asSeconds()));
        position.setY(
                static_cast<float>(transform.getPosition().getY() - 50 * gameEngine.getDeltaTime().asSeconds()));
        transform.setPosition(position);
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::D, [&]() {
        auto &transform = gameEngine.getWorld("Level1").getEntityManager("Player").getEntity(
                "Player1").getComponent<Transform>();
        Vector2<float> position;
        position.setX(
                static_cast<float>(transform.getPosition().getX() +
                                   50 * gameEngine.getDeltaTime().asSeconds()));
        position.setY(
                static_cast<float>(transform.getPosition().getY() + 0 * gameEngine.getDeltaTime().asSeconds()));
        transform.setPosition(position);
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::S, [&]() {
        auto &transform = gameEngine.getWorld("Level1").getEntityManager("Player").getEntity(
                "Player1").getComponent<Transform>();
        Vector2<float> position;
        position.setX(
                static_cast<float>(transform.getPosition().getX() +
                                   0 * gameEngine.getDeltaTime().asSeconds()));
        position.setY(
                static_cast<float>(transform.getPosition().getY() + 50 * gameEngine.getDeltaTime().asSeconds()));
        transform.setPosition(position);
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::Q, [&]() {
        auto &transform = gameEngine.getWorld("Level1").getEntityManager("Player").getEntity(
                "Player1").getComponent<Transform>();
        Vector2<float> position;
        position.setX(
                static_cast<float>(transform.getPosition().getX() -
                50 * gameEngine.getDeltaTime().asSeconds()));
        position.setY(
                static_cast<float>(transform.getPosition().getY() + 0 * gameEngine.getDeltaTime().asSeconds()));
        transform.setPosition(position);
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::Space, [&]() {
        if (gameEngine.getCurrentWorld()->getNameWorld() == "Level1") {
            if (!gameEngine.getCurrentWorld()->getEntityManager("Player").getEntity("Player1").getComponent<Sound>().isPlaying()) {
                gameEngine.getCurrentWorld()->getEntityManager("Player").getEntity("Player1").getComponent<Sound>().play();
            }
        } else if (gameEngine.getCurrentWorld()->getNameWorld() == "Menu") {
            gameEngine.getCurrentWorld()->getEntityManager("Menu").getEntity("Background").getComponent<Sound>().play();
        }
    });
    gameEngine.getEventEngine().addMouseButtonPressed(sf::Mouse::Left, [&]() {
        std::cout << "Clique gauche pressé" << std::endl;
    });
    gameEngine.getEventEngine().addMouseMoved("Player1", [&]() {
        std::cout << "Sur le sprite" << std::endl;
    });
}

int main() {
    GameEngine gameEngine(sf::VideoMode(1920, 1080), "SFML Window");
    std::map<std::string, std::unique_ptr<World>> worldMap;
    worldMap["Menu"] = worldMenu(gameEngine);
    worldMap["Level1"] = worldLevel1(gameEngine);
    worldMap["Level2"] = worldLevel2(gameEngine);
    std::map<std::string, std::string> pathRessources;
    pathRessources["Texture"] = "src/Ressources/Textures";
    pathRessources["Sounds"] = "src/Ressources/Sounds";
    pathRessources["Musics"] = "src/Ressources/Music";
    pathRessources["Font"] = "src/Ressources/Font";
    event(gameEngine);
    gameEngine.run(std::move(worldMap), pathRessources, "Menu");
    return 0;
}