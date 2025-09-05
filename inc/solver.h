#include "csp.h"

#pragma once

class Solver {
 public:
  Solver() = delete;
  Solver(CSP &csp) : csp{csp} {}

  bool backtrackingSearch(std::unordered_map<int, int> &assignments);

 private:
  bool checkConstraints(std::unordered_map<int, int> &assignments) const;
  std::vector<Variable *> getUnassignedVariables(
      std::unordered_map<int, int> &assignments) const;

  void forwardChecking();
  void arcConsistency();
  void minimumRemainingValues();
  void leastConstrainingValue();
  void constraintPropagation();

  CSP &csp;
};
