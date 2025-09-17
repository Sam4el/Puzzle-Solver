#include "csp.h"

#pragma once

class IValueHeuristic {
 public:
  virtual ~IValueHeuristic() = default;
  virtual const std::set<int> orderValues(
      const CSP& csp, const Variable& var,
      const std::unordered_map<int, int>& assignments) const = 0;
};
