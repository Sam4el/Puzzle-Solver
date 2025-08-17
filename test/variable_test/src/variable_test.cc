#include <gtest/gtest.h>

#include "variable.h"
#include "variable_test/inc/variable_test_helper.h"

TEST(VariableTest, constructor) {
    Variable var{"Test123", {1, 2, 3, 4, 5}};
    std::set<int> expectedDomain{1, 2, 3, 4, 5};

    ASSERT_EQ(VariableTestHelper::getDomain(var), expectedDomain);
    ASSERT_EQ(VariableTestHelper::getName(var), "Test123");
}

TEST(VariableTest, assignAndUnassign) {
    Variable var{"Test1", {1, 2, 3, 4, 5}};
    
    var.assign(3);
    ASSERT_EQ(VariableTestHelper::getAssignedValue(var), 3);

    var.assign(1);
    ASSERT_EQ(VariableTestHelper::getAssignedValue(var), 1);

    var.unassign();
    ASSERT_EQ(VariableTestHelper::getAssignedValue(var), std::nullopt);
}

TEST(VariableTest, isAssigned) {
    Variable var{"Test1", {1, 2, 3, 4, 5}};

    ASSERT_FALSE(var.isAssigned());

    var.assign(1);
    ASSERT_TRUE(var.isAssigned());

    var.unassign();
    ASSERT_FALSE(var.isAssigned());
}

TEST(VariableTest, reduceAndRestoreDomain) {
    Variable var{"Test1", {1, 2, 3, 4, 5}};

    ASSERT_EQ(VariableTestHelper::getDomain(var).size(), 5);

    var.reduceDomain(4);
    ASSERT_EQ(VariableTestHelper::getDomain(var).size(), 4);

    var.restoreDomain();
    ASSERT_EQ(VariableTestHelper::getDomain(var).size(), 5);
}

TEST(VariableTest, assignValueValueOutOfDomain) {
    Variable var{"Test1", {1, 2, 3, 4, 5}};

    EXPECT_THROW(var.assign(10), std::domain_error);
}

TEST(VariableTest, reduceDomainValueOutOfDomain) {
    Variable var{"Test1", {1, 2, 3, 4, 5}};

    EXPECT_THROW(var.reduceDomain(10), std::domain_error);
}
