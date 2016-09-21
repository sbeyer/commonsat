/*! \file
 * \brief Definition of the Lingeling interface for CommonSAT.
 * \copyright Copyright 2015–2016 Stephan Beyer.
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

#ifndef COMMONSAT_LINGELING_H
#define COMMONSAT_LINGELING_H

#include <commonsat/commonsat.h>
extern "C" {
#include <lglib.h>
}

namespace commonsat {

//! The solver interface for Lingeling
class SolverLingeling : public SolverInterface {
protected:
	LGL *m_solver; //!< A pointer to an instance of the Lingeling solver

public:
	SolverLingeling()
	  : m_solver(lglinit())
	{
	}

	~SolverLingeling()
	{
		free(m_solver);
	}

	void add_clause(const clause_t &clause) override
	{
		for (const auto &lit : clause) {
			lgladd(m_solver, lit);
		}
		lgladd(m_solver, 0);
	}

	bool solve() override
	{
		return lglsat(m_solver) == 10; // == 20 is nonsatisfiable
	}

	Assignment get_assignment(int var) const override
	{
		int assignment = lglderef(m_solver, var);
		if (assignment > 0) {
			return Assignment::True;
		}
		if (assignment < 0) {
			return Assignment::False;
		}
		return Assignment::Undefined;
	}
};

}

#endif // COMMONSAT_LINGELING_H
