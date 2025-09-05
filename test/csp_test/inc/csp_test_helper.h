#include "csp.h"

#pragma once

class CspTestHelper {
 public:
  class ConstraintStub : public Constraint {
    bool isSatisfied(const std::unordered_map<int, int> &assignments) const override {
      return false;
    }
    const std::vector<Variable *> &getScope() const override { return scope; }

    std::vector<Variable *> scope{};
  };
};