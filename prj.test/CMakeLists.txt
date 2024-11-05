add_executable(complex_test complex_test.cpp "doctest/doctest.h")
target_link_libraries(complex_test complex)

add_executable(complex_doctest complex_doctest.cpp "doctest/doctest.h")
target_link_libraries(complex_doctest complex)
