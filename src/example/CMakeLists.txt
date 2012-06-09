cmake_minimum_required(VERSION 2.8)

option(BoostGeometryVector_BUILD_EXAMPLE "Build examples" OFF)

if(BoostGeometryVector_BUILD_EXAMPLE)

    project(BoostGeometryVectorExample CXX)

    find_package(Boost REQUIRED)

    include_directories(
        ${BoostGeometryVector_INCLUDE_DIR}
        ${Boost_INCLUDE_DIR}
    )

    add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/example.cpp)
    
endif()
