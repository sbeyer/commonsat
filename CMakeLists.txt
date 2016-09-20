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
	    "${PROJECT_SOURCE_DIR}/solvers/minisat/build/libminisat.a"
	    CACHE FILEPATH "Library for MiniSat")
	set(MINISAT_INCLUDE_DIR
	    "${PROJECT_SOURCE_DIR}/solvers/minisat"
	    CACHE PATH "Include directory for MiniSat")
	add_test(NAME MiniSat COMMAND test_minisat)
endif(USE_MINISAT)

if(USE_CRYPTOMINISAT)
	set(CRYPTOMINISAT_LIBRARY
	    "${PROJECT_SOURCE_DIR}/solvers/cryptominisat/build/lib/libcryptominisat5.so"
	    CACHE FILEPATH "Library for CryptoMiniSat")
	set(CRYPTOMINISAT_INCLUDE_DIR
	    "${PROJECT_SOURCE_DIR}/solvers/cryptominisat/build/include"
	    CACHE PATH "Include directory for CryptoMiniSat")
	add_test(NAME CryptoMiniSat COMMAND test_cryptominisat)
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

add_subdirectory(test)

find_package(Doxygen)
add_custom_target(doc ${DOXYGEN_EXECUTABLE} doxygen.cfg)
