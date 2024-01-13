#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "entityManager.h"
#include "entity.h"
#include "Transform.h"
#include "Sprite.h"

class EntityTest : public ::testing::Test {
protected:
    Entity entity;
    Entity entity1;
};

TEST_F(EntityTest, DefaultConstructor) {
    EXPECT_EQ("", entity.getName());
}

TEST_F(EntityTest, ConstructorWithName) {
    Entity entity("TestEntity");

    EXPECT_EQ("TestEntity", entity.getName());
}

TEST_F(EntityTest, GetBit) {
    EXPECT_EQ(0, entity.getBit());
}

TEST_F(EntityTest, Init) {
    EXPECT_TRUE(entity.init());
}

TEST_F(EntityTest, GetNameAndSetName) {
    EXPECT_EQ("", entity.getName());

    entity.setName("TestEntity");
    EXPECT_EQ("TestEntity", entity.getName());

    entity.setName("TestEntity1");
    EXPECT_EQ("TestEntity1", entity.getName());
}

TEST_F(EntityTest, Update) {
    EXPECT_NO_THROW(entity.update(sf::Time::Zero));
}

TEST_F(EntityTest, addDrawable) {
    EXPECT_NO_THROW(entity.addDrawable(new Sprite()));
}

TEST_F(EntityTest, RemoveDrawable) {
    entity.addComponent<Transform>();
    entity.addComponent<Sprite>();

    EXPECT_EQ(0, entity.getComponent<Transform>().getBit());
    EXPECT_EQ(1, entity.getComponent<Sprite>().getBit());

    EXPECT_EQ(1, entity.getDrawableComponents().size());

    entity.removeDrawable(&entity.getComponent<Sprite>());

    EXPECT_EQ(0, entity.getDrawableComponents().size());
}

TEST_F(EntityTest, AddAndGetComponent) {
    entity.addComponent<Transform>();

    EXPECT_EQ(0, entity.getComponent<Transform>().getBit());

    entity1.addComponent<Transform>();

    entity1.getComponent<Transform>().setTransform(Vector2<float>(1.0f, 1.0f), 1.0f, Vector2<float>(2.0f, 2.0f));

    EXPECT_EQ(0, entity1.getComponent<Transform>().getBit());

    EXPECT_EQ(1, entity1.getComponent<Transform>().getTransform().position.getX());
    EXPECT_EQ(1, entity1.getComponent<Transform>().getTransform().position.getY());
    EXPECT_EQ(1, entity1.getComponent<Transform>().getTransform().rotation);
    EXPECT_EQ(2, entity1.getComponent<Transform>().getTransform().scale.getX());
    EXPECT_EQ(2, entity1.getComponent<Transform>().getTransform().scale.getY());

    entity1.addComponent<Sprite>();

    EXPECT_EQ(1, entity1.getComponent<Sprite>().getBit());
}

TEST_F(EntityTest, RemoveComponent) {
    EXPECT_EQ(6, entity.getComponentArrays().size());
    EXPECT_EQ(0, entity.getDrawableComponents().size());

    entity.addComponent<Transform>();
    entity.addComponent<Sprite>();

    EXPECT_EQ(0, entity.getComponent<Transform>().getBit());
    EXPECT_EQ(1, entity.getComponent<Sprite>().getBit());

    EXPECT_EQ(6, entity.getComponentArrays().size());
    EXPECT_EQ(1, entity.getDrawableComponents().size());

    entity.removeComponent<Sprite>();

    EXPECT_EQ(0, entity.getDrawableComponents().size());
    EXPECT_EQ(6, entity.getComponentArrays().size());
}

TEST_F(EntityTest, GetComponentTypeID) {
    entity.addComponent<Transform>();
    entity.addComponent<Sprite>();

    EXPECT_EQ(0, entity.getComponent<Transform>().getBit());
    EXPECT_EQ(1, entity.getComponent<Sprite>().getBit());
}

TEST_F(EntityTest, GetComponentBitset) {
    EXPECT_EQ(6, entity.getComponentBitset().size());

    entity.addComponent<Transform>();
    entity.addComponent<Sprite>();

    EXPECT_EQ(0, entity.getComponent<Transform>().getBit());
    EXPECT_EQ(1, entity.getComponent<Sprite>().getBit());

    EXPECT_EQ(6, entity.getComponentBitset().size());
}

TEST_F(EntityTest, GetDrawableComponents) {
    entity.addComponent<Transform>();
    entity.addComponent<Sprite>();

    EXPECT_EQ(0, entity.getComponent<Transform>().getBit());
    EXPECT_EQ(1, entity.getComponent<Sprite>().getBit());

    EXPECT_EQ(1, entity.getDrawableComponents().size());

    entity.addComponent<Sprite>();

    EXPECT_EQ(2, entity.getDrawableComponents().size());
}

TEST_F(EntityTest, GetComponentArrays) {
    EXPECT_EQ(6, entity.getComponentArrays().size());

    entity.addComponent<Transform>();
    entity.addComponent<Sprite>();

    EXPECT_EQ(6, entity.getComponentArrays().size());

    std::array<Components*, 6> componentArray = entity.getComponentArrays();
}

TEST_F(EntityTest, SetActive) {
    EXPECT_TRUE(entity.getActive());

    entity.setActive(false);

    EXPECT_FALSE(entity.getActive());

    entity.setActive(true);

    EXPECT_TRUE(entity.getActive());
}

TEST_F(EntityTest, GetActive) {
    EXPECT_TRUE(entity.getActive());

    entity.setActive(false);

    EXPECT_FALSE(entity.getActive());

    entity.setActive(true);

    EXPECT_TRUE(entity.getActive());
}

TEST_F(EntityTest, SetAndApplyDeferredEntity) {
    auto helloWorldFunction = []() { std::cout << "Hello world" << std::endl; };

    entity.setDeferredEntity(helloWorldFunction);

    testing::internal::CaptureStdout();

    entity.applyDeferredEntity();

    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_THAT(output, ::testing::HasSubstr("Hello world"));
}
