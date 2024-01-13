#include "gtest/gtest.h"
#include "eventEngine.h"

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

TEST_F(EventTest, AddMouseButtonPressed) {
    EXPECT_EQ(0, eventEngine.getMouseButtonPressedMap().size());

    eventEngine.addMouseButtonPressed(sf::Mouse::Button::Left, [](){});

    EXPECT_EQ(1, eventEngine.getMouseButtonPressedMap().size());
    EXPECT_EQ(sf::Mouse::Button::Left, eventEngine.getMouseButtonPressedMap().begin()->first);

    eventEngine.addMouseButtonPressed(sf::Mouse::Button::Right, [](){});

    EXPECT_EQ(2, eventEngine.getMouseButtonPressedMap().size());
    EXPECT_EQ(sf::Mouse::Button::Left, eventEngine.getMouseButtonPressedMap().begin()->first);
    EXPECT_EQ(sf::Mouse::Button::Right, eventEngine.getMouseButtonPressedMap().rbegin()->first);
}

TEST_F(EventTest, AddMouseMoved) {
    EXPECT_EQ(0, eventEngine.getMouseMovedMap().size());

    eventEngine.addMouseMoved("test", [](){});

    EXPECT_EQ(1, eventEngine.getMouseMovedMap().size());
    EXPECT_EQ("test", eventEngine.getMouseMovedMap().begin()->first);

    eventEngine.addMouseMoved("test2", [](){});

    EXPECT_EQ(2, eventEngine.getMouseMovedMap().size());
    EXPECT_EQ("test", eventEngine.getMouseMovedMap().begin()->first);
    EXPECT_EQ("test2", eventEngine.getMouseMovedMap().rbegin()->first);
}

TEST_F(EventTest, GetKeyPressedMap) {
    EXPECT_EQ(0, eventEngine.getKeyPressedMap().size());

    eventEngine.addKeyPressed(sf::Keyboard::Key::A, [](){});

    EXPECT_EQ(1, eventEngine.getKeyPressedMap().size());
    EXPECT_EQ(sf::Keyboard::Key::A, eventEngine.getKeyPressedMap().begin()->first);

    eventEngine.addKeyPressed(sf::Keyboard::Key::B, [](){});

    EXPECT_EQ(2, eventEngine.getKeyPressedMap().size());
    EXPECT_EQ(sf::Keyboard::Key::A, eventEngine.getKeyPressedMap().begin()->first);
    EXPECT_EQ(sf::Keyboard::Key::B, eventEngine.getKeyPressedMap().rbegin()->first);
}

TEST_F(EventTest, GetMouseButtonPressedMap) {
    EXPECT_EQ(0, eventEngine.getMouseButtonPressedMap().size());

    eventEngine.addMouseButtonPressed(sf::Mouse::Button::Left, [](){});

    EXPECT_EQ(1, eventEngine.getMouseButtonPressedMap().size());
    EXPECT_EQ(sf::Mouse::Button::Left, eventEngine.getMouseButtonPressedMap().begin()->first);

    eventEngine.addMouseButtonPressed(sf::Mouse::Button::Right, [](){});

    EXPECT_EQ(2, eventEngine.getMouseButtonPressedMap().size());
    EXPECT_EQ(sf::Mouse::Button::Left, eventEngine.getMouseButtonPressedMap().begin()->first);
    EXPECT_EQ(sf::Mouse::Button::Right, eventEngine.getMouseButtonPressedMap().rbegin()->first);
}

TEST_F(EventTest, GetMouseMovedMap) {
    EXPECT_EQ(0, eventEngine.getMouseMovedMap().size());

    eventEngine.addMouseMoved("test", [](){});

    EXPECT_EQ(1, eventEngine.getMouseMovedMap().size());
    EXPECT_EQ("test", eventEngine.getMouseMovedMap().begin()->first);

    eventEngine.addMouseMoved("test2", [](){});

    EXPECT_EQ(2, eventEngine.getMouseMovedMap().size());
    EXPECT_EQ("test", eventEngine.getMouseMovedMap().begin()->first);
    EXPECT_EQ("test2", eventEngine.getMouseMovedMap().rbegin()->first);
}
