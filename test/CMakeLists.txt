add_executable(puzzleSolverTests
    csp_test/src/csp_test.cc
    solver_test/src/solver_test.cc
    variable_test/src/variable_test.cc
)

target_include_directories(puzzleSolverTests PRIVATE .)

target_link_libraries(puzzleSolverTests gtest_main solverLib)
include(GoogleTest)
gtest_discover_tests(puzzleSolverTests)
