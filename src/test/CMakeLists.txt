cmake_minimum_required(VERSION 2.8)

option(BoostGeometryVector_BUILD_TEST "Build tests" OFF)

if(BoostGeometryVector_BUILD_TEST)

    project(BoostGeometryVectorTest CXX)

    find_package(Boost REQUIRED unit_test_framework)

    set(${PROJECT_NAME}_FILES
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${PROJECT_SOURCE_DIR}/Assign.cpp
        ${PROJECT_SOURCE_DIR}/Convert.cpp
        ${PROJECT_SOURCE_DIR}/GeometryConstructors.cpp
        ${PROJECT_SOURCE_DIR}/Predicates.cpp
    )

    include_directories(
        ${BoostGeometryVector_INCLUDE_DIR}
        ${Boost_INCLUDE_DIR}
    )

    add_definitions(-DBOOST_TEST_DYN_LINK)

    add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_FILES})

    target_link_libraries(${PROJECT_NAME}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )

endif()
