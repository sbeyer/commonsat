cmake_minimum_required(VERSION 3.0)

project(CommonSAT)

set(CMAKE_CXX_STANDARD 11)

option(USE_CRYPTOMINISAT "Use CryptoMiniSat solver" OFF)
option(USE_MINISAT "Use MiniSat solver" OFF)
option(USE_LINGELING "Use Lingeling solver" OFF)

include_directories("${PROJECT_SOURCE_DIR}/")

enable_testing()

if(USE_MINISAT)
	set(MINISAT_LIBRARY
	    "${PROJECT_SOURCE_DIR}/solvers/minisat/build/release/lib/libminisat.a"
	    CACHE FILEPATH "Library for MiniSat")
	set(MINISAT_INCLUDE_DIR
	    "${PROJECT_SOURCE_DIR}/solvers/minisat"
	    CACHE PATH "Include directory for MiniSat")
	add_test(NAME MiniSat COMMAND test_minisat)
endif(USE_MINISAT)

if(USE_CRYPTOMINISAT)
	set(CRYPTOMINISAT4_LIBRARY
	    "${PROJECT_SOURCE_DIR}/solvers/cryptominisat/lib/libcryptominisat4.a"
	    CACHE FILEPATH "Library for CryptoMiniSat 4")
	set(CRYPTOMINISAT4_INCLUDE_DIR
	    "${PROJECT_SOURCE_DIR}/solvers/cryptominisat/include"
	    CACHE PATH "Include directory for CryptoMiniSat 4")
	add_test(NAME CryptoMiniSat COMMAND test_cryptominisat4)
endif(USE_CRYPTOMINISAT)

if(USE_LINGELING)
	set(LINGELING_LIBRARY
	    "${PROJECT_SOURCE_DIR}/solvers/lingeling/code/liblgl.a"
	    CACHE FILEPATH "Library for lingeling")
	set(LINGELING_INCLUDE_DIR
	    "${PROJECT_SOURCE_DIR}/solvers/lingeling/code"
	    CACHE PATH "Include directory for lingeling")
	add_test(NAME Lingeling COMMAND test_lingeling)
endif(USE_LINGELING)

add_subdirectory(direct_solver_usage)
add_subdirectory(test)

find_package(Doxygen)
add_custom_target(doc ${DOXYGEN_EXECUTABLE} doxygen.cfg)
