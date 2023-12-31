cmake_minimum_required(VERSION 3.10)

project(R-Type)

find_package(SFML 2.5.1 COMPONENTS graphics window system audio REQUIRED)

set(LIB_SRCS
        src/Components/all_components/Transform.cpp
        src/Components/all_components/Sprite.cpp
        src/Components/all_components/Audio.cpp
        src/World/world.cpp
        src/GameEngine/gameEngine.cpp
        src/Event/event.cpp
)

add_library(engine_lib SHARED ${LIB_SRCS})

target_include_directories(engine_lib
        PRIVATE src/Components
        PRIVATE src/World
        PRIVATE src/GameEngine
        PRIVATE src/Entity
        PRIVATE src/Components/all_components
        PRIVATE src/Event
)

target_link_libraries(engine_lib PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

set(SRCS
        main.cpp
)

add_executable(engine ${SRCS})

target_include_directories(engine
        PRIVATE src/Entity
        PRIVATE src/World
        PRIVATE src/GameEngine
        PRIVATE src/Components
        PRIVATE src/include
)

target_link_libraries(engine PRIVATE engine_lib sfml-graphics sfml-window sfml-system sfml-audio)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Debug' as none was specified.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)

    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()


set(CMAKE_CXX_FLAGS_DEBUG "-g")

set_target_properties(engine_lib PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Lib"
)

set_target_properties(engine PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory(src/tests)
