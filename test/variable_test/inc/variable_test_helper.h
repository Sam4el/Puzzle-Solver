#include "variable.h"

#pragma once

class VariableTestHelper {
public:
static const std::string getName(const Variable& var) {
    return var.name;
}

static const std::set<int> getDomain(const Variable& var) {
    return var.domain;
}

static const std::optional<int> getAssignedValue(const Variable& var) {
    return var.assignedValue;
}
};
