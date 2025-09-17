#include "csp.h"

#pragma once

class CspTestHelper {
 public:
  class ConstraintStub : public IConstraint {
    bool isSatisfied(const std::unordered_map<int, int> &assignments) const override {
      return false;
    }
    const std::vector<const Variable *> &getScope() const override { return scope; }

    std::vector<const Variable *> scope{};
  };
};
