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

TEST_F(EntityTest, Init) {
    EXPECT_TRUE(entity.initEntity());
}

TEST_F(EntityTest, GetNameAndSetName) {
    EXPECT_EQ("", entity.getName());

    entity.setName("TestEntity");
    EXPECT_EQ("TestEntity", entity.getName());
}

TEST_F(EntityTest, AddAndGetComponent) {
    std::map<std::string, std::vector<float>> transformData;

    transformData["Position"] = std::vector<float>{1.0f, 2.0f};
    transformData["Rotation"] = std::vector<float>{3.0f, 4.0f};
    transformData["Scale"] = std::vector<float>{5.0f, 6.0f};

    Transform addedComponent(transformData);

    entity.addComponent<Transform>();
    entity1.addComponent<Transform>(transformData);

    EXPECT_EQ(addedComponent.getBit(), entity.getComponent<Transform>().getBit());
}
