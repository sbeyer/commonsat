#include "tests.h"

#include <bandit/assertion_frameworks/snowhouse/snowhouse.h>
#include <commonsat/commonsat.h>

using namespace snowhouse;

void test_satisfiable(commonsat::SolverInterface &solver)
{
	solver.add_clause({1, 2});
	solver.add_clause({1, -2, 3});
	solver.add_clause({-1, 2});
	solver.add_clause({-1, -2});
	bool isSatisfiable = solver.solve();
	AssertThat(isSatisfiable, IsTrue());
}

void test_unsatisfiable(commonsat::SolverInterface &solver)
{
	solver.add_clause({1, 2});
	solver.add_clause({1, -2, 3});
	solver.add_clause({-1, 2});
	solver.add_clause({-1, -2});
	solver.add_clause({-3});
	bool isSatisfiable = solver.solve();
	AssertThat(isSatisfiable, IsFalse());
}

void test_assignment(commonsat::SolverInterface &solver)
{
	for (int i = 0; i < 7; ++i) {
		commonsat::clause_t clause = {1, 2, 3};
		for (int j = 0; j < 3; ++j) {
			if ((i >> j) & 1) {
				clause[j] = -clause[j];
			}
		}
		solver.add_clause(clause);
	}

	bool isSatisfiable = solver.solve();
	AssertThat(isSatisfiable, IsTrue());
	AssertThat(solver.is_assigned(1), IsTrue());
	AssertThat(solver.is_assigned(2), IsTrue());
	AssertThat(solver.is_assigned(3), IsTrue());
	AssertThat(solver.is_true(1), IsTrue());
	AssertThat(solver.is_true(2), IsTrue());
	AssertThat(solver.is_true(3), IsTrue());
}
