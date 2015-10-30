#include <iostream>
#include <commonsat/commonsat.h>

using namespace commonsat;

static void check(SolverInterface &solver, bool satisfiable)
{
	solver.add_clause({1, 2});
	solver.add_clause({1, -2, 3});
	solver.add_clause({-1, 2});
	solver.add_clause({-1, -2});
	if (!satisfiable) {
		solver.add_clause({-3});
	}
	bool sat = solver.solve();
	std::cout << (sat ? "Satisfiable" : "Nonsatisfiable") << std::endl;
}

void test_commonsat(SolverInterface &solver)
{
	check(solver, true);
	check(solver, false);
}
