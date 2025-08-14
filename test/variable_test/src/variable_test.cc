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

TEST(VariableTest, reduceAndRestoreDomain) {
    Variable var{"Test1", {1, 2, 3, 4, 5}};

    ASSERT_EQ(VariableTestHelper::getDomain(var).size(), 5);

    var.reduceDomain(4);
    ASSERT_EQ(VariableTestHelper::getDomain(var).size(), 4);

    var.restoreDomain();
    ASSERT_EQ(VariableTestHelper::getDomain(var).size(), 5);
}

