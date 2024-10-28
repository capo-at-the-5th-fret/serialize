cmake_minimum_required(VERSION 3.28)

project(serialize
    VERSION 0.1.0
    LANGUAGES CXX
)

add_subdirectory(src)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)

    option(SERIALIZE_BUILD_TESTS "Enable or disable the building of tests" ON)
    #option(SERIALIZE_BUILD_EXAMPLES "Enable or disable the building of examples" ON)
    #option(SERIALIZE_BUILD_BENCHMARKS "Enable or disable the building of benchmarks" OFF)
    #option(SERIALIZE_ENABLE_INSTALL "Enable or disable the install rule" ON)

    if (SERIALIZE_BUILD_TESTS)
        enable_testing()
        add_subdirectory(tests)
    endif()

    #if (SERIALIZE_BUILD_EXAMPLES)
    #    add_subdirectory(examples)
    #endif()

    #if (SERIALIZE_BUILD_BENCHMARKS)
    #    add_subdirectory(benchmarks)
    #endif()
endif()

# if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)

#     option(SERIALIZE_BUILD_TESTS "Enable or disable the building of tests" ON)
#     option(SERIALIZE_BUILD_EXAMPLES "Enable or disable the building of examples" ON)
#     option(SERIALIZE_BUILD_BENCHMARKS "Enable or disable the building of benchmarks" ON)
#     #option(SERIALIZE_ENABLE_INSTALL "Enable or disable the install rule" ON)

#     # if (SERIALIZE_BUILD_TESTS)
#     #     enable_testing()
#     #     add_subdirectory(tests)
#     # endif()

#     if (SERIALIZE_BUILD_EXAMPLES)
#         add_subdirectory(examples)
#     endif()

#     # if (SERIALIZE_BUILD_BENCHMARKS)
#     #     add_subdirectory(benchmarks)
#     # endif()

#     # if (SERIALIZE_ENABLE_INSTALL)

#     #     include(GNUInstallDirs)
#     #     include(CMakePackageConfigHelpers)

#     #     # NOTE 1: The XXX_PACKAGE_TARGETS variable is referenced inside of the
#     #     # xxxConfig.cmake.in file, so if the name of this variable changes, it
#     #     # must be updated inside of the xxxConfig.cmake.in file.
#     #     #
#     #     # NOTE 2: If value of this variable changes, the xxxConfig.cmake.in file
#     #     # name must be renamed to match the new value.
#     #     set(SERIALIZE_PACKAGE_NAME ${PROJECT_NAME})
#     #     set(SERIALIZE_PACKAGE_TARGETS ${SERIALIZE_PACKAGE_NAME}Targets)

#     #     set(SERIALIZE_INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_INCLUDEDIR})
#     #     set(SERIALIZE_INSTALL_CMAKE_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${SERIALIZE_PACKAGE_NAME})

#     #     set(SERIALIZE_CONFIG_DIR ${PROJECT_BINARY_DIR}/cmake)
#     #     set(SERIALIZE_CONFIG_IN cmake/${SERIALIZE_PACKAGE_NAME}Config.cmake.in)
#     #     set(SERIALIZE_CONFIG ${SERIALIZE_CONFIG_DIR}/${SERIALIZE_PACKAGE_NAME}Config.cmake)
#     #     set(SERIALIZE_CONFIG_VERSION ${SERIALIZE_CONFIG_DIR}/${SERIALIZE_PACKAGE_NAME}ConfigVersion.cmake)

#     #     configure_package_config_file(
#     #         ${SERIALIZE_CONFIG_IN}
#     #         ${SERIALIZE_CONFIG}
#     #         INSTALL_DESTINATION ${SERIALIZE_INSTALL_CMAKE_DIR}
#     #     )

#     #     # major.minor.patch1 is compatible with major.minor.patch2..n
#     #     # if no VERSION is specified, the ${PROJECT_VERSION} variable will be
#     #     # used. if the ${PROJECT_VERSION} is not set, CMake will output an
#     #     # error
#     #     write_basic_package_version_file(
#     #         ${SERIALIZE_CONFIG_VERSION}
#     #         COMPATIBILITY SameMinorVersion
#     #     )

#     #     install(
#     #         FILES
#     #             ${SERIALIZE_CONFIG}
#     #             ${SERIALIZE_CONFIG_VERSION}
#     #         DESTINATION ${SERIALIZE_INSTALL_CMAKE_DIR}
#     #     )

#     #     install(TARGETS ${SERIALIZE_PACKAGE_NAME}
#     #         EXPORT ${SERIALIZE_PACKAGE_TARGETS}
#     #         ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     #         LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     #         RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#     #     )
        
#     #     install(EXPORT ${SERIALIZE_PACKAGE_TARGETS}
#     #         NAMESPACE ${SERIALIZE_PACKAGE_NAME}::
#     #         DESTINATION ${SERIALIZE_INSTALL_CMAKE_DIR}
#     #     )

#     # endif()

# endif()
