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

  inline void setVariableHeuristic(std::unique_ptr<IVariableHeuristic> &&heuristic) {
    variableHeuristic = std::move(heuristic);
  }
  inline void setValueHeuristic(std::unique_ptr<IValueHeuristic> &&heuristic) {
    valueHeuristic = std::move(heuristic);
  }
  inline void setPropagator(std::unique_ptr<IPropagator> &&propagator) {
    propagator = std::move(propagator);
  }

 private:
  bool checkConstraints(std::unordered_map<int, int> &assignments) const;
  const Variable *chooseNextVariable(std::unordered_map<int, int> &assignments) const;
  const std::set<int> orderValues(const Variable &var,
                                  std::unordered_map<int, int> &assignments) const;
  void propagate() const;

  CSP &csp;
  std::unique_ptr<IVariableHeuristic> variableHeuristic;
  std::unique_ptr<IValueHeuristic> valueHeuristic;
  std::unique_ptr<IPropagator> propagator;
};
