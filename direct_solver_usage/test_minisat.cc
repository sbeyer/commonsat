#include <commonsat/minisat.h>

extern void test_commonsat(commonsat::SolverInterface &solver);

int main()
{
	commonsat::SolverMinisat solver;
	test_commonsat(solver);
	return 0;
}
