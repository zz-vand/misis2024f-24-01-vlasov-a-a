#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <arrayt/arrayt.hpp>

#include <string>

TEST_CASE("[arrayt] - ArrayT ctor") {
    ArrayT<int> arr(1);
    CHECK(arr[0] == 0);

    ArrayT<std::string> arr1(1);
    arr1.resize(4);
    CHECK(arr1[3] == "");
}
