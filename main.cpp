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
    menuWorld->setNameWorld("Menu");
    menuWorld->createEntities(mapEntityManager);
    menuWorld->getEntityManager("Image").getEntity("Background").addComponent<Transform>();
    menuWorld->getEntityManager("Image").getEntity("Background").addComponent<Sprite>()
            .setDeferredSprite([&]() {
                std::map<std::string, std::vector<float>> mapTransform;
                mapTransform["Position"] = std::vector<float>{0.0f, 0.0f};
                mapTransform["Scale"] = std::vector<float>{1.0f, 1.0f};
                gameEngine.getWorld("Menu").getEntityManager("Image").getEntity("Background").getComponent<Sprite>().setSprite(gameEngine.getMapTexture(), "background.jpg", false);
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
                std::map<std::string, std::vector<float>> mapTransform;
                mapTransform["Position"] = std::vector<float>{0.0f, 0.0f};
                mapTransform["Scale"] = std::vector<float>{1.0f, 1.0f};
                gameEngine.getWorld("Level1").getEntityManager("Image").getEntity("Background").getComponent<Sprite>().setSprite(gameEngine.getMapTexture(), "background2.jpg");
            });
    level1World->getEntityManager("Player").getEntity("Player1").addComponent<Transform>();
<<<<<<< HEAD
=======
    level1World->getEntityManager("Player").getEntity("Player1").getComponent<Transform>().setPosition(Vector2<float>(1000.0f, 500.0f));
>>>>>>> 8bf355f ([m] Engine:)
    level1World->getEntityManager("Player").getEntity("Player1").addComponent<Sprite>()
            .setDeferredSprite([&]() {
                std::map<std::string, std::vector<float>> mapTransform;
                mapTransform["Position"] = std::vector<float>{0.0f, 0.0f};
                mapTransform["Scale"] = std::vector<float>{1.0f, 1.0f};
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
    level1World->getEntityManager("Player").getEntity("Player1").getComponent<Sprite>().setRotation(50.0f);
    level1World->getEntityManager("Player").getEntity("Player1").getComponent<Sprite>().setPosition();
    return level1World;
}

std::unique_ptr<World> worldLevel2() {
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
    });
    gameEngine.getEventEngine().addKeyPressed(sf::Keyboard::Z, [&]() {
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
    worldMap["Level2"] = worldLevel2();
    std::map<std::string, std::string> pathRessources;
    pathRessources["Texture"] = "src/Ressources/Textures";
    event(gameEngine);
    gameEngine.run(std::move(worldMap), pathRessources, "Menu");


//    std::map<std::string, std::vector<float>> mapTransform;
//    mapTransform["Position"] = {1.0f, 5.0f};
//    mapTransform["Rotation"] = {4.0f, 21.3f};
//    mapTransform["Scale"] = {0.0f, 0.0f};
//
//    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
//    mapEntityManager["players"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Thibault", "Pierre", "Louis"});
//
//    test.createEntities(mapEntityManager);
//
//    mapEntityManager["players"].first->getEntity("Thibault").addComponent<Transform>(mapTransform);
//    mapEntityManager["players"].first->getEntity("Louis").addComponent<Transform>();
//
//    std::cout << mapEntityManager["players"].first->getEntity("Thibault").getComponent<Transform>().getPositionVector()[0] << ", ";
//    std::cout << mapEntityManager["players"].first->getEntity("Thibault").getComponent<Transform>().getPositionVector()[1] << std::endl;
//
//    std::cout << mapEntityManager["players"].first->getEntity("Louis").getComponent<Transform>().getPositionVector()[0] << ", ";
//    std::cout << mapEntityManager["players"].first->getEntity("Louis").getComponent<Transform>().getPositionVector()[1] << std::endl;
//    players->getEntity("Thibault").addComponent<Transform>(mapTransform);
//    std::cout << &players->getEntity("Thibault").getComponent<Transform>() << std::endl;
//    std::cout << "Player: " << &player << std::endl;
//    std::cout << "main " << &player.addComponent<Transform>() << std::endl;
//    std::cout << "Name: " << player.getName() << std::endl;
//    player.setName("Louis");
//    std::cout << "Name: " << player.getName() << std::endl;
//    std::cout << &player.getComponent<Transform>() << std::endl;
//    for (const auto& element : mapTransform) {
//        std::cout << element.second[1] << std::endl;
//    }
//    std::cout << "{" << players->getEntity("Thibault").getComponent<Transform>().getPositionVector()[0] << ", ";
//    std::cout << players->getEntity("Thibault").getComponent<Transform>().getPositionVector()[1] << "}" << std::endl;
//    std::cout << "{" << players->getEntity("Thibault").getComponent<Transform>().getRotationVector()[0] << ", ";
//    std::cout << players->getEntity("Thibault").getComponent<Transform>().getRotationVector()[1] << "}" << std::endl;
//    std::cout << "{" << players->getEntity("Thibault").getComponent<Transform>().getScaleVector()[0] << ", ";
//    std::cout << players->getEntity("Thibault").getComponent<Transform>().getScaleVector()[1] << "}" << std::endl;
//    std::cout << std::endl;
//    std::cout << "{" << player.getComponent<Transform>().getPositionVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getPositionVector()[1] << "}" << std::endl;
//    std::cout << "{" << player.getComponent<Transform>().getRotationVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getRotationVector()[1] << "}" << std::endl;
//    std::cout << "{" << player.getComponent<Transform>().getScaleVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getScaleVector()[1] << "}" << std::endl;
//    player.getComponent<Transform>().setTransform(mapTransform);
//    std::cout << "{" << player.getComponent<Transform>().getPositionVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getPositionVector()[1] << "}" << std::endl;
//    std::cout << "{" << player.getComponent<Transform>().getRotationVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getRotationVector()[1] << "}" << std::endl;
//    std::cout << "{" << player.getComponent<Transform>().getScaleVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getScaleVector()[1] << "}" << std::endl;



//    Sprite rendering("assets/red.png");
//    if (rendering.getSprite().getTexture() == nullptr) {
//        std::cout << "Texture is null" << std::endl;
//    } else {
//        std::cout << "Texture is not null" << std::endl;
//    }
//
//    rendering.setTexture("assets/blue.png");
//    rendering.createSprite();
//
//    if (rendering.getSprite().getTexture() == nullptr) {
//        std::cout << "Texture is null" << std::endl;
//    } else {
//        std::cout << "Texture is not null" << std::endl;
//    }
    return 0;
}
