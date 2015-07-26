#include <iostream>
#include <vector>
#include <minisat/core/Solver.h>

void addClause(Minisat::Solver &solver, const std::vector<int> &clause)
{
	Minisat::vec<Minisat::Lit> tmp;
	for (const auto &lit : clause) {
		if (lit > 0) {
			tmp.push(Minisat::mkLit(lit-1, false));
		} else {
			tmp.push(Minisat::mkLit(-1-lit, true));
		}
	}
	solver.addClause_(tmp);
}

void check(bool satisfiable)
{
	Minisat::Solver solver;
	solver.newVar();
	solver.newVar();
	solver.newVar();
	addClause(solver, {1, 2});
	addClause(solver, {1, -2, 3});
	addClause(solver, {-1, 2});
	addClause(solver, {-1, -2});
	if (!satisfiable) {
		addClause(solver, {-3});
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
