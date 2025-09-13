add_library(solverLib STATIC
    csp.cc
    solver.cc
    variable.cc
)

target_include_directories(solverLib PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)

add_subdirectory(constraints)
