#include <commonsat/commonsat.h>
#include <bandit/bandit.h>

#ifndef COMMONSAT_TESTS
#define COMMONSAT_TESTS

#define RUN_TESTS_FOR_SOLVER(name) \
	go_bandit([]() { \
		bandit::describe("Solver" #name, []() { \
			run_tests<commonsat::Solver##name>(); \
		}); \
	}); \
	\
	int main(int argc, char *argv[]) \
	{ \
		return bandit::run(argc, argv); \
	}

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

struct test_item {
	const char *does_something;
	std::function<void(commonsat::SolverInterface &)> test_something;
};

template<typename T>
void run_tests()
{
	test_item tests[] = {
		{ "solves a satisfiable formula", test_satisfiable },
		{ "solves an unsatisfiable formula", test_unsatisfiable },
		{ "obtains a satisfiable assignment", test_assignment },
	};
	for (const auto &test : tests) {
		bandit::it(test.does_something, [&]() {
			T solver;
			test.test_something(solver);
		});
	}
}

#endif
