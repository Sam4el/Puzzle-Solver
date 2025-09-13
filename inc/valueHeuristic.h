#include "csp.h"

#pragma once

class ValueHeuristic {
 public:
  virtual ~ValueHeuristic() = default;
  virtual std::set<int> orderValues(const CSP& csp, const Variable& var,
                                    std::unordered_map<int, int>& assignments) = 0;
};
