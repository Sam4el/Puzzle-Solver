#include "constraints/noRepeatsConstraint.h"

#include <unordered_set>

NoRepeatsConstraint::NoRepeatsConstraint(std::vector<Variable *> vars) : scope{vars} {
}

bool NoRepeatsConstraint::isSatisfied(const std::unordered_map<int, int> &assignments) const {
  // TODO change int to template argument in the future?
  std::unordered_set<int> uniqueValues;
  uniqueValues.reserve(assignments.size());
  for (const auto &[id, value] : assignments) {
    if (!uniqueValues.insert(value).second) {
      return false;
    }
  }

  return true;
}
