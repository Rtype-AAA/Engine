#include "gtest/gtest.h"
#include "gameEngine.h"

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
}

TEST_F(GameEngineTest, ConstructorWithParameters)
{
    sf::VideoMode mode(800, 600);
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, title, style, settings);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 0);
    ASSERT_EQ(gameEngine->getMapTexture().size(), 0);
}

TEST_F(GameEngineTest, IsWindowOpen)
{
    sf::VideoMode mode(800, 600);
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, title, style, settings);

    ASSERT_TRUE(gameEngine->isWindowOpen());
}

TEST_F(GameEngineTest, GetFilesTexture) {
    gameEngine = new GameEngine();

    std::string path = "tests/assets/Textures";

    std::vector<std::string> allFilesName = gameEngine->getFilesRessources(path);

    ASSERT_EQ(allFilesName.size(), 2);

    ASSERT_TRUE(std::find(allFilesName.begin(), allFilesName.end(), "blue.png") != allFilesName.end());
    ASSERT_TRUE(std::find(allFilesName.begin(), allFilesName.end(), "red.png") != allFilesName.end());
}

TEST_F(GameEngineTest, Initialize) {
    sf::VideoMode mode(800, 600);
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, title, style, settings);

    std::string path = "tests/assets/Textures";

    std::map<std::string, std::unique_ptr<World>> mapWorld{};

    std::string nameWorld = "TestWorld";

    std::unique_ptr<World> worldPtr = std::make_unique<World>();
    worldPtr->setNameWorld(nameWorld);

    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Image"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"red"});
    worldPtr->createEntities(mapEntityManager);

    auto helloWorldFunction = [&]() { gameEngine->getWorld(nameWorld).getEntityManager("Image").getEntity("red").getComponent<Sprite>().setSprite(gameEngine->getMapTexture(), "red.png"); };

    worldPtr->getEntityManager("Image").getEntity("red").addComponent<Transform>();
    worldPtr->getEntityManager("Image").getEntity("red").addComponent<Sprite>().setDeferredSprite(helloWorldFunction);

    mapWorld[nameWorld] = std::move(worldPtr);

    gameEngine->initialize(std::move(mapWorld), std::map<std::string, std::string>{{"Textures", path}}, nameWorld);

    ASSERT_EQ(gameEngine->getMapTexture().size(), 2);

    std::map<std::string, World *> worldMap = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap.begin()->second->getEntityManagerMap().size(), 1);

    std::map<std::string, EntityManager *> entityManagers = worldMap.begin()->second->getEntityManagerMap();

    ASSERT_EQ(entityManagers.begin()->second->getEntityMap().size(), 1);

    std::map<std::string, Entity *> entities = entityManagers.begin()->second->getEntityMap();

    ASSERT_EQ(entities.size(), 1);

    ASSERT_NE(gameEngine->getMapTexture()["red.png"]->getSize().x, 0);

    ASSERT_NE(gameEngine, nullptr);
    ASSERT_NE(gameEngine->getWorldMap().begin()->second, nullptr);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().begin()->second->getEntityMap().size(), 1);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);

    std::map<std::string, World *> worldMap2 = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap2.begin()->first, nameWorld);

    sf::Sprite initializedSprite = worldMap2[nameWorld]->getEntityManager("Image").getEntity("red").getComponent<Sprite>().getSprite();

    ASSERT_NE(initializedSprite.getTexture(), nullptr);
}

