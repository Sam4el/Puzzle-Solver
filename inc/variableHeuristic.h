#include "csp.h"

#pragma once

class VariableHeuristic {
 public:
  ~VariableHeuristic() = default;
  virtual Variable* chooseVariable(const CSP& csp,
                                   const std::unordered_map<int, int>& assignments) = 0;
};
