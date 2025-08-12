add_library(solver STATIC 
    constraint.cc
    csp.cc
    solver.cc
    variable.cc)

target_include_directories(solver PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)