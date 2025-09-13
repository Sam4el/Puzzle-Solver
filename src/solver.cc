#include "solver.h"

#include <algorithm>

bool Solver::checkConstraints(std::unordered_map<int, int> &assignments) const {
  const auto &constraints = csp.getConstraints();
  return std::all_of(
      constraints.begin(), constraints.end(),
      [&assignments](const auto &constraint) { return constraint->isSatisfied(assignments); });
}

bool Solver::backtrackingSearch(std::unordered_map<int, int> &assignments) {
  if (getUnassignedVariables(assignments).empty()) {
    return true;
  }

  // TODO use heuristics to choose variable
  // TODO use Constraint propagation to reduce domains

  auto activeVariable = getUnassignedVariables(assignments)[0];
  const auto &domain = activeVariable->getDomain();

  if (domain.empty()) {
    return false;
  } else {
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
