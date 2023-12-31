//
// Created by thibaultcampagne on 29/11/23.
//

#include "src/GameEngine/gameEngine.h"

std::unique_ptr<World> worldMenu(GameEngine &gameEngine) {
    std::unique_ptr<World> menuWorld = std::make_unique<World>();
    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Image"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Background"});
    mapEntityManager["Text"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Title"});
    mapEntityManager["Button"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Play", "Option", "Quit"});
    menuWorld->setNameWorld("Menu");
    menuWorld->createEntities(mapEntityManager, "Menu");
    menuWorld->getEntityManager("Menu").getEntity("Background").addComponent<Transform>();
    menuWorld->getEntityManager("Menu").getEntity("Background").addComponent<Sprite>()
            .setDeferredSprite([&]() {
                gameEngine.getWorld("Menu").getEntityManager("Menu").getEntity("Background").getComponent<Sprite>().setSprite(gameEngine.getMapTexture(), "background.jpg");
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
    level1World->createEntities(mapEntityManager, "Level1");
    level1World->getEntityManager("Level1").getEntity("Background").addComponent<Transform>();
    level1World->getEntityManager("Level1").getEntity("Background").addComponent<Sprite>()
            .setDeferredSprite([&]() {
                gameEngine.getWorld("Level1").getEntityManager("Level1").getEntity("Background").getComponent<Sprite>().setSprite(gameEngine.getMapTexture(), "background2.jpg");
            });
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
    level2World->createEntities(mapEntityManager, "Level2");
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
}

int main() {
//    Entity player("Louis");
//    World test;
    GameEngine gameEngine(sf::VideoMode(1920, 1080), "2d", "SFML Window");
    std::map<std::string, std::unique_ptr<World>> worldMap;
    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Menu"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Background"});
    mapEntityManager["Level1"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Background"});
    mapEntityManager["Level2"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Light"});
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