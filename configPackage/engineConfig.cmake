include(CMakeFindDependencyMacro)

find_package(SFML COMPONENTS graphics window system audio CONFIG REQUIRED)

include("${CMAKE_CURRENT_LIST_DIR}/engineTargets.cmake")
