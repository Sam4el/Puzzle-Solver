#include "csp.h"

#pragma once

class ValueHeuristic {
 public:
  virtual ~ValueHeuristic() = default;
  virtual const std::set<int> orderValues(
      const CSP& csp, const Variable& var,
      const std::unordered_map<int, int>& assignments) const = 0;
};
