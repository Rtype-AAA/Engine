#include "gtest/gtest.h"
#include "../../src/GameEngine/gameEngine.h"

class GameEngineTest : public ::testing::Test
{
protected:
    GameEngine *gameEngine;

    void TearDown() override
    {
        delete gameEngine;
    }
};

TEST_F(GameEngineTest, DefaultConstructor)
{
    gameEngine = new GameEngine();

    ASSERT_EQ(gameEngine->getWorldMap().size(), 0);
    ASSERT_EQ(gameEngine->getMapTexture().size(), 0);
    ASSERT_EQ(gameEngine->getWindow().index(), 0);
}

TEST_F(GameEngineTest, ConstructorWithParameters)
{
    sf::VideoMode mode(800, 600);
    std::string type = "2D";
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, type, title, style, settings);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 0);
    ASSERT_EQ(gameEngine->getMapTexture().size(), 0);
    ASSERT_EQ(gameEngine->getWindow().index(), 1);
}

TEST_F(GameEngineTest, IsWindowOpen)
{
    sf::VideoMode mode(800, 600);
    std::string type = "2D";
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, type, title, style, settings);

    ASSERT_TRUE(gameEngine->isWindowOpen());
}

TEST_F(GameEngineTest, Initialize) {
    sf::VideoMode mode(800, 600);
    std::string type = "2D";
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, type, title, style, settings);

    std::string path = "tests/assets/Textures";


    std::map<std::string, std::unique_ptr<World>> mapWorld{};

    std::string nameWorld = "TestWorld";

    std::unique_ptr<World> worldPtr = std::make_unique<World>();
    worldPtr->setNameWorld(nameWorld);

    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Image"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"red"});
    worldPtr->createEntities(mapEntityManager, nameWorld);

    worldPtr->getEntityManager(nameWorld).getEntity("red").addComponent<Sprite>().setDeferredSprite([&]()
                                                                                                  {
            std::map<std::string, std::vector<float>> mapTransform;
            mapTransform["Position"] = std::vector<float>{0.0f, 0.0f};
            mapTransform["Scale"] = std::vector<float>{1.0f, 1.0f};
            gameEngine->getWorld(nameWorld).getEntityManager(nameWorld).getEntity("red").getComponent<Sprite>().setSprite(gameEngine->getMapTexture(), "red.png", mapTransform); });

    mapWorld[nameWorld] = std::move(worldPtr);

    gameEngine->initialize(std::move(mapWorld), std::map<std::string, std::string>{{"Textures", path}}, nameWorld);

    ASSERT_EQ(gameEngine->getMapTexture().size(), 2);

    std::map<std::string, World *> worldMap = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap.begin()->second->getEntityManagerMap().size(), 1);

    std::map<std::string, EntityManager *> entityManagers = worldMap.begin()->second->getEntityManagerMap();

    ASSERT_EQ(entityManagers.begin()->second->getEntityMap().size(), 1);

    std::map<std::string, Entity *> entities = entityManagers.begin()->second->getEntityMap();

    ASSERT_EQ(entities.size(), 1);

    ASSERT_NE(gameEngine->getMapTexture()["red.png"].getSize().x, 0);

    ASSERT_NE(gameEngine, nullptr);
    ASSERT_NE(gameEngine->getWorldMap().begin()->second, nullptr);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().begin()->second->getEntityMap().size(), 1);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);

    std::map<std::string, World *> worldMap2 = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap2.begin()->first, nameWorld);

    sf::Sprite initializedSprite = worldMap2[nameWorld]->getEntityManager(nameWorld).getEntity("red").getComponent<Sprite>().getSprite();

    ASSERT_NE(initializedSprite.getTexture(), nullptr);
}

