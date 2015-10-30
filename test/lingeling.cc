#include <commonsat/lingeling.h>

extern void test_commonsat(commonsat::SolverInterface &solver);

int main()
{
	commonsat::SolverLingeling solver;
	test_commonsat(solver);
	return 0;
}
