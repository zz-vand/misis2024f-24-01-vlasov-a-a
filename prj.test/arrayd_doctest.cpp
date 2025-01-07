#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <arrayd/arrayd.hpp>

TEST_CASE("[arrayd] - ArrayD ctor") {
    ArrayD arr1(1);
    CHECK(arr1.ssize() == 1);
    CHECK(arr1.capacity() == 1);

    ArrayD arr2(arr1);
    CHECK(arr2[0] == 0.0);

    ArrayD arr(0);
    CHECK(arr.ssize() == 0);
}

TEST_CASE("[arrayd] - ArrayD insert") {
    ArrayD arr(1);
    arr.insert(1, 2.5);
    CHECK(arr[1] == 2.5);
}

TEST_CASE("[arrayd] - ArrayD resize") {
    ArrayD arr(10);
    arr.resize(8);
    CHECK(arr.ssize() == 8);
    arr.resize(8);
    CHECK(arr.ssize() == 8);

}
