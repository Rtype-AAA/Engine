#include "gtest/gtest.h"
#include "../../src/Event/event.h"

class EventTest : public ::testing::Test {
protected:
    EventEngine eventEngine;
};

TEST_F(EventTest, DefaultConstructor) {
    EXPECT_EQ(0, eventEngine.getKeyPressedMap().size());
}

TEST_F(EventTest, Init) {
    EXPECT_TRUE(eventEngine.init());
}

TEST_F(EventTest, AddKeyPressed) {
    EXPECT_EQ(0, eventEngine.getKeyPressedMap().size());

    eventEngine.addKeyPressed(sf::Keyboard::Key::A, [](){});

    EXPECT_EQ(1, eventEngine.getKeyPressedMap().size());
    EXPECT_EQ(sf::Keyboard::Key::A, eventEngine.getKeyPressedMap().begin()->first);

    eventEngine.addKeyPressed(sf::Keyboard::Key::B, [](){});

    EXPECT_EQ(2, eventEngine.getKeyPressedMap().size());
    EXPECT_EQ(sf::Keyboard::Key::A, eventEngine.getKeyPressedMap().begin()->first);
    EXPECT_EQ(sf::Keyboard::Key::B, eventEngine.getKeyPressedMap().rbegin()->first);
}

TEST_F(EventTest, GetEvent) {
    ASSERT_TRUE(sf::Event::Count < eventEngine.getEvent().type);
}
