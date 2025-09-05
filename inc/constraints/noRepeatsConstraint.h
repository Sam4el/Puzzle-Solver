#include "constraint.h"

class NoRepeatsConstraint : public Constraint {
 public:
  NoRepeatsConstraint() = delete;
  NoRepeatsConstraint(std::vector<Variable *> vars);

  bool isSatisfied(const std::unordered_map<int, int> &assignments) const override;
  inline const std::vector<Variable *> &getScope() const override { return scope; }

 private:
  std::vector<Variable *> scope;
};
