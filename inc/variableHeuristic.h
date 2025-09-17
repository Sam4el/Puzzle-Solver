#include "csp.h"

#pragma once

class IVariableHeuristic {
 public:
  ~IVariableHeuristic() = default;
  virtual const Variable* chooseVariable(
      const CSP& csp, const std::unordered_map<int, int>& assignments) const = 0;
};
