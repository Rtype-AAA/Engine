#include "gtest/gtest.h"
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

TEST_F(EntityTest, InitEntity) {
    EXPECT_TRUE(entity.initEntity());
}

TEST_F(EntityTest, GetNameAndSetName) {
    EXPECT_EQ("", entity.getName());

    entity.setName("TestEntity");
    EXPECT_EQ("TestEntity", entity.getName());
}

TEST_F(EntityTest, Update) {
    EXPECT_NO_THROW(entity.update(sf::Time::Zero));
}

TEST_F(EntityTest, addDrawable) {
    EXPECT_NO_THROW(entity.addDrawable(new Sprite()));
}

TEST_F(EntityTest, AddAndGetComponent) {
    entity.addComponent<Transform>();

    EXPECT_EQ(0, entity.getComponent<Transform>().getBit());

    entity1.addComponent<Transform>();

    entity1.getComponent<Transform>().setTransform(Vector2<float>(1.0f, 1.0f), 1.0f, Vector2<float>(2.0f, 2.0f));

    EXPECT_EQ(0, entity1.getComponent<Transform>().getBit());

    EXPECT_EQ(1, entity1.getComponent<Transform>().getTransformStruct().position.getX());
    EXPECT_EQ(1, entity1.getComponent<Transform>().getTransformStruct().position.getY());
    EXPECT_EQ(1, entity1.getComponent<Transform>().getTransformStruct().rotation);
    EXPECT_EQ(2, entity1.getComponent<Transform>().getTransformStruct().scale.getX());
    EXPECT_EQ(2, entity1.getComponent<Transform>().getTransformStruct().scale.getY());

    entity1.addComponent<Sprite>();

    EXPECT_EQ(1, entity1.getComponent<Sprite>().getBit());
}

TEST_F(EntityTest, GetComponentTypeID) {
    entity.addComponent<Transform>();
    entity.addComponent<Sprite>();

    EXPECT_EQ(0, entity.getComponent<Transform>().getBit());
    EXPECT_EQ(1, entity.getComponent<Sprite>().getBit());
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
    EXPECT_EQ(3, entity.getComponentArrays().size());

    entity.addComponent<Transform>();
    entity.addComponent<Sprite>();

    EXPECT_EQ(3, entity.getComponentArrays().size());

    std::array<Components*, 3> componentArray = entity.getComponentArrays();
}
