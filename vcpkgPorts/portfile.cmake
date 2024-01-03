set(SOURCE_PATH ${CMAKE_CURRENT_LIST_DIR}/../../../Engine)

vcpkg_configure_cmake(
        SOURCE_PATH ${SOURCE_PATH}
        PREFER_NINJA
)

vcpkg_install_cmake()
file(INSTALL ${SOURCE_PATH}/configPackage/copyright
        DESTINATION ${CURRENT_PACKAGES_DIR}/share/engine)
vcpkg_fixup_cmake_targets(CONFIG_PATH lib/cmake/engine)
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/share")
