cmake_minimum_required(VERSION 3.10)
project(all_components VERSION 1.0)

set(LIB_SRCS
        Transform.cpp
        Rendering.cpp
        Audio.cpp
)

add_library(all_components SHARED ${LIB_SRCS})

target_include_directories(all_components
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(all_components
        PRIVATE -Wall
)

set_target_properties(all_components PROPERTIES
        POSITION_INDEPENDENT_CODE ON
)