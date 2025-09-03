#include "csp.h"

std::vector<Variable *> CSP::getUnassignedVariables()
{
    std::vector<Variable *> unassignedVariables;

    for (auto &variable : variables)
    {
        if (!variable.isAssigned())
        {
            unassignedVariables.push_back(&variable);
        }
    }

    return unassignedVariables;
}
