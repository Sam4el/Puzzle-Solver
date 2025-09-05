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
    Variable(const int id, std::set<int> domain);

    void reduceDomain(int value);
    void restoreLastDomain();
    inline void assign() { assigned = true; }
    inline void unassign() { assigned = false; }

    inline const int getId() const { return id; }
    inline bool isAssigned() const { return assigned; }

private:
    const int id;
    std::set<int> domain;
    std::stack<int> domainDelta;
    bool assigned;
};
