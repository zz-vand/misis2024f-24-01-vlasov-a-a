add_executable(complex_test complex_test.cpp "doctest/doctest.h")
target_link_libraries(complex_test complex)

add_executable(complex_doctest complex_doctest.cpp "doctest/doctest.h")
target_link_libraries(complex_doctest complex)

add_executable(rational_test rational_test.cpp "doctest/doctest.h")
target_link_libraries(rational_test rational)

add_executable(arrayd_test arrayd_test.cpp "doctest/doctest.h")
target_link_libraries(arrayd_test arrayd)
