cmake_minimum_required(VERSION 3.10)

project(engine VERSION 1.0.0 DESCRIPTION "Moteur de jeu")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build the test suite" OFF)

if(WIN32)
    set(SFML_VERSION 2.6.1)
else()
    set(SFML_VERSION 2.5.1)
endif()

if(SFML_VERSION EQUAL 2.6.1)
    set(SFML_SYSTEM_LIB_PATH "/usr/local/lib/libsfml-system.so.2.6.1")
    if(NOT EXISTS "${SFML_SYSTEM_LIB_PATH}")
        message(STATUS "SFML system library not found. Attempting to install SFML...")

        execute_process(
            COMMAND bash -c "echo 'Installing SFML...\n' && cd ${CMAKE_CURRENT_SOURCE_DIR}/SFML && cmake -Bbuild && sudo cmake --build build --config Release --target install"
            RESULT_VARIABLE SFML_INSTALL_RESULT
        )

        if(SFML_INSTALL_RESULT EQUAL 0 AND EXISTS "${SFML_SYSTEM_LIB_PATH}")
            message(STATUS "SFML successfully installed.")
            find_package(SFML 2.6.1 COMPONENTS system window graphics audio QUIET)

            if(NOT SFML_FOUND)
                message(FATAL_ERROR "SFML couldn't be located! Please make sure to install SFML or specify the correct SFML_DIR in your CMake configuration.")
            else()
                set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML/build/lib")
            endif()
        else()
            message(FATAL_ERROR "Failed to install SFML.")
        endif()
    endif()

else()
    find_package(SFML ${SFML_VERSION} COMPONENTS system window graphics audio REQUIRED)
endif()


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
            "tests/GameEngine/TestGameEngine.cpp"
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
        EXPORT quantumvortex-engineTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include/quantumvortex-engine)

install(DIRECTORY
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Archetype/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/all_components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Entity/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Event/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/World/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine/include
        DESTINATION include/quantumvortex-engine)


include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "quantumvortex-engineConfigVersion.cmake"
        VERSION 1.0
        COMPATIBILITY AnyNewerVersion
)

install(EXPORT quantumvortex-engineTargets
        FILE quantumvortex-engineTargets.cmake
        NAMESPACE qtv::
        DESTINATION lib/cmake/quantumvortex-engine)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/quantumvortex-engineConfigVersion.cmake"
        DESTINATION lib/cmake/quantumvortex-engine)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/configPackage/quantumvortex-engineConfig.cmake" DESTINATION lib/cmake/quantumvortex-engine)

set(CPACK_PACKAGE_NAME "QuantumVortex Engine")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Un moteur de jeu personnalisé")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/copyright")
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