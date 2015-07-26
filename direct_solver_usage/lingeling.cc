#include <iostream>
#include <vector>

extern "C" {
#include <lglib.h>
}

void addClause(LGL *lgl, const std::vector<int> &clause)
{
	for (const auto &lit : clause) {
		lgladd(lgl, lit);
	}
	lgladd(lgl, 0);
}

void check(bool satisfiable)
{
	LGL *lgl = lglinit();
	addClause(lgl, {1, 2});
	addClause(lgl, {1, -2, 3});
	addClause(lgl, {-1, 2});
	addClause(lgl, {-1, -2});
	if (!satisfiable) {
		addClause(lgl, {-3});
	}
	int sat = lglsat(lgl);
	if (sat == 10) {
		std::cout << "Satisfiable" << std::endl;
	} else {
		if (sat == 20) {
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
