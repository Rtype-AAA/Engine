vcpkg_from_git(
        OUT_SOURCE_PATH SOURCE_PATH
        URL "https://github.com/Rtype-AAA/Engine.git"
        REF main
)

vcpkg_configure_cmake(
        SOURCE_PATH ${SOURCE_PATH}
        PREFER_NINJA
)

vcpkg_install_cmake()
vcpkg_fixup_cmake_targets(CONFIG_PATH lib/cmake/${PORT})
