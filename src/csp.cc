#include "csp.h"

void CSP::addVariable(Variable var) {
    variables.push_back(std::move(var));
}

void CSP::addConstraint(std::unique_ptr<Constraint>&& constraint) {
    constraints.push_back(std::move(constraint));
}

void CSP::assignVariable(Variable& var, int value) {
    // TODO try/catch?
    var.assign(value);
}

std::vector<Variable*> CSP::getUnassignedVariables() {
    std::vector<Variable*> unassignedVariables;

    for(auto& variable : variables) {
        if (!variable.isAssigned()) {
            unassignedVariables.push_back(&variable);
        }
    }

    return unassignedVariables;
}
