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

void test_satisfiable(commonsat::SolverInterface &solver);
void test_unsatisfiable(commonsat::SolverInterface &solver);
void test_assignment(commonsat::SolverInterface &solver);

template<typename T>
void run_tests()
{
	struct test_item {
		const char *does_something;
		std::function<void(commonsat::SolverInterface &)> test_something;
	};

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
