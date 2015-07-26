#include <iostream>
#include <vector>
#include <cryptominisat4/cryptominisat.h>

void check(bool satisfiable)
{
	CMSat::SATSolver solver;
	// solver.set_num_threads(4);
	solver.new_vars(2);
	solver.add_clause({CMSat::Lit(0, false), CMSat::Lit(1, false)});
	solver.add_clause({CMSat::Lit(0, true), CMSat::Lit(1, false)});
	solver.add_clause({CMSat::Lit(0, true), CMSat::Lit(1, true)});
	solver.new_var();
	solver.add_clause({CMSat::Lit(0, false), CMSat::Lit(1, true), CMSat::Lit(2, false)});
	if (!satisfiable) {
		solver.add_clause({CMSat::Lit(2, true)});
	}
	CMSat::lbool sat = solver.solve();
	if (sat == CMSat::l_True) {
		std::cout << "Satisfiable" << std::endl;
	} else {
		if (sat == CMSat::l_False) {
			std::cout << "Nonsatisfiable" << std::endl;
		} else {
			std::cout << "Undefined" << std::endl;
		}
	}
}

int main()
{
	check(true);
	check(false);
	return 0;
}