TEST_F(GameEngineTest, InitializeSprite)
{
    sf::VideoMode mode(800, 600);
    std::string type = "2D";
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, type, title, style, settings);

    std::string path = "tests/assets/Textures";

    gameEngine->initializeTexture(path);

    ASSERT_EQ(gameEngine->getMapTexture().size(), 2);

    std::map<std::string, std::unique_ptr<World>> mapWorld{};

    std::string nameWorld = "TestWorld";

    std::unique_ptr<World> worldPtr = std::make_unique<World>();
    worldPtr->setNameWorld(nameWorld);

    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Image"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"red"});
    worldPtr->createEntities(mapEntityManager, nameWorld);

    worldPtr->getEntityManager(nameWorld).getEntity("red").addComponent<Sprite>().setDeferredSprite([&]()
                                                                                                  {
            std::map<std::string, std::vector<float>> mapTransform;
            mapTransform["Position"] = std::vector<float>{0.0f, 0.0f};
            mapTransform["Scale"] = std::vector<float>{1.0f, 1.0f};
            gameEngine->getWorld(nameWorld).getEntityManager(nameWorld).getEntity("red").getComponent<Sprite>().setSprite(gameEngine->getMapTexture(), "red.png", mapTransform); });

    mapWorld[nameWorld] = std::move(worldPtr);

    gameEngine->initializeWorldMap(std::move(mapWorld));

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);

    std::map<std::string, World *> worldMap = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap.begin()->second->getEntityManagerMap().size(), 1);

    std::map<std::string, EntityManager *> entityManagers = worldMap.begin()->second->getEntityManagerMap();

    ASSERT_EQ(entityManagers.begin()->second->getEntityMap().size(), 1);

    std::map<std::string, Entity *> entities = entityManagers.begin()->second->getEntityMap();

    ASSERT_EQ(entities.size(), 1);

    ASSERT_NE(gameEngine->getMapTexture()["red.png"].getSize().x, 0);

    ASSERT_NE(gameEngine, nullptr);
    ASSERT_NE(gameEngine->getWorldMap().begin()->second, nullptr);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().begin()->second->getEntityMap().size(), 1);

    gameEngine->initializeSprite();

    std::map<std::string, World *> worldMap2 = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap2.begin()->first, nameWorld);

    sf::Sprite initializedSprite = worldMap2[nameWorld]->getEntityManager(nameWorld).getEntity("red").getComponent<Sprite>().getSprite();

    ASSERT_NE(initializedSprite.getTexture(), nullptr);
}

TEST_F(GameEngineTest, InitializeTexture)
{
    sf::VideoMode mode(800, 600);
    std::string type = "2D";
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, type, title, style, settings);

    ASSERT_EQ(gameEngine->getMapTexture().size(), 0);

    std::string path = "tests/assets/Textures";

    gameEngine->initializeTexture(path);

    ASSERT_EQ(gameEngine->getMapTexture().size(), 2);

    std::map<std::string, sf::Texture> mapTexture = gameEngine->getMapTexture();

    ASSERT_TRUE(mapTexture.find("blue.png") != mapTexture.end());
    ASSERT_TRUE(mapTexture.find("red.png") != mapTexture.end());
}

TEST_F(GameEngineTest, InitializeWorldMap)
{
    sf::VideoMode mode(800, 600);
    std::string type = "2D";
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, type, title, style, settings);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 0);

    std::map<std::string, std::unique_ptr<World>> mapWorld{};

    std::string nameWorld = "TestWorld";

    std::unique_ptr<World> worldPtr = std::make_unique<World>();
    worldPtr->setNameWorld(nameWorld);

    mapWorld[nameWorld] = std::move(worldPtr);

    gameEngine->initializeWorldMap(std::move(mapWorld));

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);

    std::map<std::string, World *> worldMap = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap.begin()->first, nameWorld);
    ASSERT_EQ(worldMap.begin()->second->getNameWorld(), nameWorld);
}

TEST_F(GameEngineTest, GetWindow)
{
    sf::VideoMode mode(800, 600);
    std::string type = "2D";
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, type, title, style, settings);

    ASSERT_EQ(gameEngine->getWindow().index(), 1);

    auto &windowVariant = gameEngine->getWindow();

    ASSERT_TRUE(std::holds_alternative<std::unique_ptr<sf::RenderWindow>>(windowVariant));

    auto *renderWindowPtr = std::get_if<std::unique_ptr<sf::RenderWindow>>(&windowVariant);
    ASSERT_TRUE(renderWindowPtr != nullptr);

    ASSERT_TRUE(*renderWindowPtr != nullptr);
}

TEST_F(GameEngineTest, GetEventEngine)
{
    sf::VideoMode mode(800, 600);
    std::string type = "2D";
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, type, title, style, settings);

    ASSERT_TRUE(gameEngine->getEventEngine().init());
    ASSERT_EQ(gameEngine->getEventEngine().getKeyPressedMap().size(), 0);

    gameEngine->getEventEngine().addKeyPressed(sf::Keyboard::Key::A, []() {});

    ASSERT_EQ(gameEngine->getEventEngine().getKeyPressedMap().size(), 1);
    ASSERT_EQ(gameEngine->getEventEngine().getKeyPressedMap().begin()->first, sf::Keyboard::Key::A);
}

TEST_F(GameEngineTest, GetWorldMap)
{
    sf::VideoMode mode(800, 600);
    std::string type = "2D";
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, type, title, style, settings);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 0);

    std::string nameWorld = "TestWorld";

    std::unique_ptr<World> worldPtr = std::make_unique<World>();
    worldPtr->setNameWorld(nameWorld);

    gameEngine->addWorld(nameWorld, std::move(worldPtr));

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);

    std::map<std::string, World *> worldMap = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap.begin()->first, nameWorld);
    ASSERT_EQ(worldMap.begin()->second->getNameWorld(), nameWorld);
}
