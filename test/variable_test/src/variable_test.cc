#include "variable.h"

#include <gtest/gtest.h>

TEST(VariableTest, constructor) {
  Variable var{7, {1, 2, 3, 4, 5}};
  std::set<int> expectedDomain{1, 2, 3, 4, 5};

  ASSERT_EQ(var.getDomain(), expectedDomain);
  ASSERT_EQ(var.getId(), 7);
}

TEST(VariableTest, reduceAndRestoreDomain) {
  Variable var{7, {1, 2, 3, 4, 5}};

  ASSERT_EQ(var.getDomain().size(), 5);

  var.reduceDomain(4);
  ASSERT_EQ(var.getDomain().size(), 4);

  var.reduceDomain(3);
  ASSERT_EQ(var.getDomain().size(), 3);

  var.restoreLastDomain();
  var.restoreLastDomain();
  ASSERT_EQ(var.getDomain().size(), 5);
}

TEST(VariableTest, reduceDomainValueOutOfDomain) {
  Variable var{7, {1, 2, 3, 4, 5}};

  EXPECT_THROW(var.reduceDomain(10), std::domain_error);
}
