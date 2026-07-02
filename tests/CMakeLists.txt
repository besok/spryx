add_executable(test_rnea test_rnea.cpp)
target_link_libraries(test_rnea PRIVATE spryx)

add_test(NAME test_rnea COMMAND test_rnea)
