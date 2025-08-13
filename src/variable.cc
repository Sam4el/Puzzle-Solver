#include "variable.h"

Variable::Variable(std::string name, std::set<int> domain)
    : name{name},
    domain{domain},
    domainBackup{domain} {}

void Variable::assign(int value) {
    assignedValue = value;
}

void Variable::unassign() {
    assignedValue = std::nullopt;
}

void Variable::reduceDomain(int value) {
    domain.erase(value);
}

void Variable::restoreDomain() {
    domain = domainBackup;
}