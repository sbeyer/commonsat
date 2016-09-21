#!/bin/sh
# Get all submodules, get and compile all supported solvers,
# compile tests and run them

SOLVERS="CRYPTOMINISAT LINGELING MINISAT PICOSAT"
CMAKE_SOLVERS="$(for solver in $SOLVERS ; do echo -n " -DUSE_$solver=ON" ; done)"

git submodule update --init --recursive &&
make -C solvers &&
cmake $CMAKE_SOLVERS . &&
make &&
ctest --verbose
