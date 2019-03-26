cmake_minimum_required(VERSION 3.1)

set(HELLOWORLD_VERSION_MAJOR 1)
set(HELLOWORLD_VERSION_MINOR 0)
set(HELLOWORLD_VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})

project(helloworld-all VERSION ${HELLOWORLD_VERSION_MAJOR}.${HELLOWORLD_VERSION_MINOR}.${HELLOWORLD_VERSION_PATCH})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

configure_file (
  "${PROJECT_SOURCE_DIR}/config/config.h.in"
  "${PROJECT_BINARY_DIR}/gen/config.h"
)

include_directories(${PROJECT_BINARY_DIR}/gen ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(lib build/lib)
add_subdirectory(src build/src)
add_subdirectory(test build/test)

set_target_properties(helloworld-lib helloworld test_version PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT ivananisimov2010@gmail.com)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()