#include <commonsat/cryptominisat.h>

extern void test_commonsat(commonsat::SolverInterface &solver);

int main()
{
	commonsat::SolverCryptominisat solver;
	test_commonsat(solver);
	return 0;
}