TEST_F(GameEngineTest, InitializeSpriteFunction)
{
    sf::VideoMode mode(800, 600);
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, title, style, settings);

    std::string path = "tests/assets/Textures";

    gameEngine->initializeTexture(path);

    ASSERT_EQ(gameEngine->getMapTexture().size(), 2);

    std::map<std::string, std::unique_ptr<World>> mapWorld{};

    std::string nameWorld = "TestWorld";

    std::unique_ptr<World> worldPtr = std::make_unique<World>();
    worldPtr->setNameWorld(nameWorld);

    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Image"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"red"});
    worldPtr->createEntities(mapEntityManager);

    worldPtr->getEntityManager("Image").getEntity("red").addComponent<Transform>();
    worldPtr->getEntityManager("Image").getEntity("red").addComponent<Sprite>().setDeferredSprite([&]()
                                                                                                  {
            gameEngine->getWorld(nameWorld).getEntityManager("Image").getEntity("red").getComponent<Sprite>().setSprite(gameEngine->getMapTexture(), "red.png"); });

    mapWorld[nameWorld] = std::move(worldPtr);

    gameEngine->initializeWorldMap(std::move(mapWorld));

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);

    std::map<std::string, World *> worldMap = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap.begin()->second->getEntityManagerMap().size(), 1);

    std::map<std::string, EntityManager *> entityManagers = worldMap.begin()->second->getEntityManagerMap();

    ASSERT_EQ(entityManagers.begin()->second->getEntityMap().size(), 1);

    std::map<std::string, Entity *> entities = entityManagers.begin()->second->getEntityMap();

    ASSERT_EQ(entities.size(), 1);

    ASSERT_NE(gameEngine->getMapTexture()["red.png"]->getSize().x, 0);

    ASSERT_NE(gameEngine, nullptr);
    ASSERT_NE(gameEngine->getWorldMap().begin()->second, nullptr);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().begin()->second->getEntityMap().size(), 1);

    gameEngine->initializeSpriteFunction();

    std::map<std::string, World *> worldMap2 = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap2.begin()->first, nameWorld);

    sf::Sprite initializedSprite = worldMap2[nameWorld]->getEntityManager("Image").getEntity("red").getComponent<Sprite>().getSprite();

    ASSERT_NE(initializedSprite.getTexture(), nullptr);
}

TEST_F(GameEngineTest, InitializeSoundFunction) {
    gameEngine = new GameEngine();

    std::string path = "tests/assets/Sounds";

    gameEngine->initializeSound(path);

    ASSERT_EQ(gameEngine->getMapSound().size(), 2);

    std::map<std::string, std::unique_ptr<World>> mapWorld{};

    std::string nameWorld = "TestWorld";

    std::unique_ptr<World> worldPtr = std::make_unique<World>();
    worldPtr->setNameWorld(nameWorld);

    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Sound"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"test1"});
    worldPtr->createEntities(mapEntityManager);

    worldPtr->getEntityManager("Sound").getEntity("test1").addComponent<Sound>().setDeferredSound([&]()
                                                                                                  {
            gameEngine->getWorld(nameWorld).getEntityManager("Sound").getEntity("test1").getComponent<Sound>().setSound(gameEngine->getMapSound(), "test1.ogg"); });

    mapWorld[nameWorld] = std::move(worldPtr);

    gameEngine->initializeWorldMap(std::move(mapWorld));

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);

    std::map<std::string, World *> worldMap = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap.begin()->second->getEntityManagerMap().size(), 1);

    std::map<std::string, EntityManager *> entityManagers = worldMap.begin()->second->getEntityManagerMap();

    ASSERT_EQ(entityManagers.begin()->second->getEntityMap().size(), 1);

    std::map<std::string, Entity *> entities = entityManagers.begin()->second->getEntityMap();

    ASSERT_EQ(entities.size(), 1);

    ASSERT_NE(gameEngine->getMapSound()["test1.ogg"]->getDuration().asSeconds(), 0);

    ASSERT_NE(gameEngine, nullptr);
    ASSERT_NE(gameEngine->getWorldMap().begin()->second, nullptr);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().begin()->second->getEntityMap().size(), 1);
}

TEST_F(GameEngineTest, InitializeMusicFunction) {
    gameEngine = new GameEngine();

    std::string path = "tests/assets/Sounds";

    gameEngine->initializeMusic(path);

    ASSERT_EQ(gameEngine->getMapMusic().size(), 2);

    std::map<std::string, std::unique_ptr<World>> mapWorld{};

    std::string nameWorld = "TestWorld";

    std::unique_ptr<World> worldPtr = std::make_unique<World>();
    worldPtr->setNameWorld(nameWorld);

    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Music"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"test1"});
    worldPtr->createEntities(mapEntityManager);

    mapWorld[nameWorld] = std::move(worldPtr);

    gameEngine->initializeWorldMap(std::move(mapWorld));

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);

    gameEngine->getWorldMap()["TestWorld"]->getEntityManager("Music").getEntity("test1").addComponent<Music>().setDeferredMusic([&]()
                                                                                                  {
            gameEngine->getWorld(nameWorld).getEntityManager("Music").getEntity("test1").getComponent<Music>().setMusic(gameEngine->getMapMusic(), "test1.ogg"); });

    gameEngine->initializeMusicFunction();

    std::map<std::string, World *> worldMap = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap.begin()->second->getEntityManagerMap().size(), 1);

    std::map<std::string, EntityManager *> entityManagers = worldMap.begin()->second->getEntityManagerMap();

    ASSERT_EQ(entityManagers.begin()->second->getEntityMap().size(), 1);

    std::map<std::string, Entity *> entities = entityManagers.begin()->second->getEntityMap();

    ASSERT_EQ(entities.size(), 1);

    ASSERT_NE(gameEngine->getMapMusic()["test1.ogg"]->getDuration().asSeconds(), 0);

    ASSERT_NE(gameEngine, nullptr);
    ASSERT_NE(gameEngine->getWorldMap().begin()->second, nullptr);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().begin()->second->getEntityMap().size(), 1);
}

