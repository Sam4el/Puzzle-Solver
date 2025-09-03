#include <set>
#include <stack>
#include <string>
#include <optional>

#pragma once

class VariableTestHelper;

class Variable
{
    friend class VariableTestHelper;

public:
    Variable() = delete;
    Variable(const std::string name, std::set<int> domain);

    void reduceDomain(int value);
    void restoreLastDomain();
    inline void assign() { assigned = true; }
    inline void unassign() { assigned = false; }

    inline const std::string getName() const { return name; }
    inline bool isAssigned() const { return assigned; }

private:
    const std::string name;
    std::set<int> domain;
    std::stack<int> domainDelta;
    bool assigned;
};
