include(CMakeFindDependencyMacro)

find_package(SFML COMPONENTS graphics window system audio CONFIG REQUIRED)

include("${CMAKE_CURRENT_LIST_DIR}/quantumvortex-engineTargets.cmake")

set(quantumvortex_engine_INCLUDE_DIRS ${quantumvortex_engine_INCLUDE_DIRS} PARENT_SCOPE)
