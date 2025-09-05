#include "variable.h"

#include <iostream>
#include <stdexcept>

Variable::Variable(const int id, const std::set<int> &domain)
    : id{id}, domain{std::move(domain)} {
}

void Variable::reduceDomain(int value) {
  if (domain.contains(value)) {
    domainDelta.push(value);
    domain.erase(value);
  } else {
    throw std::domain_error("Value " + std::to_string(value) + " is not in the domain");
  }
}

void Variable::restoreLastDomain() {
  if (!domainDelta.empty()) {
    domain.insert(domainDelta.top());
    domainDelta.pop();
  }
}
