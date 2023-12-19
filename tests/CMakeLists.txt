cmake_minimum_required(VERSION 3.10)
project(R-TypeTests)

add_executable(all_tests
    TestMain.cpp
    Entity/TestEntity.cpp
    Entity/TestEntityManager.cpp
    Components/all_components/TestAudio.cpp
    Components/all_components/TestTransform.cpp
)

target_include_directories(all_tests
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Entity
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(all_tests PRIVATE all_components gtest gtest_main sfml-system sfml-window sfml-graphics sfml-audio)

set_target_properties(all_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../"
)

include(GoogleTest)
gtest_discover_tests(all_tests)
