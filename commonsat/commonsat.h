/*! \file
 * \brief Definition of the main interface for CommonSAT.
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

#ifndef COMMONSAT_H
#define COMMONSAT_H

#include <vector>

namespace commonsat {

using clause_t = std::vector<int>;

//! The general solver interface class
class SolverInterface {
public:
	SolverInterface()
	{
	}

	//! Add a clause to the CNF
	// \example add_clause({1, -2, -3, 6}) adds clause {x_1, not x_2, not x_3, x_6}
	virtual void add_clause(const clause_t &clause) = 0;

	//! Solve the CNF given by the added clauses
	// \return true if the CNF is satisfiable, false if not
	virtual bool solve() = 0;
};

}

#endif // COMMONSAT_H
