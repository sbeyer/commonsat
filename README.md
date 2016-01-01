# CommonSAT

CommonSAT is intended as a common C++11 SAT solver interface for different SAT solvers.

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
 - [ ] PicoSat
 - [ ] PrecoSat
 - [ ] YALS

Note that the things mentioned above are TODO list items that are probably not
implemented.

[![Build Status](https://travis-ci.org/sbeyer/commonsat.svg)](https://travis-ci.org/sbeyer/commonsat)
