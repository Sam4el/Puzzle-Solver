#include <memory>
#include <unordered_map>
#include <vector>

#include "variable.h"

#pragma once

class Constraint {
 public:
  virtual ~Constraint() = default;

  // assignments are <ConstraintId, Value>
  // TODO change int to template argument in the future?
  virtual bool isSatisfied(const std::unordered_map<int, int> &assignments) const = 0;
  virtual const std::vector<const Variable *> &getScope() const = 0;
};
