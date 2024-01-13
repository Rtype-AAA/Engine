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
    level1World->getEntityManager("Player").getEntity("Player1").addComponent<Transform>().setTransformPosition(Vector2<float>(1000.0f, 500.0f));
    level1World->getEntityManager("Player").getEntity("Player1").addComponent<Sprite>()
            .setDeferredSprite([&]() {
                std::vector<Rect<int>> frames;
                frames.push_back(Rect<int>(0, 0, 33, 36));
                frames.push_back(Rect<int>(33, 0, 33, 36));
                frames.push_back(Rect<int>(66, 0, 33, 36));
                frames.push_back(Rect<int>(99, 0, 33, 36));
                frames.push_back(Rect<int>(132, 0, 33, 36));
                frames.push_back(Rect<int>(165, 0, 33, 36));
                frames.push_back(Rect<int>(198, 0, 33, 36));
                frames.push_back(Rect<int>(231, 0, 33, 36));
                frames.push_back(Rect<int>(264, 0, 33, 36));
                frames.push_back(Rect<int>(297, 0, 33, 36));
                frames.push_back(Rect<int>(330, 0, 33, 36));
                frames.push_back(Rect<int>(363, 0, 33, 36));
                frames.push_back(Rect<int>(396, 0, 33, 36));
                frames.push_back(Rect<int>(429, 0, 33, 36));
                frames.push_back(Rect<int>(462, 0, 33, 36));
                frames.push_back(Rect<int>(495, 0, 33, 36));
                gameEngine.getWorld("Level1").getEntityManager("Player").getEntity("Player1").getComponent<Sprite>().setSprite(gameEngine.getMapTexture(), "r-typesheet5.gif", true, frames, 100);
            });
    level1World->getEntityManager("Player").getEntity("Player1").getComponent<Sprite>().setPosition();
    level1World->getEntityManager("Player").getEntity("Player1").addComponent<Sound>()
            .setDeferredSound([&]() {
                gameEngine.getWorld("Level1").getEntityManager("Player").getEntity("Player1").getComponent<Sound>().setSound(gameEngine.getMapSound(), "Laser.flac");

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
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::Z, [&]() {
        if (gameEngine.getCurrentWorld()->getNameWorld() == "Menu") {
            gameEngine.getCurrentWorld()->getEntityManager("Music").getEntity(
                    "Music").getComponent<Music>().stop();
        }
        gameEngine.setCurrentWorld(&gameEngine.getWorld("Level1"));
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::E, [&]() {
        gameEngine.setCurrentWorld(&gameEngine.getWorld("Level2"));
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::S, [&]() {
        std::cout << gameEngine.getCurrentWorld()->getNameWorld() << std::endl;
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::Q, [&]() {
        std::visit([](auto& w) {
            w->close();

        }, gameEngine.getWindow());
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::Space, [&] () {
        if (gameEngine.getCurrentWorld()->getNameWorld() == "Level1") {
            gameEngine.getCurrentWorld()->getEntityManager("Player").getEntity("Player1").getComponent<Sound>().play();
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
    GameEngine gameEngine(sf::VideoMode(1920, 1080), "2d", "SFML Window");
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
