#include "csp.h"

#include <gtest/gtest.h>

#include "csp_test/inc/csp_test_helper.h"

class CspTest : public ::testing::Test {
 protected:
  CSP csp;
  Variable var1{10, {1, 2, 3, 4}};
  Variable var2{20, {1, 4}};
};

TEST_F(CspTest, addAndGetConstraints) {
  csp.addConstraint(std::make_unique<CspTestHelper::ConstraintStub>());
  csp.addConstraint(std::make_unique<CspTestHelper::ConstraintStub>());

  ASSERT_EQ(csp.getConstraints().size(), 2);
}

TEST_F(CspTest, addAndGetVariables) {
  csp.addVariable({10, {1, 2, 3, 4}});
  csp.addVariable({20, {1, 4}});

  ASSERT_EQ(csp.getVariables().size(), 2);
}
