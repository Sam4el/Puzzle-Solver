#include <gtest/gtest.h>

#include "variable.h"
#include "variable_test/inc/variable_test_helper.h"

TEST(VariableTest, constructor) {
    Variable var{"Test123", {1, 2, 3, 4, 5}};
    std::set<int> expectedDomain{1, 2, 3, 4, 5};

    ASSERT_EQ(VariableTestHelper::getDomain(var), expectedDomain);
    ASSERT_EQ(var.getName(), "Test123");
}

TEST(VariableTest, isAssigned) {
    Variable var{"Test1", {1, 2, 3, 4, 5}};

    ASSERT_FALSE(var.isAssigned());

    var.assign();
    ASSERT_TRUE(var.isAssigned());

    var.unassign();
    ASSERT_FALSE(var.isAssigned());
}

TEST(VariableTest, reduceAndRestoreDomain) {
    Variable var{"Test1", {1, 2, 3, 4, 5}};

    ASSERT_EQ(VariableTestHelper::getDomain(var).size(), 5);

    var.reduceDomain(4);
    ASSERT_EQ(VariableTestHelper::getDomain(var).size(), 4);

    var.reduceDomain(3);
    ASSERT_EQ(VariableTestHelper::getDomain(var).size(), 3);

    var.restoreLastDomain();
    var.restoreLastDomain();
    ASSERT_EQ(VariableTestHelper::getDomain(var).size(), 5);
}

TEST(VariableTest, reduceDomainValueOutOfDomain) {
    Variable var{"Test1", {1, 2, 3, 4, 5}};

    EXPECT_THROW(var.reduceDomain(10), std::domain_error);
}
