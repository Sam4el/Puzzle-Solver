#include <iostream>

#include "solver.h"

int main () {
    std::cout << "Hello World CSP Solver" << std::endl;

    CSP csp;
    Solver solverEngine{csp};

    return 0;
}
