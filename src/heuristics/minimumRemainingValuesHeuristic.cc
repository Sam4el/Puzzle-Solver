#include "heuristics/minimumRemainingValuesHeuristic.h"

#include <exception>

const Variable* MRV::chooseVariable(const CSP& csp,
                                    const std::unordered_map<int, int>& assignments) const {
  const auto unassignedVariables = csp.getUnassignedVariables(assignments);
  if (unassignedVariables.empty()) {
    throw std::logic_error("No more unassigned variables!");
  }

  const Variable* result = unassignedVariables.front();
  for (const auto& var : csp.getUnassignedVariables(assignments)) {
    if (var->getDomain().size() < result->getDomain().size()) {
      result = var;
    }
  }

  return result;
}
