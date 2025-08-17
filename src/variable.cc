#include <iostream>
#include <stdexcept>

#include "variable.h"

Variable::Variable(std::string name, std::set<int> domain)
    : name{name},
    domain{domain},
    domainBackup{domain} {}

void Variable::assign(int value) {
    // TODO Should it be caught here or when called?

    if (domain.contains(value)) {
        assignedValue = value;
    } else {
        throw std::domain_error("Value " + std::to_string(value) + " is not in the domain");
    }
}

void Variable::unassign() {
    assignedValue = std::nullopt;
}

void Variable::reduceDomain(int value) {
    // TODO Should it be caught here or when called?

    if (domain.contains(value)) {
        domain.erase(value);
    } else {
        throw std::domain_error("Value " + std::to_string(value) + " is not in the domain");
    }
}

void Variable::restoreDomain() {
    domain = domainBackup;
}

bool Variable::isAssigned() const {
    return assignedValue.has_value();
}
