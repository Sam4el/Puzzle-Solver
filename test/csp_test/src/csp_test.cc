#include "csp.h"

#include <gtest/gtest.h>

#include "csp_test/inc/csp_test_helper.h"

class CspTest : public ::testing::Test {
 protected:
  CSP csp;
  Variable var1{10, {1, 2, 3, 4}};
  Variable var2{20, {1, 4}};
  Variable var3{30, {1, 4, 5}};
};

TEST_F(CspTest, addAndGetConstraints) {
  csp.addConstraint(std::make_unique<CspTestHelper::ConstraintStub>());
  csp.addConstraint(std::make_unique<CspTestHelper::ConstraintStub>());

  ASSERT_EQ(csp.getConstraints().size(), 2);
}

TEST_F(CspTest, addAndGetVariables) {
  csp.addVariable(var1);
  csp.addVariable(var2);

  ASSERT_EQ(csp.getVariables().size(), 2);
}

TEST_F(CspTest, getUnassignedVariables) {
  csp.addVariable(var1);
  csp.addVariable(var2);
  csp.addVariable(var3);
  std::unordered_map<int, int> assignments1{};

  std::vector<const Variable*> expected1{&csp.getVariables()[0], &csp.getVariables()[1],
                                         &csp.getVariables()[2]};
  ASSERT_EQ(csp.getUnassignedVariables(assignments1), expected1);

  std::unordered_map<int, int> assignments2{{10, 1}, {30, 5}};
  std::vector<const Variable*> expected2{&csp.getVariables()[1]};
  ASSERT_EQ(csp.getUnassignedVariables(assignments2), expected2);
}
