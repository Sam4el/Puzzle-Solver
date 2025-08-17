#include <gtest/gtest.h>

#include "csp.h"
#include "csp_test/inc/csp_test_helper.h"

TEST(cspTest, addVariable) {
    CSP csp;
    ASSERT_EQ(CspTestHelper::getVariablesSize(csp), 0);

    csp.addVariable({"Test1", {1, 2, 3, 4}});
    ASSERT_EQ(CspTestHelper::getVariablesSize(csp), 1);
}

TEST(cspTest, addConstraint) {
    CSP csp;
    ASSERT_EQ(CspTestHelper::getConstraintsSize(csp), 0);

    csp.addConstraint(std::make_unique<CspTestHelper::ConstraintStub>());
    ASSERT_EQ(CspTestHelper::getConstraintsSize(csp), 1);
}

TEST(cspTest, assignVariable) {
    CSP csp;
    csp.addVariable({"Test1", {1, 2, 3, 4}});
    ASSERT_EQ(csp.getUnassignedVariables().size(), 1);

    csp.assignVariable(*csp.getUnassignedVariables()[0], 2);
    ASSERT_EQ(csp.getUnassignedVariables().size(), 0);
}

TEST(cspTest, getUnassignedVariables) {
    CSP csp;
    ASSERT_EQ(csp.getUnassignedVariables().size(), 0);

    csp.addVariable({"Test1", {1, 2, 3, 4}});
    ASSERT_EQ(csp.getUnassignedVariables().size(), 1);

    csp.addVariable({"Test2", {1, 2, 3, 4}});
    csp.addVariable({"Test3", {1, 2, 3, 4}});
    ASSERT_EQ(csp.getUnassignedVariables().size(), 3);
}
