cmake_minimum_required(VERSION 2.8)

option(BoostGeometryVector_BUILD_TEST "Build tests" ${BUILD_ALL})

if(BoostGeometryVector_BUILD_TEST)

    project(TestBoostGeometryVector CXX)

    find_package(Boost REQUIRED unit_test_framework)

    set(${PROJECT_NAME}_FILES
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/Assign.cpp
        ${PROJECT_SOURCE_DIR}/src/Convert.cpp
        ${PROJECT_SOURCE_DIR}/src/GeometryConstructors.cpp
        ${PROJECT_SOURCE_DIR}/src/Length.cpp
        ${PROJECT_SOURCE_DIR}/src/Predicates.cpp
        ${PROJECT_SOURCE_DIR}/src/Products.cpp
        ${PROJECT_SOURCE_DIR}/src/Transform.cpp
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
