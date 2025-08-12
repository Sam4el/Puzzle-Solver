#include "variable.h"

Variable::Variable(std::string name) : name{name} {}

void Variable::assign(int value) {
    assignedValue = value;
}

void Variable::unassign() {
    assignedValue = std::nullopt;
}