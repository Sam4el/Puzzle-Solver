#include "variable.h"

#pragma once

class VariableTestHelper {
public:
static const std::set<int> getDomain(const Variable& var) {
    return var.domain;
}
};
