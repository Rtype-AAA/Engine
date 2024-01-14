#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Music.h"

class MusicTests : public ::testing::Test
{
protected:
    Music music;

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(MusicTests, Constructor) {
    ASSERT_EQ(music.getBit(), 3);
    ASSERT_EQ(music.init(), true);

}

TEST_F(MusicTests, GetBit) {
    ASSERT_EQ(music.getBit(), 3);
}

TEST_F(MusicTests, Update) {
    EXPECT_NO_THROW(music.update(sf::Time::Zero));
}

TEST_F(MusicTests, Init) {
    ASSERT_EQ(music.init(), true);
}

TEST_F(MusicTests, SetMusic) {
    ASSERT_EQ(music.getMusic(), nullptr);

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic;
    std::shared_ptr<sf::Music> musicBuffer = std::make_shared<sf::Music>();
    mapMusic["test"] = musicBuffer;

    music.setMusic(mapMusic, "test");

    ASSERT_NE(music.getMusic(), nullptr);
    ASSERT_EQ(music.getMusic(), musicBuffer);
}

TEST_F(MusicTests, SetDeferredMusic) {
    auto helloWorldFunction = []() { std::cout << "Hello world" << std::endl; };

    music.setDeferredMusic(helloWorldFunction);

    testing::internal::CaptureStdout();

    music.applyDeferredMusic();

    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_THAT(output, ::testing::HasSubstr("Hello world"));
}

TEST_F(MusicTests, GetMusic) {
    ASSERT_EQ(music.getMusic(), nullptr);

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic;
    std::shared_ptr<sf::Music> musicBuffer = std::make_shared<sf::Music>();
    mapMusic["test"] = musicBuffer;

    music.setMusic(mapMusic, "test");

    ASSERT_NE(music.getMusic(), nullptr);
    ASSERT_EQ(music.getMusic(), musicBuffer);
}

TEST_F(MusicTests, Play) {
    ASSERT_EQ(music.getMusic(), nullptr);

    testing::internal::CaptureStderr();

    music.play();

    std::string output = testing::internal::GetCapturedStderr();

    ASSERT_THAT(output, ::testing::HasSubstr("Please set the music before playing it."));

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic;

    std::shared_ptr<sf::Music> musicBuffer = std::make_shared<sf::Music>();

    musicBuffer->openFromFile("tests/assets/Sounds/test1.ogg");
    mapMusic["test"] = musicBuffer;

    music.setMusic(mapMusic, "test");

    ASSERT_NE(music.getMusic(), nullptr);
    ASSERT_EQ(music.getMusic(), musicBuffer);

    ASSERT_NO_THROW(music.play());
    ASSERT_EQ(music.getStatus(), sf::SoundSource::Status::Playing);
}

TEST_F(MusicTests, Pause) {
    ASSERT_EQ(music.getMusic(), nullptr);

    testing::internal::CaptureStderr();

    music.pause();

    std::string output = testing::internal::GetCapturedStderr();

    ASSERT_THAT(output, ::testing::HasSubstr("Please set the music before pausing it."));

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic;

    std::shared_ptr<sf::Music> musicBuffer = std::make_shared<sf::Music>();

    musicBuffer->openFromFile("tests/assets/Sounds/test1.ogg");
    mapMusic["test"] = musicBuffer;

    music.setMusic(mapMusic, "test");

    ASSERT_NE(music.getMusic(), nullptr);
    ASSERT_EQ(music.getMusic(), musicBuffer);

    ASSERT_NO_THROW(music.play());
    ASSERT_EQ(music.getStatus(), sf::SoundSource::Status::Playing);

    ASSERT_NO_THROW(music.pause());
    ASSERT_EQ(music.getStatus(), sf::SoundSource::Status::Paused);
}

TEST_F(MusicTests, Stop) {
    ASSERT_EQ(music.getMusic(), nullptr);

    testing::internal::CaptureStderr();

    music.stop();

    std::string output = testing::internal::GetCapturedStderr();

    ASSERT_THAT(output, ::testing::HasSubstr("Please set the music before stopping it."));

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic;

    std::shared_ptr<sf::Music> musicBuffer = std::make_shared<sf::Music>();

    musicBuffer->openFromFile("tests/assets/Sounds/test1.ogg");
    mapMusic["test"] = musicBuffer;

    music.setMusic(mapMusic, "test");

    ASSERT_NE(music.getMusic(), nullptr);
    ASSERT_EQ(music.getMusic(), musicBuffer);

    ASSERT_NO_THROW(music.play());
    ASSERT_EQ(music.getStatus(), sf::SoundSource::Status::Playing);

    ASSERT_NO_THROW(music.stop());
    ASSERT_EQ(music.getStatus(), sf::SoundSource::Status::Stopped);
}

TEST_F(MusicTests, SetLoop) {
    ASSERT_EQ(music.getMusic(), nullptr);

    testing::internal::CaptureStderr();

    music.setLoop(false);

    std::string output = testing::internal::GetCapturedStderr();

    ASSERT_THAT(output, ::testing::HasSubstr("Please set the music before setting its loop."));

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic;

    std::shared_ptr<sf::Music> musicBuffer = std::make_shared<sf::Music>();

    musicBuffer->openFromFile("tests/assets/Sounds/test1.ogg");
    mapMusic["test"] = musicBuffer;

    music.setMusic(mapMusic, "test");

    ASSERT_NE(music.getMusic(), nullptr);
    ASSERT_EQ(music.getMusic(), musicBuffer);

    ASSERT_NO_THROW(music.setLoop(true));
    ASSERT_EQ(music.getLoop(), true);
}

TEST_F(MusicTests, GetLoop) {
    ASSERT_EQ(music.getMusic(), nullptr);
    ASSERT_EQ(music.getLoop(), false);

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic;

    std::shared_ptr<sf::Music> musicBuffer = std::make_shared<sf::Music>();

    musicBuffer->openFromFile("tests/assets/Sounds/test1.ogg");
    mapMusic["test"] = musicBuffer;

    music.setMusic(mapMusic, "test");

    ASSERT_NE(music.getMusic(), nullptr);
    ASSERT_EQ(music.getMusic(), musicBuffer);

    ASSERT_NO_THROW(music.setLoop(true));
    ASSERT_EQ(music.getLoop(), true);
}

TEST_F(MusicTests, SetVolume) {
    ASSERT_EQ(music.getMusic(), nullptr);

    testing::internal::CaptureStderr();

    music.setVolume(50);

    std::string output = testing::internal::GetCapturedStderr();

    ASSERT_THAT(output, ::testing::HasSubstr("Please set the music before setting its volume."));

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic;

    std::shared_ptr<sf::Music> musicBuffer = std::make_shared<sf::Music>();

    musicBuffer->openFromFile("tests/assets/Sounds/test1.ogg");
    mapMusic["test"] = musicBuffer;

    music.setMusic(mapMusic, "test");

    ASSERT_NE(music.getMusic(), nullptr);
    ASSERT_EQ(music.getMusic(), musicBuffer);

    ASSERT_NO_THROW(music.setVolume(50));
    ASSERT_EQ(music.getVolume(), 50);
}

TEST_F(MusicTests, GetVolume) {
    ASSERT_EQ(music.getMusic(), nullptr);
    ASSERT_EQ(music.getVolume(), -100);

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic;

    std::shared_ptr<sf::Music> musicBuffer = std::make_shared<sf::Music>();

    musicBuffer->openFromFile("tests/assets/Sounds/test1.ogg");
    mapMusic["test"] = musicBuffer;

    music.setMusic(mapMusic, "test");

    ASSERT_NE(music.getMusic(), nullptr);
    ASSERT_EQ(music.getMusic(), musicBuffer);

    ASSERT_NO_THROW(music.setVolume(50));
    ASSERT_EQ(music.getVolume(), music.getMusic()->getVolume());
    ASSERT_EQ(music.getVolume(), 50);

    ASSERT_NO_THROW(music.setVolume(100));
    ASSERT_EQ(music.getVolume(), music.getMusic()->getVolume());
    ASSERT_EQ(music.getVolume(), 100);
}

TEST_F(MusicTests, GetStatus) {
    ASSERT_EQ(music.getStatus(), sf::SoundSource::Status::Stopped);

    std::map<std::string, std::shared_ptr<sf::Music>> mapMusic;

    std::shared_ptr<sf::Music> musicBuffer = std::make_shared<sf::Music>();

    musicBuffer->openFromFile("tests/assets/Sounds/test1.ogg");
    mapMusic["test"] = musicBuffer;

    music.setMusic(mapMusic, "test");
    ASSERT_EQ(music.getStatus(), sf::SoundSource::Status::Stopped);

    ASSERT_NO_THROW(music.play());
    ASSERT_EQ(music.getStatus(), sf::SoundSource::Status::Playing);

    ASSERT_NO_THROW(music.pause());
    ASSERT_EQ(music.getStatus(), sf::SoundSource::Status::Paused);

    ASSERT_NO_THROW(music.stop());
    ASSERT_EQ(music.getStatus(), sf::SoundSource::Status::Stopped);
}
