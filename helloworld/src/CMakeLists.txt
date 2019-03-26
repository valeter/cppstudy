project(helloworld-src)

set(SOURCES helloworld.cpp)

add_executable(helloworld ${SOURCES})

target_link_libraries(helloworld
    helloworld-lib
)

install(TARGETS helloworld RUNTIME DESTINATION ../bin)