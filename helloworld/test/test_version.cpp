#define BOOST_TEST_MODULE helloworld_test_module


#include <boost/test/unit_test.hpp>

#include "lib.h"


BOOST_AUTO_TEST_SUITE(helloworld_test_suite)

BOOST_AUTO_TEST_CASE(helloword_test_version)
{
    BOOST_CHECK(buildVersion() > 0);
}

BOOST_AUTO_TEST_SUITE_END()