TEST_F(GameEngineTest, InitializeTextFunction) {
    gameEngine = new GameEngine();

    std::string path = "tests/assets/Fonts";

    gameEngine->initializeFont(path);

    ASSERT_EQ(gameEngine->getMapFont().size(), 2);

    std::map<std::string, std::unique_ptr<World>> mapWorld{};

    std::string nameWorld = "TestWorld";

    std::unique_ptr<World> worldPtr = std::make_unique<World>();
    worldPtr->setNameWorld(nameWorld);

    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["Text"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"test1"});
    worldPtr->createEntities(mapEntityManager);

    Color color;

    mapWorld[nameWorld] = std::move(worldPtr);

    gameEngine->initializeWorldMap(std::move(mapWorld));

    gameEngine->getWorldMap()["TestWorld"]->getEntityManager("Text").getEntity("test1").addComponent<Text>().setDeferredText([&]()
                                                                                                  {
            gameEngine->getWorld(nameWorld).getEntityManager("Text").getEntity("test1").getComponent<Text>().setText(gameEngine->getMapFont(), "test1.ttf", "test1", 14, color); });

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);

    gameEngine->initializeTextFunction();

    std::map<std::string, World *> worldMap = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap.begin()->second->getEntityManagerMap().size(), 1);

    std::map<std::string, EntityManager *> entityManagers = worldMap.begin()->second->getEntityManagerMap();

    ASSERT_EQ(entityManagers.begin()->second->getEntityMap().size(), 1);

    std::map<std::string, Entity *> entities = entityManagers.begin()->second->getEntityMap();

    ASSERT_EQ(entities.size(), 1);

    ASSERT_NE(gameEngine->getMapFont()["test1.ttf"]->getInfo().family, "");

    ASSERT_NE(gameEngine, nullptr);
    ASSERT_NE(gameEngine->getWorldMap().begin()->second, nullptr);

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().size(), 1);
    ASSERT_EQ(gameEngine->getWorldMap().begin()->second->getEntityManagerMap().begin()->second->getEntityMap().size(), 1);

    sf::Text initializedText = worldMap["TestWorld"]->getEntityManager("Text").getEntity("test1").getComponent<Text>().getText();

    ASSERT_NE(initializedText.getFont(), nullptr);
    ASSERT_EQ(initializedText.getFont()->getInfo().family, "Roboto");

    ASSERT_EQ(initializedText.getString(), "test1");
    ASSERT_EQ(initializedText.getCharacterSize(), 14);
}

TEST_F(GameEngineTest, InitializeAllFiles) {
    gameEngine = new GameEngine();

    std::string path = "tests/assets/Textures";
    std::string path2 = "tests/assets/Sounds";
    std::string path3 = "tests/assets/Fonts";

    const std::map<std::string, std::string> mapPath{{"Textures", path}, {"Sounds", path2}, {"Fonts", path3}};

    gameEngine->initializeAllFiles(mapPath);

    ASSERT_EQ(gameEngine->getMapTexture().size(), 2);
    ASSERT_EQ(gameEngine->getMapSound().size(), 2);
    ASSERT_EQ(gameEngine->getMapFont().size(), 2);

    std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture = gameEngine->getMapTexture();

    ASSERT_TRUE(mapTexture.find("blue.png") != mapTexture.end());
    ASSERT_TRUE(mapTexture.find("red.png") != mapTexture.end());

    std::map<std::string, std::shared_ptr<sf::SoundBuffer>> mapSound = gameEngine->getMapSound();

    ASSERT_TRUE(mapSound.find("test1.ogg") != mapSound.end());
    ASSERT_TRUE(mapSound.find("test2.ogg") != mapSound.end());

    std::map<std::string, std::shared_ptr<sf::Font>> mapFont = gameEngine->getMapFont();

    ASSERT_TRUE(mapFont.find("test1.ttf") != mapFont.end());
    ASSERT_TRUE(mapFont.find("test2.ttf") != mapFont.end());
}

