cmake_minimum_required(VERSION 3.10)

project(R-Type)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

file(GLOB HEADER_FILES
        "include/*.h"
        "src/Archetype/include/*.h"
        "src/Components/include/*.h"
        "src/Components/all_components/include/*.h"
        "src/Entity/include/*.h"
        "src/Event/include/*.h"
        "src/World/include/*.h"
        "src/GameEngine/include/*.h"
)
file(GLOB LIB_SRCS
        "src/Components/*.cpp"
        "src/Components/all_components/*.cpp"
        "src/Entity/*.cpp"
        "src/World/*.cpp"
        "src/GameEngine/*.cpp"
        "src/Event/*.cpp"
)

message(STATUS "Lib_SRCS : ${LIB_SRCS}")

add_library(engine_lib SHARED ${LIB_SRCS} ${HEADER_FILES})
target_include_directories(engine_lib PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Archetype/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/all_components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Entity/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Event/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/World/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine/include
)
target_link_libraries(engine_lib PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)

add_executable(engine main.cpp)
target_include_directories(engine PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Archetype/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/all_components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Entity/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Event/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/World/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine/include
)
target_link_libraries(engine PRIVATE engine_lib)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Debug' as none was specified.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)

    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set_target_properties(engine_lib PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Lib")
set_target_properties(engine PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

install(TARGETS engine_lib
        EXPORT engineTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

install(DIRECTORY
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Archetype/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/all_components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Entity/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Event/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/World/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine/include
        DESTINATION include)


include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "engineConfigVersion.cmake"
        VERSION 1.0
        COMPATIBILITY AnyNewerVersion
)

install(EXPORT engineTargets
        FILE engineTargets.cmake
        NAMESPACE engine::
        DESTINATION lib/cmake/engine)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/engineConfigVersion.cmake"
        DESTINATION lib/cmake/engine)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/configPackage/engineConfig.cmake" DESTINATION lib/cmake/engine)
