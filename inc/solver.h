#include "csp.h"

#pragma once

class Solver {
public:
Solver() = delete;
Solver(CSP& csp) : csp{csp} {}

bool backtrackingSearch();
bool assignVariable(Variable& var, int value);
void unassignVariable(Variable& var);
void constraintPropagation();

private:
CSP& csp;
};
