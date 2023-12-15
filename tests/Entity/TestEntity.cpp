#include "gtest/gtest.h"
#include "../../Entity/entity.h"
#include "../include/all_components.h"

class EntityTest : public ::testing::Test {
protected:
    Entity entity;
};

TEST_F(EntityTest, GetNameAndSetName) {
    EXPECT_EQ("", entity.getName());

    entity.setName("TestEntity");
    EXPECT_EQ("TestEntity", entity.getName());
}

TEST_F(EntityTest, AddAndGetComponent) {
    std::map<std::string, std::vector<float>> transformData = {
        {"Position", {1.0f, 2.0f}},
        {"Rotation", {3.0f, 4.0f}},
        {"Scale", {5.0f, 6.0f}}
    };

    Transform addedComponent(transformData);

    entity.addComponent<Transform>(transformData);

    EXPECT_EQ(addedComponent.getBit(), entity.getComponent<Transform>().getBit());
}
