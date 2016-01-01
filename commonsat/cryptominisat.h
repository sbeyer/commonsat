/*! \file
 * \brief Definition of the CryptoMiniSat interface for CommonSAT.
 * \copyright Copyright 2015 Stephan Beyer.
 * \par
 * This file is part of CommonSAT.
 * \par
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * \par
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * \par
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef COMMONSAT_CRYPTOMINISAT_H
#define COMMONSAT_CRYPTOMINISAT_H

#include <cassert>
#include <commonsat/commonsat.h>
#include <cryptominisat4/cryptominisat.h>

namespace commonsat {

//! The solver interface for CryptoMiniSat
class SolverCryptominisat : public SolverInterface {
protected:
	CMSat::SATSolver m_solver;
	int m_variable_count;

	//! Guarantee that we have \v max_id many variables
	void make_variables(int max_id)
	{
		for (; m_variable_count < max_id; ++m_variable_count) {
			m_solver.new_var();
		}
	}

public:
	SolverCryptominisat()
	  : m_solver()
	  , m_variable_count(0)
	{
	}

	void add_clause(const clause_t &clause)
	{
		std::vector<CMSat::Lit> tmp;
		for (const auto &lit : clause) {
			assert(lit != 0);
			auto var_id = abs(lit);
			make_variables(var_id);
			tmp.emplace_back(CMSat::Lit(var_id - 1, var_id != lit));
		}
		m_solver.add_clause(tmp);
	}

	bool solve()
	{
		return m_solver.solve() == CMSat::l_True; // == l_False is nonsatisfiable
	}
};

}

#endif // COMMONSAT_CRYPTOMINISAT_H
