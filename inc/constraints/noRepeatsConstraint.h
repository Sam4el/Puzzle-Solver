#include "constraint.h"

class NoRepeatsConstraint : public Constraint {
 public:
  NoRepeatsConstraint() = delete;
  NoRepeatsConstraint(const std::vector<const Variable *> &vars);

  bool isSatisfied(const std::unordered_map<int, int> &assignments) const override;
  inline const std::vector<const Variable *> &getScope() const override { return scope; }

 private:
  std::vector<const Variable *> scope;
};