TEST_F(GameEngineTest, InitializeTexture)
{
    sf::VideoMode mode(800, 600);
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, title, style, settings);

    ASSERT_EQ(gameEngine->getMapTexture().size(), 0);

    std::string path = "tests/assets/Textures";

    gameEngine->initializeTexture(path);

    ASSERT_EQ(gameEngine->getMapTexture().size(), 2);

    std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture = gameEngine->getMapTexture();

    ASSERT_TRUE(mapTexture.find("blue.png") != mapTexture.end());
    ASSERT_TRUE(mapTexture.find("red.png") != mapTexture.end());
}

TEST_F(GameEngineTest, InitializeSound)
{
    gameEngine = new GameEngine();

    ASSERT_EQ(gameEngine->getMapSound().size(), 0);

    std::string path = "tests/assets/Sounds";

    gameEngine->initializeSound(path);

    ASSERT_EQ(gameEngine->getMapSound().size(), 2);

    std::map<std::string, std::shared_ptr<sf::SoundBuffer>> mapSound = gameEngine->getMapSound();

    ASSERT_TRUE(mapSound.find("test1.ogg") != mapSound.end());
    ASSERT_TRUE(mapSound.find("test2.ogg") != mapSound.end());
}

TEST_F(GameEngineTest, InitializeMusic)
{
    gameEngine = new GameEngine();

    ASSERT_EQ(gameEngine->getMapMusic().size(), 0);

    std::string path = "tests/assets/Sounds";

    gameEngine->initializeMusic(path);

    ASSERT_EQ(gameEngine->getMapMusic().size(), 2);

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic = gameEngine->getMapMusic();

    ASSERT_TRUE(mapMusic.find("test1.ogg") != mapMusic.end());
    ASSERT_TRUE(mapMusic.find("test2.ogg") != mapMusic.end());
}

TEST_F(GameEngineTest, InitializeFont)
{
    gameEngine = new GameEngine();

    ASSERT_EQ(gameEngine->getMapFont().size(), 0);

    std::string path = "tests/assets/Fonts";

    gameEngine->initializeFont(path);

    ASSERT_EQ(gameEngine->getMapFont().size(), 2);

    std::map<std::string, std::shared_ptr<sf::Font>> mapFont = gameEngine->getMapFont();

    ASSERT_TRUE(mapFont.find("test1.ttf") != mapFont.end());
    ASSERT_TRUE(mapFont.find("test2.ttf") != mapFont.end());
}

TEST_F(GameEngineTest, InitializeWorldMap)
{
    sf::VideoMode mode(800, 600);
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, title, style, settings);

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
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, title, style, settings);

    sf::RenderWindow *window = &gameEngine->getWindow();

    ASSERT_EQ(window->getSize().x, 800);
    ASSERT_EQ(window->getSize().y, 600);
}

TEST_F(GameEngineTest, GetEventEngine)
{
    sf::VideoMode mode(800, 600);
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, title, style, settings);

    ASSERT_EQ(gameEngine->getEventEngine().getKeyPressedMap().size(), 0);

    gameEngine->getEventEngine().addKeyPressed(sf::Keyboard::Key::A, []() {});

    ASSERT_EQ(gameEngine->getEventEngine().getKeyPressedMap().size(), 1);
    ASSERT_EQ(gameEngine->getEventEngine().getKeyPressedMap().begin()->first, sf::Keyboard::Key::A);
}

TEST_F(GameEngineTest, SetAndGetCurrentWorld) {
    gameEngine = new GameEngine();

    ASSERT_EQ(gameEngine->getCurrentWorld(), nullptr);

    std::string nameWorld = "TestWorld";

    std::unique_ptr<World> worldPtr = std::make_unique<World>();
    worldPtr->setNameWorld(nameWorld);

    gameEngine->addWorld(nameWorld, std::move(worldPtr));

    ASSERT_EQ(gameEngine->getCurrentWorld(), nullptr);

    gameEngine->setCurrentWorld(gameEngine->getWorldMap().begin()->second);

    ASSERT_EQ(gameEngine->getCurrentWorld(), gameEngine->getWorldMap().begin()->second);
}

