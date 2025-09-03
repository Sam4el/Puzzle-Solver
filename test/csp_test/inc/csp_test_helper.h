#include "csp.h"

#pragma once

class CspTestHelper {
public:
    class ConstraintStub : public Constraint {
        bool isSatisfied(std::unordered_map<std::string, int> assignments) const override {
            return false;
        }
        std::vector<Variable*> getScope() const override {
            return {};
        }
    };

    static const int getVariablesSize(const CSP& csp) {
        return csp.variables.size();
    }

    static const int getConstraintsSize(const CSP& csp) {
        return csp.constraints.size();
    }
};