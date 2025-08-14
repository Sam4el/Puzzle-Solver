#include "constraint.h"
#include "variable.h"

#pragma once

class CSP {
public:
void addVariable(Variable var);
void addConstraint(Constraint constraint);
void assignVariable(Variable& var, int value);

// TODO Methods: names and hat should they do?
// TODO How do I know amount of variables and constraints?
// TODO How do I add variables and constraints? Should they be public?

private:
std::vector<Variable> variables;
std::vector<std::unique_ptr<Constraint>> constraints;
};
