#include "solver.h"

#include <algorithm>

bool Solver::checkConstraints(std::unordered_map<int, int> &assignments) const {
  const auto &constraints = csp.getConstraints();
  return std::all_of(
      constraints.begin(), constraints.end(),
      [&assignments](const auto &constraint) { return constraint->isSatisfied(assignments); });
}

std::vector<Variable *> Solver::getUnassignedVariables(
    std::unordered_map<int, int> &assignments) const {
  std::vector<Variable *> unassignedVariables;
  for (auto &var : csp.getVariables()) {
    if (assignments.find(var.getId()) == assignments.end()) {
      unassignedVariables.push_back(&var);
    }
  }

  return unassignedVariables;
}

bool Solver::backtrackingSearch(std::unordered_map<int, int> &assignments) {
  // All assigned, solution found
  if (getUnassignedVariables(assignments).empty()) {
    return true;
  }

  // TODO use heuristics to choose variable
  // TODO use Constraint propagation to reduce domains

  // Assign first unassigned variable
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
    // Cleanup after finishing domain or failed backtrackingSearch
    assignments.erase(activeVariable->getId());
  }

  return false;
}

// void Solver::constraintPropagation()
// {
// }
