#include <memory>
#include <unordered_map>
#include <vector>

#include "variable.h"

#pragma once

class Constraint
{
public:
    virtual ~Constraint() = default;

    // assignments are <ConstraintId, Value>
    virtual bool isSatisfied(const std::unordered_map<int, int> &assignments) const = 0;
    virtual const std::vector<Variable *> &getScope() const = 0;
};
