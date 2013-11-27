cmake_minimum_required(VERSION 2.8)

###################
#  Documentation  #
###################

# Generate VERSION.txt
file(WRITE
    ${CMAKE_CURRENT_BINARY_DIR}/VERSION.txt
    "${PROJECT_NAME} v${${PROJECT_NAME}_VERSION}"
)

option(${PROJECT_NAME}_BUILD_DOC "Generate API documentation with Doxygen" OFF)
if(${PROJECT_NAME}_BUILD_DOC)
    find_package(Doxygen REQUIRED)
    # Copy license file to test generated documentation
    file(COPY ${PROJECT_SOURCE_DIR}/LICENSE_1_0.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    # Generate Doxyfile
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
        ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        @ONLY
    )
    # Doxygen target
    add_custom_target(
        ${PROJECT_NAME}_DOCUMENTATION
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
        SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
    )
endif()

###############
#  Packaging  #
###############
if(${PROJECT_NAME}_PACKAGING_ENABLED)
    install(FILES
        ${PROJECT_SOURCE_DIR}/LICENSE_1_0.txt
        ${PROJECT_SOURCE_DIR}/README.txt
        ${PROJECT_SOURCE_DIR}/INSTALL.txt
        ${CMAKE_CURRENT_BINARY_DIR}/VERSION.txt
        DESTINATION ${CMAKE_INSTALL_DOCDIR}
        COMPONENT doc
    )
    if(${PROJECT_NAME}_BUILD_DOC)
        install(CODE "execute_process(COMMAND \"${CMAKE_COMMAND}\" --build ${CMAKE_BINARY_DIR} --target ${PROJECT_NAME}_DOCUMENTATION)")
        install(DIRECTORY
            ${CMAKE_CURRENT_BINARY_DIR}/html
            DESTINATION ${CMAKE_INSTALL_DOCDIR}
            COMPONENT doc
        )
    endif()
endif()
