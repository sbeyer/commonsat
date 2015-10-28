set(CMAKE_CXX_STANDARD 11)

option(USE_CRYPTOMINISAT "Use CryptoMiniSat solver" OFF)
option(USE_MINISAT "Use MiniSat solver" OFF)
option(USE_LINGELING "Use Lingeling solver" OFF)

include_directories("${PROJECT_SOURCE_DIR}/")

if(USE_MINISAT)
	set(MINISAT_LIBRARY
	    "${PROJECT_SOURCE_DIR}/solvers/minisat/libminisat.so"
	    CACHE FILEPATH "Library for MiniSat")
	set(MINISAT_INCLUDE_DIR
	    "${PROJECT_SOURCE_DIR}/solvers/minisat"
	    CACHE PATH "Include directory for MiniSat")
	include_directories("${MINISAT_INCLUDE_DIR}")
	add_executable(minisat minisat.cc)
	add_executable(test_minisat test_minisat.cc)
	target_link_libraries(minisat ${MINISAT_LIBRARY})
	target_link_libraries(test_minisat ${MINISAT_LIBRARY})
endif(USE_MINISAT)

if(USE_CRYPTOMINISAT)
	set(CRYPTOMINISAT4_LIBRARY
	    "${PROJECT_SOURCE_DIR}/solvers/cryptominisat/lib/libcryptominisat4.so"
	    CACHE FILEPATH "Library for CryptoMiniSat 4")
	set(CRYPTOMINISAT4_INCLUDE_DIR
	    "${PROJECT_SOURCE_DIR}/solvers/cryptominisat/include"
	    CACHE PATH "Include directory for CryptoMiniSat 4")
	include_directories("${CRYPTOMINISAT4_INCLUDE_DIR}")
	add_executable(cryptominisat4 cryptominisat4.cc)
	add_executable(test_cryptominisat test_cryptominisat.cc)
	target_link_libraries(cryptominisat4 ${CRYPTOMINISAT4_LIBRARY})
	target_link_libraries(test_cryptominisat ${CRYPTOMINISAT4_LIBRARY})
endif(USE_CRYPTOMINISAT)

if(USE_LINGELING)
	set(LINGELING_LIBRARY
	    "${PROJECT_SOURCE_DIR}/solvers/lingeling-cssc14/lingeling-azf-9203284-140522/liblgl.a"
	    CACHE FILEPATH "Library for lingeling")
	set(LINGELING_INCLUDE_DIR
	    "${PROJECT_SOURCE_DIR}/solvers/lingeling-cssc14/lingeling-azf-9203284-140522"
	    CACHE PATH "Include directory for lingeling")
	include_directories("${LINGELING_INCLUDE_DIR}")
	add_executable(lingeling lingeling.cc)
	add_executable(test_lingeling test_lingeling.cc)
	target_link_libraries(lingeling ${LINGELING_LIBRARY})
	target_link_libraries(test_lingeling ${LINGELING_LIBRARY})
endif(USE_LINGELING)
