cmake_minimum_required(VERSION 3.22)

project(engine VERSION 1.0.0 DESCRIPTION "Moteur de jeu")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build the test suite" OFF)

if(WIN32)
    set(SFML_VERSION 2.6.1)
    
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x86-windows/share/sfml")
else()
    set(SFML_VERSION 2.5.1)
    find_package(SFML 2.5.1 COMPONENTS system window graphics audio network QUIET)

    if(NOT SFML_FOUND)
        message(STATUS "SFML couldn't be found. Attempting to install SFML...")

        include(FetchContent)
        FetchContent_Declare(SFML
                GIT_REPOSITORY https://github.com/SFML/SFML.git
                GIT_TAG 2.5.1)
        FetchContent_MakeAvailable(SFML)

    endif()
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources)

file(GLOB HEADER_FILES
        "include/*.h"
        "src/Archetype/include/*.h"
        "src/Components/include/*.h"
        "src/Components/all_components/include/*.h"
        "src/Entity/include/*.h"
        "src/Event/include/*.h"
        "src/World/include/*.h"
        "src/GameEngine/include/*.h"
        "src/Other/include/*.h"
        "src/toSFML/include/*.h"
        "src/Script/include/*.h"
)

file(GLOB HEADER_RESSOURCES
        "includeRessources/*.h"
)

file(GLOB LIB_SRCS
        "src/Components/*.cpp"
        "src/Components/all_components/*.cpp"
        "src/Entity/*.cpp"
        "src/World/*.cpp"
        "src/GameEngine/*.cpp"
        "src/Event/*.cpp"
        "src/Other/*.cpp"
        "src/toSFML/*.cpp"
        "src/Script/*.cpp"
)

if (WIN32)
    file(COPY 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Textures 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Font
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Music
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Sounds
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release
    )

    file(COPY 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Textures 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Font
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Music
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Sounds
        DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/Nebula Striker"
    )
else()
    file(COPY 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Textures 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Font
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Music
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Sounds
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
    )

    file(COPY 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Textures 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Font
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Music
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Sounds
        DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/Nebula Striker"
    )
endif()

set(COPIED_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Textures 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Font
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Music
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ressources/Sounds
)

set(COMMON_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Archetype/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components/all_components/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Entity/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Event/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/World/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Other/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/toSFML/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Script/include
)

set(RESSOURCES_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/includeRessources
)

if (WIN32)
    add_library(engine_lib_static STATIC ${LIB_SRCS} ${HEADER_FILES})
    target_include_directories(engine_lib_static PRIVATE ${COMMON_INCLUDE_DIRS})
    target_link_libraries(engine_lib_static PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)

    add_library(engine_lib SHARED ${LIB_SRCS} ${HEADER_FILES})
    target_include_directories(engine_lib PRIVATE ${COMMON_INCLUDE_DIRS})
    target_link_libraries(engine_lib PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)

    add_executable(engine main.cpp ${HEADER_RESSOURCES})
    target_include_directories(engine PRIVATE ${COMMON_INCLUDE_DIRS} ${COPIED_DIRECTORIES} ${RESSOURCES_INCLUDE_DIRS})
    target_link_libraries(engine PRIVATE engine_lib)

    add_dependencies(engine_lib engine_lib_static)
    add_dependencies(engine engine_lib)
else ()
    add_library(engine_lib SHARED ${LIB_SRCS} ${HEADER_FILES})
    target_include_directories(engine_lib PRIVATE ${COMMON_INCLUDE_DIRS})
    target_link_libraries(engine_lib PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)

    add_executable(engine main.cpp ${HEADER_RESSOURCES})
    target_include_directories(engine PRIVATE ${COMMON_INCLUDE_DIRS} ${COPIED_DIRECTORIES} ${RESSOURCES_INCLUDE_DIRS})
    target_link_libraries(engine PRIVATE engine_lib)

    add_dependencies(engine engine_lib)
endif ()

if(BUILD_TESTS)
    file(GLOB LIB_SRCS_TEST
            "tests/Components/all_components/*.cpp"
            "tests/Entity/*.cpp"
            "tests/Event/*.cpp"
            "tests/GameEngine/*.cpp"
            "tests/World/*.cpp"
            "tests/Other/*.cpp"
            "tests/toSFML/*.cpp"
    )
    add_executable(all_tests ${LIB_SRCS_TEST})
    target_include_directories(all_tests PRIVATE

    )
    target_link_libraries(all_tests PRIVATE engine_lib gtest gtest_main)

    include(GoogleTest)
    gtest_discover_tests(all_tests)
    set_target_properties(all_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endif()

if(WIN32)
    set_target_properties(engine_lib_static PROPERTIES OUTPUT_NAME engine_lib PREFIX "")
    set_target_properties(engine_lib PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Lib")
    set_target_properties(engine PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/Nebula Striker")
else()
    set_target_properties(engine_lib PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Lib")
    set_target_properties(engine PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Nebula Striker")
endif()

install(TARGETS engine_lib
        EXPORT engineTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include/engine)

install(DIRECTORY
        ${COMMON_INCLUDE_DIRS}
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
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/copyright")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

if (WIN32)
    set(CPACK_GENERATOR "ZIP")
else()
    set(CPACK_GENERATOR "TGZ")

endif ()

include(CPack)

set(CPACK_VERBOSE ON)