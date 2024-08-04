#!/bin/sh
# Get all submodules, get and compile all supported solvers,
# compile tests and run them

SOLVERS="CRYPTOMINISAT LINGELING MINISAT PICOSAT"
CMAKE_SOLVERS="$(for solver in $SOLVERS ; do echo -n " -DUSE_$solver=ON" ; done)"

git submodule update --init --recursive &&
make -C solvers &&
cmake -B build $CMAKE_SOLVERS -DCMAKE_EXPORT_COMPILE_COMMANDS=ON . || exit

( cd build &&
  make &&
  ctest )

test -e compile_commands.json || ln -s build/compile_commands.json
