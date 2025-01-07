#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "queuea/queuea.hpp" 

TEST_CASE("Testing QueueA") {
    QueueA queue;

    CHECK(queue.IsEmpty() == true);
    CHECK(queue.Count() == 0);

   
    queue.Push(1);
    CHECK(queue.IsEmpty() == false);
    CHECK(queue.Count() == 1);
    CHECK(queue.Top() == 1);

    queue.Push(2);
    CHECK(queue.Count() == 2);
    CHECK(queue.Top() == 1);

    queue.Push(3);
    CHECK(queue.Count() == 3);
    CHECK(queue.Top() == 1);

    queue.Pop();
    CHECK(queue.Count() == 2);
    CHECK(queue.Top() == 2);

    queue.Pop();
    CHECK(queue.Count() == 1);
    CHECK(queue.Top() == 3);

    queue.Pop();
    CHECK(queue.IsEmpty() == true);
    CHECK_THROWS_AS(queue.Top(), std::logic_error); 

    
    queue.Push(4);
    CHECK(queue.Count() == 1);
    CHECK(queue.Top() == 4);

    queue.Push(5);
    CHECK(queue.Count() == 2);
    CHECK(queue.Top() == 4);

  
    queue.Clear();
    CHECK(queue.IsEmpty() == true);
    CHECK_THROWS_AS(queue.Top(), std::logic_error); 

    for (int i = 0; i < 10; ++i) {
        queue.Push(i);
        CHECK(queue.Count() == i + 1);
        CHECK(queue.Top() == 0); 
    }

    for (int i = 0; i < 10; ++i) {
        queue.Pop();
        CHECK(queue.Count() == 9 - i);
        if (queue.Count() > 0) {
            CHECK(queue.Top() == i + 1); 
        }
    }
}
