cmake_minimum_required(VERSION 3.10)

project(engine VERSION 1.0.0 DESCRIPTION "Moteur de jeu")

option(BUILD_TESTS "Build the test suite" OFF)

find_package(SFML COMPONENTS graphics window system audio CONFIG REQUIRED)

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

if(BUILD_TESTS)
    file(GLOB LIB_SRCS_TEST
            "tests/Components/all_components/TestSprite.cpp"
            "tests/Components/all_components/TestTransform.cpp"
            "tests/Entity/TestEntity.cpp"
            "tests/Entity/TestEntityManager.cpp"
            "tests/Event/TestEvent.cpp"
            "tests/World/TestWorld.cpp"
    )
    add_executable(all_tests ${LIB_SRCS_TEST})
    target_include_directories(all_tests PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/src/Archetype/include
            ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/include
            ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/all_components/include
            ${CMAKE_CURRENT_SOURCE_DIR}/src/Entity/include
            ${CMAKE_CURRENT_SOURCE_DIR}/src/Event/include
            ${CMAKE_CURRENT_SOURCE_DIR}/src/World/include
            ${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine/include
    )
    target_link_libraries(all_tests PRIVATE engine_lib gtest gtest_main)

    include(GoogleTest)
    gtest_discover_tests(all_tests)
    set_target_properties(all_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endif()

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
        INCLUDES DESTINATION include/engine)

install(DIRECTORY
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Archetype/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/all_components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Entity/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Event/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/World/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine/include
        DESTINATION include/engine)


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

set(CPACK_PACKAGE_NAME "QuantumVortex Engine")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Un moteur de jeu personnalisé")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/configPackage/copyright")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

if (WIN32)
    set(CPACK_GENERATOR "NSIS;ZIP")
    set(CPACK_NSIS_MODIFY_PATH ON)
else()
    set(CPACK_GENERATOR "RPM;TGZ")
    set(CPACK_RPM_PACKAGE_LICENSE "MIT")
    set(CPACK_RPM_PACKAGE_GROUP "Amusements/Games")
    set(CPACK_RPM_COMPRESSION_TYPE "xz")
endif ()

include(CPack)

set(CPACK_VERBOSE ON)