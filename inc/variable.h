#include <set>
#include <string>
#include <optional>

#pragma once

class VariableTestHelper;

class Variable {
friend class VariableTestHelper;

public:
Variable() = delete;
Variable(const std::string name, std::set<int> domain);

void assign(int value);
void unassign();
void reduceDomain(int value);
void restoreDomain();

bool isAssigned() const;

private:
const std::string name;
std::set<int> domain;
const std::set<int> domainBackup;
std::optional<int> assignedValue;
};
