if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS_INIT "-Wall")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO_INIT "-O3 -g -DNDEBUG")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS_INIT "-Wall")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O3 -g -DNDEBUG")
endif()

if((NOT DEFINED CMAKE_BUILD_TYPE) OR (CMAKE_BUILD_TYPE STREQUAL ""))
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()
