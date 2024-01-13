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
    ASSERT_TRUE(sprite.initSprite());
}

TEST_F(SpriteTest, GetBit) {
    ASSERT_EQ(sprite.getBit(), 1);
}

TEST_F(SpriteTest, Update) {
    sf::Time deltaTime;

    ASSERT_NO_THROW(sprite.update(deltaTime));
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

TEST_F(SpriteTest, SetSprite) {
    Sprite spriteComp;

    std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture;
    sf::Texture testTexture;

    ASSERT_TRUE(testTexture.loadFromFile("tests/assets/red.png"));

    mapTexture["TestTexture"] = std::make_shared<sf::Texture>(testTexture);

    sf::Sprite testSprite;
    testSprite.setTexture(testTexture);

    spriteComp.setSprite(mapTexture, "TestTexture");

    ASSERT_TRUE(spriteComp.getSprite().getTexture() != nullptr);

    int64_t testTextureSize = testTexture.getSize().x * testTexture.getSize().y;
    int64_t spriteCompTextureSize = spriteComp.getSprite().getTexture()->getSize().x * spriteComp.getSprite().getTexture()->getSize().y;

    ASSERT_TRUE(testTextureSize > 0);
    ASSERT_EQ(testTextureSize, spriteCompTextureSize);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().x, 0.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().y, 0.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().x, 1.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().y, 1.0f);
}

TEST_F(SpriteTest, SetTransformSpriteWithPositionRotationAndScale) {
    Sprite spriteComp;

    spriteComp.setTransformSprite(Vector2<float>(10.0f, 20.0f), 30.0f, Vector2<float>(2.0f, 2.0f));

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().x, 10.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().y, 20.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getRotation(), 30.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().x, 2.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().y, 2.0f);
}

TEST_F(SpriteTest, SetPositionWithPosition) {
    Sprite spriteComp;

    spriteComp.setPosition(Vector2<float>(10.0f, 20.0f));

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().x, 10.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().y, 20.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getRotation(), 0.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().x, 1.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().y, 1.0f);

    spriteComp.setPosition(Vector2<float>(30.0f, 40.0f));

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().x, 30.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().y, 40.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getRotation(), 0.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().x, 1.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().y, 1.0f);
}

TEST_F(SpriteTest, SetRotationWithRotation) {
    Sprite spriteComp;

    spriteComp.setRotation(30.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().x, 0.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().y, 0.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getRotation(), 30.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().x, 1.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().y, 1.0f);

    spriteComp.setRotation(40.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().x, 0.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().y, 0.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getRotation(), 40.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().x, 1.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().y, 1.0f);
}

TEST_F(SpriteTest, SetScaleWithScale) {
    Sprite spriteComp;

    spriteComp.setScale(Vector2<float>(2.0f, 2.0f));

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().x, 0.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().y, 0.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getRotation(), 0.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().x, 2.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().y, 2.0f);

    spriteComp.setScale(Vector2<float>(3.0f, 3.0f));

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().x, 0.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getPosition().y, 0.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getRotation(), 0.0f);

    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().x, 3.0f);
    ASSERT_FLOAT_EQ(spriteComp.getSprite().getScale().y, 3.0f);
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

TEST_F(SpriteTest, GetBounds) {
    Sprite sprite("tests/assets/red.png");

    Rect<float> rect = sprite.getBounds();

    sf::Sprite sfSprite = sprite.getSprite();

    ASSERT_EQ(rect.getLeft(), sfSprite.getGlobalBounds().left);
    ASSERT_EQ(rect.getTop(), sfSprite.getGlobalBounds().top);
    ASSERT_EQ(rect.getWidth(), sfSprite.getGlobalBounds().width);
    ASSERT_EQ(rect.getHeight(), sfSprite.getGlobalBounds().height);
}
