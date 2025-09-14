#include "solver.h"

#include <algorithm>

bool Solver::checkConstraints(std::unordered_map<int, int> &assignments) const {
  const auto &constraints = csp.getConstraints();
  return std::all_of(
      constraints.begin(), constraints.end(),
      [&assignments](const auto &constraint) { return constraint->isSatisfied(assignments); });
}

const Variable *Solver::chooseNextVariable(std::unordered_map<int, int> &assignments) const {
  if (variableHeuristic) {
    return variableHeuristic->chooseVariable(csp, assignments);
  }

  auto unassigned = csp.getUnassignedVariables(assignments);
  return unassigned.empty() ? nullptr : unassigned[0];
}

bool Solver::backtrackingSearch(std::unordered_map<int, int> &assignments) {
  if (csp.getUnassignedVariables(assignments).empty()) {
    return true;
  }

  // TODO use Constraint propagation to reduce domains
  const Variable *activeVariable = chooseNextVariable(assignments);

  if (!activeVariable) {
    return false;
  } else {
    const auto &domain = activeVariable->getDomain();
    for (auto value : domain) {
      assignments[activeVariable->getId()] = value;

      if (checkConstraints(assignments)) {
        if (backtrackingSearch(assignments)) {
          return true;
        }
      }
    }
    assignments.erase(activeVariable->getId());
  }

  return false;
}
