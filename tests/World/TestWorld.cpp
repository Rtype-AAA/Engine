#include "gtest/gtest.h"
#include "world.h"

class TestWorld : public ::testing::Test {
protected:
    World world;
};

TEST_F(TestWorld, DefaultConstructor) {
    EXPECT_EQ(0, world.getEntityManagerMap().size());
    EXPECT_EQ("", world.getNameWorld());
}

TEST_F(TestWorld, CreateEntities) {
    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    std::vector<std::string> vectorEntity;
    vectorEntity.emplace_back("test");
    mapEntityManager.insert(std::make_pair("test", std::make_pair(std::make_unique<EntityManager>(), vectorEntity)));

    world.createEntities(mapEntityManager);
    EXPECT_EQ(1, world.getEntityManagerMap().size());
    EXPECT_EQ("test", world.getEntityManagerMap().begin()->first);
    EXPECT_EQ(1, world.getEntityManagerMap().begin()->second->getEntityMap().size());
    EXPECT_EQ("test", world.getEntityManagerMap().begin()->second->getEntityMap().begin()->first);
}

TEST_F(TestWorld, AddEntityManager) {
    world.addEntityManager("test");
    EXPECT_EQ(1, world.getEntityManagerMap().size());
    EXPECT_EQ("test", world.getEntityManagerMap().begin()->first);
}

TEST_F(TestWorld, GetEntityManager) {
    world.addEntityManager("test");

    EXPECT_EQ(1, world.getEntityManagerMap().size());
    EXPECT_EQ("test", world.getEntityManagerMap().begin()->first);

    EntityManager& entityManager = world.getEntityManager("test");
    EXPECT_EQ(1, world.getEntityManagerMap().size());
    EXPECT_EQ("test", world.getEntityManagerMap().begin()->first);
}

TEST_F(TestWorld, SetNameWorld) {
    std::string name = "test";

    world.setNameWorld(name);
    EXPECT_EQ(name, world.getNameWorld());

    std::string name2 = "test2";
    world.setNameWorld(name2);
    EXPECT_NE(name, world.getNameWorld());
    EXPECT_EQ(name2, world.getNameWorld());
}

TEST_F(TestWorld, GetNameWorld) {
    std::string name = "test";

    world.setNameWorld(name);
    EXPECT_EQ(name, world.getNameWorld());
}

TEST_F(TestWorld, GetEntityManagerMap) {
    std::string name = "test";
    world.addEntityManager(name);

    EXPECT_EQ(1, world.getEntityManagerMap().size());
    EXPECT_EQ(name, world.getEntityManagerMap().begin()->first);

    std::map<std::string, EntityManager*> map = world.getEntityManagerMap();

    EXPECT_EQ(1, map.size());
    EXPECT_EQ(name, map.begin()->first);

    std::string name2 = "test2";
    world.addEntityManager(name2);

    EXPECT_EQ(2, world.getEntityManagerMap().size());
    EXPECT_EQ(name, world.getEntityManagerMap().begin()->first);

    std::map<std::string, EntityManager*> map2 = world.getEntityManagerMap();

    EXPECT_EQ(2, map2.size());
    EXPECT_EQ(name, map2.begin()->first);
    EXPECT_EQ(name2, (++map2.begin())->first);
}

TEST_F(TestWorld, InitWorld) {
    EXPECT_TRUE(world.initWorld());
}
