#include "solver.h"

namespace
{

} // namespace

// bool Solver::backtrackingSearch()
// {
//     if (csp.getUnassignedVariables().size() == 0)
//     {
//         return true;
//     }
//     else
//     {
//     }
// }

void Solver::assignVariable(Variable &var, int value)
{
    var.assign();
    assignments[var.getId()] = value;
}

void Solver::unassignVariable(Variable &var)
{
    var.unassign();
    assignments.erase(var.getId());
}

// void Solver::constraintPropagation()
// {
// }

// std::unordered_map<int, int> Solver::run()
// {
// }
