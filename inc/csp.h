#include "constraint.h"
#include "variable.h"

#pragma once

class CspTestHelper;

class CSP {
  friend class CspTestHelper;

 public:
  CSP() = default;
  CSP(const CSP &) = delete;
  CSP &operator=(const CSP &) = delete;
  CSP(CSP &&) = delete;
  CSP &operator=(CSP &&) = delete;

  inline void addConstraint(std::unique_ptr<Constraint> &&constraint) {
    constraints.push_back(std::move(constraint));
  }
  inline void addVariable(Variable var) { variables.push_back(std::move(var)); }
  inline void assignVariable(Variable &var) { var.assign(); }

  std::vector<Variable *> getUnassignedVariables();

 private:
  std::vector<Variable> variables;
  std::vector<std::unique_ptr<Constraint>> constraints;
};
