# CommonSAT

CommonSAT is intended as a common C++11 SAT solver interface for different SAT solvers.

[![Build Status](https://travis-ci.org/sbeyer/commonsat.svg)](https://travis-ci.org/sbeyer/commonsat)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/d2e9f78b43924f418914201125716925)](https://www.codacy.com/app/sbeyer/commonsat?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=sbeyer/commonsat&amp;utm_campaign=Badge_Grade)

## So... what is CommonSAT?

It is a header-only library, providing a common interface for

 - [ ] reading CNFs in DIMACS format
 - [ ] writing CNFs in DIMACS format
 - [X] generating CNF formulae
 - [X] solving them (sequentially)
 - [ ] solving them in parallel
 - [X] obtaining satisfiability or non-satisfiability information
 - [X] obtaining a satisfiable assignment (if satisfiable)
 - [ ] obtaining conflict information (if non-satisfiable)
 - [ ] obtaining information about the computation
 - [ ] freezing and thawing variables for incremental computations

for SAT solver libraries like

 - [X] MiniSAT
 - [X] CryptoMiniSat
 - [X] Lingeling
 - [ ] Plingeling
 - [ ] Treengeling
 - [X] PicoSat
 - [ ] PrecoSat
 - [ ] YALS

Note that the things mentioned above are TODO list items that are probably not
implemented.

## How do I get something to run ...quickly?

The quickest way to get started is along the following lines:
```sh
sudo apt install git cmake doxygen graphviz
git clone https://github.com/sbeyer/commonsat.git
cd commonsat
util/quickstart.sh
doxygen .
```

The quickstart script will do a lot of magic, like updating submodules (for
the test suite), obtaining and compiling all the supported solvers, and
compile and run the commonsat tests.
