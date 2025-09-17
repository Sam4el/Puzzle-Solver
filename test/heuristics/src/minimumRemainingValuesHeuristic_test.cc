#include "heuristics/minimumRemainingValuesHeuristic.h"

#include <gtest/gtest.h>

#include "solver.h"

class MRVTest : public ::testing::Test {
 protected:
  CSP csp;
  Solver solver{csp};

  Variable var1{10, {1, 2, 3, 4}};
  Variable var2{20, {1, 2}};
  Variable var3{30, {1, 2, 3, 4, 5, 6}};
  Variable var4{40, {1, 2, 3}};

  std::unique_ptr<IVariableHeuristic> mrv;

  void SetUp() { mrv = std::make_unique<MRV>(); }
};

TEST_F(MRVTest, chooseVariable) {
  csp.addVariable(var1);
  csp.addVariable(var2);
  csp.addVariable(var3);
  csp.addVariable(var4);

  std::unordered_map<int, int> assignments1{};
  const Variable* expected1 = csp.getUnassignedVariables(assignments1)[1];
  ASSERT_EQ(mrv->chooseVariable(csp, assignments1), expected1);

  std::unordered_map<int, int> assignments2{{20, 2}};
  const Variable* expected2 = csp.getUnassignedVariables(assignments2)[3];
  ASSERT_EQ(mrv->chooseVariable(csp, assignments2), expected2);
}

TEST_F(MRVTest, chooseVariableNoMoreUnassignedVariables) {
  csp.addVariable(var1);
  csp.addVariable(var2);
  std::unordered_map<int, int> assignments{{10, 1}, {20, 2}};
  ASSERT_THROW(mrv->chooseVariable(csp, assignments), std::logic_error);
}
