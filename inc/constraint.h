#include <memory>
#include <unordered_map>
#include <vector>

#include "variable.h"

#pragma once

class Constraint
{
public:
    virtual ~Constraint() = default;
    // assignments are <ConstraintName, Value>
    virtual bool isSatisfied(std::unordered_map<std::string, int> assignments) const = 0;
    virtual std::vector<Variable *> getScope() const = 0;
};
