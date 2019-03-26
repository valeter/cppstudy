project(helloworld-lib)

set(SOURCES lib.cpp)
set(HEADERS lib.h)

add_library(helloworld-lib STATIC ${SOURCES} ${HEADERS})
target_include_directories(helloworld-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})