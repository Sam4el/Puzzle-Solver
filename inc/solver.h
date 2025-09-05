#include "csp.h"

#pragma once

class Solver
{
public:
    Solver() = delete;
    Solver(CSP &csp) : csp{csp} {}

    std::unordered_map<int, int> run();

private:
    void assignVariable(Variable &var, int value);
    void forwardChecking();
    void arcConsistency();
    void minimumRemainingValues();
    void leastConstrainingValue();
    void unassignVariable(Variable &var);
    void constraintPropagation();

    bool backtrackingSearch();

    CSP &csp;
    // TODO change string to int
    // TODO change int to some template type
    std::unordered_map<int, int> assignments;
};
