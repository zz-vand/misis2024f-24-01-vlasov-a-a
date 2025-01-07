#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "stackl/stackL.hpp"

TEST_CASE("") {
    StackL stack;

    CHECK(stack.IsEmpty()); 
    stack.Push(10);
    CHECK(!stack.IsEmpty());     
    CHECK(stack.Top() == 10);
    stack.Push(20);
    CHECK(stack.Top() == 20); 
    stack.Push(30);
    CHECK(stack.Top() == 30); 
    stack.Pop();
    CHECK(stack.Top() == 20); 
    stack.Pop();
    CHECK(stack.Top() == 10); 
    stack.Pop();
    CHECK(stack.IsEmpty()); 
}

TEST_CASE("") {
    StackL stack;

    CHECK_THROWS_AS(stack.Top(), std::logic_error);
    CHECK_NOTHROW(stack.Pop()); 
    stack.Push(42);
    CHECK(stack.Top() == 42); 
}

TEST_CASE("") {
    StackL stack1;

    stack1.Push(1);
    stack1.Push(2);
    stack1.Push(3);
    CHECK(stack1.Top() == 3);
    StackL stack2 = stack1;     
    stack2.Pop();
    CHECK(stack2.Top() == 2); 
    StackL stack3 = std::move(stack1);     
    CHECK(stack3.Top() == 3);     
    CHECK(stack1.IsEmpty()); 
}
