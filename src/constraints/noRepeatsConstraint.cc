#include "constraints/noRepeatsConstraint.h"

#include <unordered_set>

NoRepeatsConstraint::NoRepeatsConstraint(const std::vector<const Variable *> &vars)
    : scope{vars} {
}

bool NoRepeatsConstraint::isSatisfied(const std::unordered_map<int, int> &assignments) const {
  std::unordered_set<int> scopeIds;
  scopeIds.reserve(scope.size());
  for (const auto *elem : scope) {
    scopeIds.insert(elem->getId());
  }

  std::unordered_set<int> uniqueValues;
  uniqueValues.reserve(assignments.size());
  for (const auto &[id, value] : assignments) {
    if (scopeIds.contains(id) && !uniqueValues.insert(value).second) {
      return false;
    }
  }

  return true;
}
