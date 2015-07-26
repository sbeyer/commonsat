#include <iostream>
#include <commonsat/cryptominisat.h>

void check(bool satisfiable)
{
	commonsat::SolverCryptominisat solver;
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

int main()
{
	check(true);
	check(false);
	return 0;
}
