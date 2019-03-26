project(helloworld-test)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)


set(TEST_SOURCES test_version.cpp)

add_executable(test_version ${TEST_SOURCES})

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    helloworld-lib
)

enable_testing()

add_test(NAME helloworld_tests COMMAND test_version)