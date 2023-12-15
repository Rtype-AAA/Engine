cmake_minimum_required(VERSION 3.10)

project(R-Type)

set(SRCS
        main.cpp
)

add_library(all_components SHARED
        Components/all_components/Transform.cpp
        Components/all_components/Rendering.cpp
        Components/all_components/Audio.cpp
)

add_executable(engine ${SRCS})

target_include_directories(engine
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Entity
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(engine PRIVATE all_components)

set_target_properties(engine PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory(tests)
