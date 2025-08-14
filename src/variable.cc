#include <iostream>
#include <stdexcept>

#include "variable.h"

Variable::Variable(std::string name, std::set<int> domain)
    : name{name},
    domain{domain},
    domainBackup{domain} {}

void Variable::assign(int value) {
    try {
        if (domain.contains(value)) {
            assignedValue = value;
        } else {
            throw std::domain_error("Value " + std::to_string(value) + " is not in the domain");
        }
    }
    catch (std::domain_error& e) {
        std::cerr << "assign() exception " << e.what() << "\n";
    }
}

void Variable::unassign() {
    assignedValue = std::nullopt;
}

void Variable::reduceDomain(int value) {
    try {
        if (domain.contains(value)) {
            domain.erase(value);
        } else {
            throw std::domain_error("Value " + std::to_string(value) + " is not in the domain");
        }
    }
    catch (std::domain_error& e) {
        std::cerr << "reduceDomain() exception " << e.what() << "\n";
    }
}

void Variable::restoreDomain() {
    domain = domainBackup;
}
