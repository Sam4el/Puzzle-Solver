#include "csp.h"

#pragma once

class Solver {
public:
Solver() = delete;
Solver(CSP& csp) : csp{csp} {}

std::unordered_map<std::string, int> run();

private:
void forwardChecking();
void arcConsistency();
void minimumRemainingValues();
void leastConstrainingValue();
void unassignVariable(Variable& var);
void constraintPropagation();

bool backtrackingSearch();
bool assignVariable(Variable& var, int value);

CSP& csp;
//TODO change string to int
//TODO change int to some template type
std::unordered_map<std::string, int> assignments;
};
