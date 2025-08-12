#include "constraint.h"
#include "variable.h"

#pragma once

class CSP {
public:
void assignVariable(int value, std::string name = "");

// TODO Methods: names and hat should they do?
// TODO How do I know amount of variables and constraints?
// TODO How do I add variables and constraints? Should they be public?

private:
std::vector<Variable> variables;
std::vector<std::unique_ptr<Constraint>> constraints;
};