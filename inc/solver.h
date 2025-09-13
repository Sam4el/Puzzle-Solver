#include "csp.h"
#include "propagator.h"
#include "valueHeuristic.h"
#include "variableHeuristic.h"

#pragma once

class Solver {
 public:
  Solver() = delete;
  Solver(CSP &csp) : csp{csp} {}

  bool backtrackingSearch(std::unordered_map<int, int> &assignments);

  inline void setVariableHeuristic(std::unique_ptr<VariableHeuristic> &&heuristic) {
    variableHeuristic = std::move(heuristic);
  }
  inline void setValueHeuristic(std::unique_ptr<ValueHeuristic> &&heuristic) {
    valueHeuristic = std::move(heuristic);
  }
  inline void setPropagator(std::unique_ptr<Propagator> &&propagator) {
    propagator = std::move(propagator);
  }

 private:
  bool checkConstraints(std::unordered_map<int, int> &assignments) const;
  inline const std::vector<const Variable *> getUnassignedVariables(
      std::unordered_map<int, int> &assignments) const {
    return csp.getUnassignedVariables(assignments);
  }

  // TODO arguments for propagate
  inline void propagate() const { propagator->propagate(); }
  inline const std::set<int> orderValues(const CSP &csp, const Variable &var,
                                         std::unordered_map<int, int> &assignments) const {
    return valueHeuristic->orderValues(csp, var, assignments);
  }
  inline const Variable *chooseVariable(const CSP &csp,
                                        std::unordered_map<int, int> &assignments) const {
    return variableHeuristic->chooseVariable(csp, assignments);
  }

  CSP &csp;
  std::unique_ptr<VariableHeuristic> variableHeuristic;
  std::unique_ptr<ValueHeuristic> valueHeuristic;
  std::unique_ptr<Propagator> propagator;
};
