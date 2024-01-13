#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Sprite.h"

class SpriteTest : public ::testing::Test {
protected:
    Sprite sprite;
};

TEST_F(SpriteTest, DefaultConstructor) {
    Sprite sprite;

    ASSERT_EQ(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, GetTransform) {
    ASSERT_EQ(sprite.getTransform(), nullptr);

    Transform transform;
    sprite.setTransform(transform);

    ASSERT_NE(sprite.getTransform(), nullptr);

    ASSERT_EQ(sprite.getTransform()->getPosition().getX(), 0.0f);
    ASSERT_EQ(sprite.getTransform()->getPosition().getY(), 0.0f);

    ASSERT_EQ(sprite.getTransform()->getRotation(), 0.0f);

    ASSERT_EQ(sprite.getTransform()->getScale().getX(), 1.0f);
    ASSERT_EQ(sprite.getTransform()->getScale().getY(), 1.0f);

    sprite.getTransform()->setPosition(Vector2<float>(10.0f, 20.0f));
    sprite.getTransform()->setRotation(30.0f);
    sprite.getTransform()->setScale(Vector2<float>(2.0f, 2.0f));

    ASSERT_EQ(sprite.getTransform()->getPosition().getX(), 10.0f);
    ASSERT_EQ(sprite.getTransform()->getPosition().getY(), 20.0f);

    ASSERT_EQ(sprite.getTransform()->getRotation(), 30.0f);

    ASSERT_EQ(sprite.getTransform()->getScale().getX(), 2.0f);
    ASSERT_EQ(sprite.getTransform()->getScale().getY(), 2.0f);
}

TEST_F(SpriteTest, Init) {
    ASSERT_FALSE(sprite.init());

    Transform transform;

    sprite.setTransform(transform);

    ASSERT_TRUE(sprite.init());
}

TEST_F(SpriteTest, GetBit) {
    ASSERT_EQ(sprite.getBit(), 1);
}

TEST_F(SpriteTest, Update) {
    sf::Time deltaTime = sf::seconds(1.0f);

    Transform transform;
    sprite.setTransform(transform);

    ASSERT_TRUE(sprite.init());

    sf::Texture texture;
    texture.loadFromFile("tests/assets/red.png");

    sf::Sprite sfprite;
    sfprite.setTexture(texture);

    sprite.setSprite(sfprite);
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);

    ASSERT_NO_THROW(sprite.update(deltaTime));

    ASSERT_FLOAT_EQ(sprite.getSprite().getPosition().x, 0.0f);
    ASSERT_FLOAT_EQ(sprite.getSprite().getPosition().y, 0.0f);

    ASSERT_FLOAT_EQ(sprite.getSprite().getRotation(), 0.0f);

    ASSERT_FLOAT_EQ(sprite.getSprite().getScale().x, 1.0f);
    ASSERT_FLOAT_EQ(sprite.getSprite().getScale().y, 1.0f);

    sprite.getTransform()->setPosition(Vector2<float>(10.0f, 20.0f));
    sprite.getTransform()->setRotation(30.0f);
    sprite.getTransform()->setScale(Vector2<float>(2.0f, 2.0f));

    ASSERT_NO_THROW(sprite.update(deltaTime));

    ASSERT_FLOAT_EQ(sprite.getSprite().getPosition().x, 10.0f);
    ASSERT_FLOAT_EQ(sprite.getSprite().getPosition().y, 20.0f);

    ASSERT_FLOAT_EQ(sprite.getSprite().getRotation(), 30.0f);

    ASSERT_FLOAT_EQ(sprite.getSprite().getScale().x, 2.0f);
    ASSERT_FLOAT_EQ(sprite.getSprite().getScale().y, 2.0f);
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


TEST_F(SpriteTest, SetSpriteWithAnExistingSprite) {
    ASSERT_EQ(sprite.getSprite().getTexture(), nullptr);

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
    std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture;
    sf::Texture testTexture;

    ASSERT_TRUE(testTexture.loadFromFile("tests/assets/red.png"));

    mapTexture["TestTexture"] = std::make_shared<sf::Texture>(testTexture);

    sf::Sprite testSprite;
    testSprite.setTexture(testTexture);

    sprite.setSprite(mapTexture, "TestTexture");

    ASSERT_TRUE(sprite.getSprite().getTexture() != nullptr);

    int64_t testTextureSize = testTexture.getSize().x * testTexture.getSize().y;
    int64_t spriteTextureSize = sprite.getSprite().getTexture()->getSize().x * sprite.getSprite().getTexture()->getSize().y;

    ASSERT_TRUE(testTextureSize > 0);
    ASSERT_EQ(testTextureSize, spriteTextureSize);

    ASSERT_FLOAT_EQ(sprite.getSprite().getPosition().x, 0.0f);
    ASSERT_FLOAT_EQ(sprite.getSprite().getPosition().y, 0.0f);

    ASSERT_FLOAT_EQ(sprite.getSprite().getScale().x, 1.0f);
    ASSERT_FLOAT_EQ(sprite.getSprite().getScale().y, 1.0f);
}

TEST_F(SpriteTest, SetAndApplyDefferedSprite) {
    auto helloWorldFunction = []() { std::cout << "Hello world" << std::endl; };

    sprite.setDeferredSprite(helloWorldFunction);

    testing::internal::CaptureStdout();

    sprite.applyDeferredSprite();

    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_THAT(output, ::testing::HasSubstr("Hello world"));
}

TEST_F(SpriteTest, SetTransform) {
    Transform transform;
    sprite.setTransform(transform);

    ASSERT_NE(sprite.getTransform(), nullptr);

    ASSERT_EQ(sprite.getTransform()->getPosition().getX(), 0.0f);
    ASSERT_EQ(sprite.getTransform()->getPosition().getY(), 0.0f);

    ASSERT_EQ(sprite.getTransform()->getRotation(), 0.0f);

    ASSERT_EQ(sprite.getTransform()->getScale().getX(), 1.0f);
    ASSERT_EQ(sprite.getTransform()->getScale().getY(), 1.0f);

    Transform newTransform;

    newTransform.setPosition(Vector2<float>(10.0f, 20.0f));
    newTransform.setRotation(30.0f);
    newTransform.setScale(Vector2<float>(2.0f, 2.0f));

    sprite.setTransform(newTransform);

    ASSERT_EQ(sprite.getTransform()->getPosition().getX(), 10.0f);
    ASSERT_EQ(sprite.getTransform()->getPosition().getY(), 20.0f);

    ASSERT_EQ(sprite.getTransform()->getRotation(), 30.0f);

    ASSERT_EQ(sprite.getTransform()->getScale().getX(), 2.0f);
    ASSERT_EQ(sprite.getTransform()->getScale().getY(), 2.0f);

    ASSERT_EQ(sprite.getTransform()->getPosition().getX(), newTransform.getPosition().getX());
    ASSERT_EQ(sprite.getTransform()->getPosition().getY(), newTransform.getPosition().getY());

    ASSERT_EQ(sprite.getTransform()->getRotation(), newTransform.getRotation());

    ASSERT_EQ(sprite.getTransform()->getScale().getX(), newTransform.getScale().getX());
    ASSERT_EQ(sprite.getTransform()->getScale().getY(), newTransform.getScale().getY());
}
