include(CMakeFindDependencyMacro)
find_dependency(SFML 2.5.1 COMPONENTS graphics window system audio REQUIRED)

include("${CMAKE_CURRENT_LIST_DIR}/engineTargets.cmake")
