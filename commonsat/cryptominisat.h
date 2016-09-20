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

#include <stdexcept>
#include <commonsat/commonsat.h>
#include <cryptominisat5/cryptominisat.h>

namespace commonsat {

//! The solver interface for CryptoMiniSat
class SolverCryptominisat : public SolverInterface {
protected:
	CMSat::SATSolver m_solver; //!< An instance of the CryptoMiniSat solver
	int m_variable_count; //!< The number of variables in the model

	//! Guarantee that we have \p max_id many variables
	void make_variables(int max_id)
	{
		for (; m_variable_count < max_id; ++m_variable_count) {
			m_solver.new_var();
		}
#ifndef NDEBUG
		if (m_variable_count != int(m_solver.nVars())) {
			throw std::logic_error("number of variables of front-end and back-end deviate");
		}
#endif
	}

public:
	SolverCryptominisat()
	  : m_solver()
	  , m_variable_count(0)
	{
	}

	void add_clause(const clause_t &clause) override
	{
		std::vector<CMSat::Lit> tmp;
		for (const auto &lit : clause) {
#ifndef NDEBUG
			if (lit == 0) {
				throw std::logic_error("0 must not be an id for a variable");
			}
#endif
			auto var_id = abs(lit);
			make_variables(var_id);
			tmp.emplace_back(CMSat::Lit(var_id - 1, var_id != lit));
		}
		m_solver.add_clause(tmp);
	}

	bool solve() override
	{
		return m_solver.solve() == CMSat::l_True; // == l_False is nonsatisfiable
	}

	Assignment get_assignment(int var) const override
	{
#ifndef NDEBUG
		if (var <= 0 || var > m_variable_count) {
			throw std::out_of_range("indexed non-existent variable");
		}
#endif

		const CMSat::lbool assignment = m_solver.get_model()[var - 1];

		if (assignment == CMSat::lbool(uint8_t(0))) {
			return Assignment::True;
		}
		if (assignment == CMSat::lbool(uint8_t(1))) {
			return Assignment::False;
		}
		return Assignment::Undefined;
	}
};

}

#endif // COMMONSAT_CRYPTOMINISAT_H
