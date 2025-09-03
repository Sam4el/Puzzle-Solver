#include "solver.h"

namespace
{

} // namespace

bool Solver::backtrackingSearch()
{
    if (csp.getUnassignedVariables().size() == 0)
    {
        return true;
    }
    else
    {
    }
}

bool Solver::assignVariable(Variable &var, int value)
{
    var.assign();
    assignments[var.getName()] = value;
}

void Solver::unassignVariable(Variable &var)
{
    var.unassign();
    assignments.erase(var.getName());
}

void Solver::constraintPropagation()
{
}

std::unordered_map<std::string, int> Solver::run()
{
}
