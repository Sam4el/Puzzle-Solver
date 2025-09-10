#include "solver.h"

#include <gtest/gtest.h>

#include "constraints/noRepeatsConstraint.h"

class SolverTest : public ::testing::Test {
 protected:
  CSP csp;
  Solver solver{csp};
  std::unordered_map<int, int> assignments;
};

TEST_F(SolverTest, backtrackingSearchWithSolution) {
  Variable var1{1, {3, 4}};
  Variable var2{2, {3}};
  Variable var3{3, {3, 4, 5}};

  csp.addVariable(var1);
  csp.addVariable(var2);
  csp.addVariable(var3);

  auto& variables = csp.getVariables();
  std::vector<Variable*> constraintScope{&variables[0], &variables[1], &variables[2]};

  csp.addConstraint(std::make_unique<NoRepeatsConstraint>(constraintScope));

  std::unordered_map<int, int> result;
  solver.backtrackingSearch(result);

  std::unordered_map<int, int> expectedResult{{1, 4}, {2, 3}, {3, 5}};

  ASSERT_EQ(result, expectedResult);
}

TEST_F(SolverTest, backtrackingSearchNoSolution) {
  Variable var1{1, {3, 4}};
  Variable var2{2, {3}};
  Variable var3{3, {3, 4}};

  csp.addVariable(var1);
  csp.addVariable(var2);
  csp.addVariable(var3);

  auto& variables = csp.getVariables();
  std::vector<Variable*> constraintScope{&variables[0], &variables[1], &variables[2]};

  csp.addConstraint(std::make_unique<NoRepeatsConstraint>(constraintScope));

  std::unordered_map<int, int> result;
  solver.backtrackingSearch(result);

  std::unordered_map<int, int> expectedResult{};

  ASSERT_EQ(result, expectedResult);
}

TEST_F(SolverTest, backtrackingSearchSudoku4x4) {
  // Create board of Variables
  int boardSize = 4;
  std::vector<std::vector<Variable>> sudokuBoard(boardSize, std::vector<Variable>{});
  std::set<int> defaultDomain{1, 2, 3, 4};
  int id = 0;
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      sudokuBoard[i].emplace_back(id++, defaultDomain);
    }
  }

  // Add Variables to CSP
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      csp.addVariable(sudokuBoard[i][j]);
    }
  }

  // Assign some Variables
  std::unordered_map<int, int> result;
  result[0] = 1;
  result[3] = 4;
  result[5] = 2;
  result[10] = 4;
  result[15] = 3;

  auto& variables = csp.getVariables();

  // Scope of blocks 2x2
  std::vector<Variable*> scope1{&variables[0], &variables[1], &variables[4], &variables[5]};
  std::vector<Variable*> scope2{&variables[2], &variables[3], &variables[6], &variables[7]};
  std::vector<Variable*> scope3{&variables[8], &variables[9], &variables[12], &variables[13]};
  std::vector<Variable*> scope4{&variables[10], &variables[11], &variables[14],
                                &variables[15]};

  csp.addConstraint(std::make_unique<NoRepeatsConstraint>(scope1));
  csp.addConstraint(std::make_unique<NoRepeatsConstraint>(scope2));
  csp.addConstraint(std::make_unique<NoRepeatsConstraint>(scope3));
  csp.addConstraint(std::make_unique<NoRepeatsConstraint>(scope4));

  // Add scope of rows and cols
  for (int i = 0; i < boardSize; i++) {
    std::vector<Variable*> rowScope;
    for (int j = 0; j < boardSize; j++) {
      rowScope.push_back(&sudokuBoard[i][j]);
    }
    csp.addConstraint(std::make_unique<NoRepeatsConstraint>(rowScope));
  }

  for (int j = 0; j < boardSize; j++) {
    std::vector<Variable*> colScope;
    for (int i = 0; i < boardSize; i++) {
      colScope.push_back(&sudokuBoard[i][j]);
    }
    csp.addConstraint(std::make_unique<NoRepeatsConstraint>(colScope));
  }

  solver.backtrackingSearch(result);

  // clang-format off
  std::unordered_map<int, int> expectedResult{
    { 0, 1}, { 1, 3}, { 2, 2}, { 3, 4},
    { 4, 4}, { 5, 2}, { 6, 3}, { 7, 1},
    { 8, 3}, { 9, 1}, {10, 4}, {11, 2},
    {12, 2}, {13, 4}, {14, 1}, {15, 3}};
  // clang-format on

  ASSERT_EQ(result, expectedResult);
}
