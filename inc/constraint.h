#include <memory>
#include <vector>

#include "variable.h"

#pragma once

class Constraint {
public:
virtual bool isSatisfied() const = 0;
virtual std::vector<std::unique_ptr<Variable>> getScope() const = 0;
};