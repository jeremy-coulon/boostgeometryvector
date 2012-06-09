# - Config file for the BoostGeometryVector package
# It defines the following variables
#  BoostGeometryVector_INCLUDE_DIR  - include directory for BoostGeometryVector
#  BoostGeometryVector_INCLUDE_DIRS - include directories for BoostGeometryVector

@PACKAGE_INIT@

set(BoostGeometryVector_INCLUDE_DIR 
    "@PACKAGE_CMAKE_INSTALL_FULL_INCLUDEDIR@"
    CACHE PATH "Include directory for BoostGeometryVector"
)
if(BoostGeometryVector_FIND_REQUIRED)
    set_and_check(BoostGeometryVector_INCLUDE_DIRS "${BoostGeometryVector_INCLUDE_DIR}")
else()
    set(BoostGeometryVector_INCLUDE_DIRS "${BoostGeometryVector_INCLUDE_DIR}")
endif()

mark_as_advanced(
    BoostGeometryVector_DIR
    BoostGeometryVector_INCLUDE_DIR
)
