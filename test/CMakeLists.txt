add_executable(puzzleSolverTests
    csp_test.cc
    solver_test.cc
    variable_test.cc
)

target_link_libraries(puzzleSolverTests gtest_main solverLib)
include(GoogleTest)
gtest_discover_tests(puzzleSolverTests)
