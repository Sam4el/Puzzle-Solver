#include "variableHeuristic.h"

#pragma once

class MRV : public VariableHeuristic {
 public:
  const Variable* chooseVariable(
      const CSP& csp, const std::unordered_map<int, int>& assignments) const override;
};
