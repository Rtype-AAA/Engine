#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Sprite.h"

class SpriteTest : public ::testing::Test {
protected:
    Sprite sprite;
};

TEST_F(SpriteTest, DefaultConstructor) {
    Sprite sprite;

}

TEST_F(SpriteTest, ConstructorWithTexturePath) {
    Sprite sprite("tests/assets/red.png");

    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, Init) {
    ASSERT_TRUE(sprite.init());
}

TEST_F(SpriteTest, GetBit) {
    ASSERT_EQ(sprite.getBit(), 1);
}

TEST_F(SpriteTest, CreateSpriteWithTexturePath) {
    sprite.createSprite("tests/assets/red.png");
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, CreateSpriteWithExistingTexture) {
    sf::Texture texture;

    sprite.createSprite(texture);
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, CreateSpriteWithTheComponentTexture) {
    Sprite sprite("tests/assets/red.png");

    sprite.createSprite();
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, GetSprite) {
    Sprite sprite;

    ASSERT_EQ(sprite.getSprite().getTexture(), nullptr);

    sf::Texture texture;
    texture.loadFromFile("tests/assets/red.png");

    sf::Sprite sfprite;
    sfprite.setTexture(texture);

    ASSERT_EQ(sprite.getSprite().getTexture(), nullptr);

    sprite.setSprite(sfprite);

    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
    ASSERT_EQ(sprite.getSprite().getTexture(), sfprite.getTexture());
}

TEST_F(SpriteTest, GetTexture) {
    const std::string texturePath = "tests/assets/blue.png";

    sprite.createSprite(texturePath);

    sf::Texture originalTexture;
    ASSERT_TRUE(originalTexture.loadFromFile(texturePath));

    EXPECT_EQ(sprite.getTexture().getSize(), originalTexture.getSize());
}

TEST_F(SpriteTest, IsTextureLoaded) {
    ASSERT_FALSE(sprite.isTextureLoaded());

    sprite.createSprite("tests/assets/red.png");
    ASSERT_TRUE(sprite.isTextureLoaded());

    sprite.createSprite();
    ASSERT_TRUE(sprite.isTextureLoaded());

    sf::Texture texture;
    sprite.createSprite(texture);
    ASSERT_TRUE(sprite.isTextureLoaded());

    sprite.createSprite("tests/assets/blue.png");
    ASSERT_TRUE(sprite.isTextureLoaded());
}

TEST_F(SpriteTest, SetSpriteWithAnExistingSprite) {
    Sprite sprite("tests/assets/red.png");

    sf::Texture newTexture;
    ASSERT_TRUE(newTexture.loadFromFile("tests/assets/blue.png"));

    sf::Sprite newSprite;
    newSprite.setTexture(newTexture);

    ASSERT_NE(sprite.getSprite().getTexture(), newSprite.getTexture());

    sprite.setSprite(newSprite);
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
    ASSERT_EQ(sprite.getSprite().getTexture(), newSprite.getTexture());
}

TEST_F(SpriteTest, SetSpriteWithMapTextureTextureNameAndMapTransform) {
    Sprite spriteComp;

    std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture;
    sf::Texture testTexture;

    ASSERT_TRUE(testTexture.loadFromFile("tests/assets/red.png"));

    mapTexture["TestTexture"] = std::make_shared<sf::Texture>(testTexture);

    sf::Sprite testSprite;
    testSprite.setTexture(testTexture);

    std::map<std::string, std::vector<float>> mapTransform;
    mapTransform["Position"] = {10.0f, 20.0f};
    mapTransform["Scale"] = {2.0f, 2.0f};

    spriteComp.setSprite(mapTexture, "TestTexture", mapTransform);

    ASSERT_TRUE(spriteComp.getSprite().getTexture() != nullptr);

    int64_t testTextureSize = testTexture.getSize().x * testTexture.getSize().y;
    int64_t spriteCompTextureSize = spriteComp.getSprite().getTexture()->getSize().x * spriteComp.getSprite().getTexture()->getSize().y;

    ASSERT_TRUE(testTextureSize > 0);
    ASSERT_EQ(testTextureSize, spriteCompTextureSize);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().x, 10.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().y, 20.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().x, 2.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().y, 2.0f);
}

TEST_F(SpriteTest, SetTextureWithTexturePath) {
    Sprite sprite("tests/assets/red.png");

    sf::Texture newTexture;
    ASSERT_TRUE(newTexture.loadFromFile("tests/assets/blue.png"));

    sf::Sprite newSprite;
    newSprite.setTexture(newTexture);

    ASSERT_NE(sprite.getSprite().getTexture(), newSprite.getTexture());

    sprite.setTexture(newTexture);
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, SetTextureWithAnExistingTexture) {
    Sprite sprite("tests/assets/red.png");

    sf::Texture newTexture;
    ASSERT_TRUE(newTexture.loadFromFile("tests/assets/blue.png"));

    sf::Sprite newSprite;
    newSprite.setTexture(newTexture);

    ASSERT_NE(sprite.getSprite().getTexture(), newSprite.getTexture());

    sprite.setTexture(newTexture);
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, SetAndApplyDefferedSprite) {
    auto helloWorldFunction = []() { std::cout << "Hello world" << std::endl; };

    sprite.setDeferredSprite(helloWorldFunction);

    testing::internal::CaptureStdout();

    sprite.applyDeferredSprite();

    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_THAT(output, ::testing::HasSubstr("Hello world"));
}
