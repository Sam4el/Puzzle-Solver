#include "constraint.h"
#include "variable.h"

#pragma once

class CspTestHelper;

class CSP {
friend class CspTestHelper;

public:
void addConstraint(std::unique_ptr<Constraint>&& constraint);
void addVariable(Variable var);
void assignVariable(Variable& var, int value);

std::vector<Variable*> getUnassignedVariables();

private:
std::vector<Variable> variables;
std::vector<std::unique_ptr<Constraint>> constraints;
// TODO Optimization needed?
// Maybe add unordered_map<string, int> to keep quick acces
// to Variables or Constraints by name.
};
