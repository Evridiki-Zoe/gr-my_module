find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_MY_MODULE gnuradio-my_module)

FIND_PATH(
    GR_MY_MODULE_INCLUDE_DIRS
    NAMES gnuradio/my_module/api.h
    HINTS $ENV{MY_MODULE_DIR}/include
        ${PC_MY_MODULE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_MY_MODULE_LIBRARIES
    NAMES gnuradio-my_module
    HINTS $ENV{MY_MODULE_DIR}/lib
        ${PC_MY_MODULE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-my_moduleTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_MY_MODULE DEFAULT_MSG GR_MY_MODULE_LIBRARIES GR_MY_MODULE_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_MY_MODULE_LIBRARIES GR_MY_MODULE_INCLUDE_DIRS)
