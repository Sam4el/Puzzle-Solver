#include "csp.h"

#pragma once

class Solver {
public:
Solver() = delete;
Solver(CSP& csp) : csp{csp} {}

bool backtrackingSearch();
bool assignVariable(Variable& var, int value); // Should it be reference?
void unassignVariable(Variable& var); // Should it be reference?
void constraintPropagation();

private:
CSP& csp;
};