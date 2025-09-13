#include "csp.h"

const std::vector<const Variable *> CSP::getUnassignedVariables(
    const std::unordered_map<int, int> &assignments) const {
  std::vector<const Variable *> unassignedVariables;
  for (auto &var : variables) {
    if (assignments.find(var.getId()) == assignments.end()) {
      unassignedVariables.push_back(&var);
    }
  }

  return unassignedVariables;
}