TEST_F(GameEngineTest, AddWorld) {
    gameEngine = new GameEngine();

    ASSERT_EQ(gameEngine->getWorldMap().size(), 0);

    std::string nameWorld = "TestWorld";

    std::unique_ptr<World> worldPtr = std::make_unique<World>();
    worldPtr->setNameWorld(nameWorld);

    gameEngine->addWorld(nameWorld, std::move(worldPtr));

    ASSERT_EQ(gameEngine->getWorldMap().size(), 1);

    std::map<std::string, World *> worldMap = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap.begin()->first, nameWorld);
    ASSERT_EQ(worldMap.begin()->second->getNameWorld(), nameWorld);

    std::string nameWorld2 = "TestWorld2";

    std::unique_ptr<World> worldPtr2 = std::make_unique<World>();
    worldPtr2->setNameWorld(nameWorld2);

    gameEngine->addWorld(nameWorld2, std::move(worldPtr2));

    ASSERT_EQ(gameEngine->getWorldMap().size(), 2);

    std::map<std::string, World *> worldMap2 = gameEngine->getWorldMap();

    ASSERT_EQ(worldMap2.begin()->first, nameWorld);
    ASSERT_EQ(worldMap2.begin()->second->getNameWorld(), nameWorld);

    ASSERT_EQ((++worldMap2.begin())->first, nameWorld2);
    ASSERT_EQ((++worldMap2.begin())->second->getNameWorld(), nameWorld2);
}

TEST_F(GameEngineTest, getMapTexture)
{
    gameEngine = new GameEngine();

    ASSERT_EQ(gameEngine->getMapTexture().size(), 0);

    std::string path = "tests/assets/Textures";

    gameEngine->initializeTexture(path);

    ASSERT_EQ(gameEngine->getMapTexture().size(), 2);

    std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture = gameEngine->getMapTexture();

    ASSERT_TRUE(mapTexture.find("blue.png") != mapTexture.end());
    ASSERT_TRUE(mapTexture.find("red.png") != mapTexture.end());
}

TEST_F(GameEngineTest, GetWorldMap)
{
    sf::VideoMode mode(800, 600);
    sf::String title = "Test GameEngine";
    sf::Uint32 style = sf::Style::Default;
    sf::ContextSettings settings;

    gameEngine = new GameEngine(mode, title, style, settings);

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

TEST_F(GameEngineTest, GetMapMusic)
{
    gameEngine = new GameEngine();

    ASSERT_EQ(gameEngine->getMapMusic().size(), 0);

    std::string path = "tests/assets/Sounds";

    gameEngine->initializeMusic(path);

    ASSERT_EQ(gameEngine->getMapMusic().size(), 2);

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic = gameEngine->getMapMusic();

    ASSERT_TRUE(mapMusic.find("test1.ogg") != mapMusic.end());
    ASSERT_TRUE(mapMusic.find("test2.ogg") != mapMusic.end());
}

TEST_F(GameEngineTest, GetMapSound)
{
    gameEngine = new GameEngine();

    ASSERT_EQ(gameEngine->getMapSound().size(), 0);

    std::string path = "tests/assets/Sounds";

    gameEngine->initializeSound(path);

    ASSERT_EQ(gameEngine->getMapSound().size(), 2);

    std::map<std::string, std::shared_ptr<sf::SoundBuffer>> mapSound = gameEngine->getMapSound();

    ASSERT_TRUE(mapSound.find("test1.ogg") != mapSound.end());
    ASSERT_TRUE(mapSound.find("test2.ogg") != mapSound.end());
}

TEST_F(GameEngineTest, GetMapFont)
{
    gameEngine = new GameEngine();

    ASSERT_EQ(gameEngine->getMapFont().size(), 0);

    std::string path = "tests/assets/Fonts";

    gameEngine->initializeFont(path);

    ASSERT_EQ(gameEngine->getMapFont().size(), 2);

    std::map<std::string, std::shared_ptr<sf::Font>> mapFont = gameEngine->getMapFont();

    ASSERT_TRUE(mapFont.find("test1.ttf") != mapFont.end());
    ASSERT_TRUE(mapFont.find("test2.ttf") != mapFont.end());
}

TEST_F(GameEngineTest, SetAndGetDeltaTime) {
    gameEngine = new GameEngine();

    ASSERT_EQ(gameEngine->getDeltaTime().asSeconds(), 0);

    sf::Time time = sf::seconds(1);

    gameEngine->setDeltaTime(time);

    ASSERT_EQ(gameEngine->getDeltaTime().asSeconds(), 1);
}
