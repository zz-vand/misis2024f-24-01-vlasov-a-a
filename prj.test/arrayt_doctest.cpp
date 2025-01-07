#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <arrayt/arrayt.hpp>

#include <string>

TEST_CASE("") {
    ArrayT<char> arr(1);
    CHECK(arr[0] == 0);

    arr.resize(4);
    CHECK(arr.ssize() == 4);

    arr.insert(1, 'a');
    CHECK(arr[1] == 'a');

    arr.remove(1);
    CHECK(arr.ssize() == 4);
    CHECK(arr[1] != 'a');

    arr.insert(3, 9);
    arr.remove(2);
    CHECK(arr[2] == 9);

}

TEST_CASE("") {
    ArrayT<float> arr(1);
    CHECK(arr[0] == 0);

    arr.resize(4);
    CHECK(arr.ssize() == 4);

    arr.insert(1, 1.8);
    CHECK(arr[1] == 1.8f);

    arr.remove(1);
    CHECK(arr.ssize() == 4);
    CHECK(arr[1] == 0);

    arr.insert(3, 9.72);
    arr.remove(2);
    CHECK(arr[2] == 9.72f);

}

TEST_CASE("") {
    ArrayT<std::string> arr(1);
    CHECK(arr[0] == "");

    arr.resize(4);
    CHECK(arr.ssize() == 4);

    arr.insert(1, "cool");
    CHECK(arr[1] == "cool");

    arr.remove(1);
    CHECK(arr.ssize() == 4);
    CHECK(arr[1] == "");

    arr.insert(3, "snow");
    arr.remove(2);
    CHECK(arr[2] == "snow");

}

TEST_CASE("") {
    ArrayT<double> arr(1);
    CHECK(arr[0] == 0);

    arr.resize(4);
    CHECK(arr.ssize() == 4);

    arr.insert(1, 1.8);
    CHECK(arr[1] == 1.8);

    arr.remove(1);
    CHECK(arr.ssize() == 4);
    CHECK(arr[1] == 0);

    arr.insert(3, 9.72);
    arr.remove(2);
    CHECK(arr[2] == 9.72);

}
