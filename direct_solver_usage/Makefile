# TODO: this should be generated automatically by cmake, dependent on the available solvers
CXX=g++-5
LD=$(CXX)
CXXFLAGS=-std=c++11 -Wall -W -Wextra
CRYPTOMINISAT4_INCLUDE=../solvers/cryptominisat/include
CRYPTOMINISAT4_LIB=../solvers/cryptominisat/lib
MINISAT_INCLUDE=../solvers/minisat
MINISAT_LIB=../solvers/minisat
LINGELING_INCLUDE=../solvers/lingeling-cssc14/lingeling-azf-9203284-140522
LINGELING_LIB=../solvers/lingeling-cssc14/lingeling-azf-9203284-140522
BINARIES=cryptominisat4 minisat lingeling test_minisat test_lingeling

.PHONY: all run clean

all: $(BINARIES)

run: all
	LD_LIBRARY_PATH=$(CRYPTOMINISAT4_LIB) ./cryptominisat4
	LD_LIBRARY_PATH=$(MINISAT_LIB) ./minisat
	LD_LIBRARY_PATH=$(LINGELING_LIB) ./lingeling
	LD_LIBRARY_PATH=$(MINISAT_LIB) ./test_minisat
	LD_LIBRARY_PATH=$(LINGELING_LIB) ./test_lingeling

clean:
	rm -f $(BINARIES)

cryptominisat4: cryptominisat4.cc
	"$(CXX)" $(CXXFLAGS) -I"$(CRYPTOMINISAT4_INCLUDE)" "$<" -L"$(CRYPTOMINISAT4_LIB)" -lcryptominisat4 -o "$@"

minisat: minisat.cc
	"$(CXX)" $(CXXFLAGS) -I"$(MINISAT_INCLUDE)" "$<" -L"$(MINISAT_LIB)" -lminisat -o "$@"

test_minisat: test_minisat.cc
	"$(CXX)" $(CXXFLAGS) -I.. -I"$(MINISAT_INCLUDE)" "$<" -L"$(MINISAT_LIB)" -lminisat -o "$@"

lingeling: lingeling.cc
	"$(CXX)" $(CXXFLAGS) -I"$(LINGELING_INCLUDE)" "$<" -L"$(LINGELING_LIB)" -llgl -o "$@"

test_lingeling: test_lingeling.cc
	"$(CXX)" $(CXXFLAGS) -I.. -I"$(LINGELING_INCLUDE)" "$<" -L"$(LINGELING_LIB)" -llgl -o "$@"
