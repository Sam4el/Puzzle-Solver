add_executable(puzzleSolverTests
    constraint_test.cc
    csp_test.cc
    solver_test.cc
    variable_test.cc)

target_link_libraries(puzzleSolverTests gtest_main solver)
include(GoogleTest)
gtest_discover_tests(puzzleSolverTests)
