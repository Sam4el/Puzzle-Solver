#include <set>
#include <string>
#include <optional>

#pragma once

class Variable {
public:
Variable() = default;
Variable(std::string name);
void assign(int value);
void unassign();

private:
std::string name;
std::set<int> domain;
std::optional<int> assignedValue;
};