#include <optional>
#include <set>
#include <stack>
#include <string>

#pragma once

class VariableTestHelper;

class Variable {
  friend class VariableTestHelper;

 public:
  Variable() = delete;
  Variable(const int id, const std::set<int>& domain);

  void reduceDomain(int value);
  void restoreLastDomain();

  inline const std::set<int>& getDomain() { return domain; }
  inline const int getId() const { return id; }

 private:
  const int id;
  std::set<int> domain;
  std::stack<int> domainDelta;
};
