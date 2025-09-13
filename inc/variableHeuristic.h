#include "csp.h"

#pragma once

class VariableHeuristic {
 public:
  ~VariableHeuristic() = default;
  virtual const Variable* chooseVariable(
      const CSP& csp, const std::unordered_map<int, int>& assignments) const = 0;
};
