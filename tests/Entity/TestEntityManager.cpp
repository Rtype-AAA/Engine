#include "gtest/gtest.h"
#include "entityManager.h"
#include "Transform.h"
#include "Sprite.h"

class EntityManagerTest : public ::testing::Test {
protected:
    EntityManager entityManager{};

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(EntityManagerTest, DefaultConstructor) {
    EntityManager manager{};

    EXPECT_EQ(0, manager.getEntities().size());
    EXPECT_EQ(0, manager.getEntityMap().size());
}

TEST_F(EntityManagerTest, Init) {
    EXPECT_TRUE(entityManager.init());
}

TEST_F(EntityManagerTest, AddEntity) {
    std::string entity = "TestEntity";

    EXPECT_EQ(0, entityManager.getEntities().size());
    EXPECT_EQ(0, entityManager.getEntityMap().size());

    entityManager.addEntity(entity);

    EXPECT_EQ(1, entityManager.getEntities().size());
    EXPECT_EQ(1, entityManager.getEntityMap().size());

    Entity newEntity;
    newEntity.setName("Another");

    Entity original;
    original.setName(entityManager.getEntity("TestEntity").getName());

    EXPECT_NE(original.getName(), newEntity.getName());
    EXPECT_EQ(original.getName(), entity);

    Transform addedComponent;

    std::string entityWithComponent = "WithComponent";

    entityManager.addEntity(entityWithComponent);
    entityManager.getEntity("WithComponent").addComponent<Transform>();

    EXPECT_EQ(2, entityManager.getEntities().size());
    EXPECT_EQ(2, entityManager.getEntityMap().size());

    EXPECT_EQ(original.getName(), entityManager.getEntity("TestEntity").getName());
    EXPECT_EQ(entityWithComponent, entityManager.getEntity("WithComponent").getName());

    EXPECT_EQ(addedComponent.getBit(), entityManager.getEntity("WithComponent").getComponent<Transform>().getBit());
}

TEST_F(EntityManagerTest, GetEntity) {
    std::string entity = "TestEntity";

    entityManager.addEntity(entity);

    EXPECT_EQ(1, entityManager.getEntities().size());
    EXPECT_EQ(1, entityManager.getEntityMap().size());

    Entity original;
    original.setName(entity);

    EXPECT_EQ(original.getName(), entityManager.getEntity("TestEntity").getName());
}

TEST_F(EntityManagerTest, GetEntities) {
    std::string entity = "TestEntity";

    entityManager.addEntity(entity);

    EXPECT_EQ(1, entityManager.getEntities().size());
    EXPECT_EQ(1, entityManager.getEntityMap().size());

    std::string entity2 = "TestEntity2";

    entityManager.addEntity(entity2);

    EXPECT_EQ(2, entityManager.getEntities().size());
    EXPECT_EQ(2, entityManager.getEntityMap().size());

    std::map<std::string, std::vector<float>> transformData = {
        {"Position", {1.0f, 2.0f}},
        {"Rotation", {3.0f, 4.0f}},
        {"Scale", {5.0f, 6.0f}}
    };

    entityManager.getEntity("TestEntity").addComponent<Transform>();

    entityManager.getEntity("TestEntity").getComponent<Transform>().setTransform(Vector2<float>(1.0f, 2.0f), 3.0, Vector2<float>(4.0f, 5.0f));

    std::map<std::string, Entity *> entities = entityManager.getEntities();

    EXPECT_EQ(2, entities.size());
    EXPECT_EQ(entity, entities["TestEntity"]->getName());
    EXPECT_EQ(entity2, entities["TestEntity2"]->getName());

    EXPECT_EQ(entities["TestEntity"]->getComponent<Transform>().getBit(), entityManager.getEntity("TestEntity").getComponent<Transform>().getBit());

    EXPECT_EQ(entities["TestEntity"]->getComponent<Transform>().getPosition().getX(), entityManager.getEntity("TestEntity").getComponent<Transform>().getPosition().getX());
    EXPECT_EQ(entities["TestEntity"]->getComponent<Transform>().getPosition().getY(), entityManager.getEntity("TestEntity").getComponent<Transform>().getPosition().getY());
    EXPECT_EQ(entities["TestEntity"]->getComponent<Transform>().getRotation(), entityManager.getEntity("TestEntity").getComponent<Transform>().getRotation());
    EXPECT_EQ(entities["TestEntity"]->getComponent<Transform>().getScale().getX(), entityManager.getEntity("TestEntity").getComponent<Transform>().getScale().getX());
    EXPECT_EQ(entities["TestEntity"]->getComponent<Transform>().getScale().getY(), entityManager.getEntity("TestEntity").getComponent<Transform>().getScale().getY());
}

TEST_F(EntityManagerTest, GetEntityMap) {
    std::string entity = "TestEntity";

    entityManager.addEntity(entity);

    EXPECT_EQ(1, entityManager.getEntities().size());
    EXPECT_EQ(1, entityManager.getEntityMap().size());

    std::string entity2 = "TestEntity2";

    entityManager.addEntity(entity2);

    EXPECT_EQ(2, entityManager.getEntities().size());
    EXPECT_EQ(2, entityManager.getEntityMap().size());

    Transform addedComponent;
    entityManager.getEntity("TestEntity").addComponent<Transform>();

    EXPECT_EQ(2, entityManager.getEntityMap().size());
    EXPECT_EQ(entity, entityManager.getEntityMap()["TestEntity"]->getName());
    EXPECT_EQ(entity2, entityManager.getEntityMap()["TestEntity2"]->getName());

    EXPECT_EQ(addedComponent.getBit(), entityManager.getEntityMap()["TestEntity"]->getComponent<Transform>().getBit());
}
