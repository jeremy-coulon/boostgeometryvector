cmake_minimum_required(VERSION 2.8.8)

if(${PROJECT_NAME}_PACKAGING_ENABLED)
    ##########################
    #  CMake exported files  #
    ##########################

    include(CMakePackageConfigHelpers)

    # Generate BoostGeometryVectorConfig.cmake
    configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/BoostGeometryVectorConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/BoostGeometryVectorConfig.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_CMAKEDIR}
        PATH_VARS CMAKE_INSTALL_FULL_INCLUDEDIR
    )

    # Generate BoostGeometryVectorConfigVersion.cmake
    write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/BoostGeometryVectorConfigVersion.cmake
        VERSION ${BoostGeometryVector_VERSION}
        COMPATIBILITY ExactVersion
    )

    ###############
    #  Packaging  #
    ###############

    install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/BoostGeometryVectorConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/BoostGeometryVectorConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_CMAKEDIR}
        COMPONENT dev
    )
endif()
