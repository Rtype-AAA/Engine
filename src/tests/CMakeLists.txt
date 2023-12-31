cmake_minimum_required(VERSION 3.10)

project(R-TypeTests)

find_package(SFML REQUIRED COMPONENTS system window graphics audio)

add_executable(all_tests
        TestMain.cpp
        Entity/TestEntity.cpp
        Entity/TestEntityManager.cpp
        Components/all_components/TestTransform.cpp
)

target_include_directories(all_tests
    PRIVATE ../Entity
    PRIVATE ../include
)

target_link_libraries(all_tests PRIVATE engine_lib gtest gtest_main sfml-system sfml-window sfml-graphics sfml-audio)

set_target_properties(all_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "../.."
)

include(GoogleTest)
gtest_discover_tests(all_tests)
