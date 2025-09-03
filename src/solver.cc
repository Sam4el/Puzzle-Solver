#include "solver.h"

namespace {

} // namespace

bool Solver::backtrackingSearch() {
    if (csp.getUnassignedVariables().size() == 0) {
        return true;
    }
    else {

    }
}

bool Solver::assignVariable(Variable& var, int value) {
    // Try/catch?

    var.assign(value);
}

void Solver::unassignVariable(Variable& var) {
    var.unassign();
}

void Solver::constraintPropagation() {

}

std::unordered_map<std::string, int> Solver::run() {
    backtrackingSearch();

    return assignments;
}
