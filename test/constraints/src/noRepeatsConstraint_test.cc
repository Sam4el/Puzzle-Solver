#include "constraints/noRepeatsConstraint.h"

#include "gtest/gtest.h"

class NoRepeatsConstraintTest : public ::testing::Test {
 protected:
  Variable var1{10, {1, 2, 3, 4}};
  Variable var2{20, {2, 3, 4, 5}};
  Variable var3{30, {3, 4, 5, 6}};
  Variable var4{40, {4, 5, 6, 7}};
  std::vector<Variable> variables{var1, var2, var3, var4};
  std::unique_ptr<Constraint> noRepeatsConstraint;

  void SetUp() override {
    noRepeatsConstraint = std::make_unique<NoRepeatsConstraint>(
        std::vector<Variable *>{&variables[0], &variables[1], &variables[2], &variables[3]});
  }
};

TEST_F(NoRepeatsConstraintTest, constructorAndGetScope) {
  ASSERT_EQ(noRepeatsConstraint->getScope()[0]->getId(), var1.getId());
  ASSERT_EQ(noRepeatsConstraint->getScope()[1]->getId(), var2.getId());
  ASSERT_EQ(noRepeatsConstraint->getScope()[2]->getId(), var3.getId());
  ASSERT_EQ(noRepeatsConstraint->getScope()[3]->getId(), var4.getId());
}

TEST_F(NoRepeatsConstraintTest, isSatisfied) {
  const std::unordered_map<int, int> assignments1{
      {var1.getId(), 1}, {var2.getId(), 2}, {var3.getId(), 3}, {var4.getId(), 4}};
  ASSERT_TRUE(noRepeatsConstraint->isSatisfied(assignments1));

  const std::unordered_map<int, int> assignments2{
      {var1.getId(), 2}, {var2.getId(), 2}, {var3.getId(), 3}, {var4.getId(), 4}};
  ASSERT_FALSE(noRepeatsConstraint->isSatisfied(assignments2));
}
