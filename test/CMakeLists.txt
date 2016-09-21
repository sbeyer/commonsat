include_directories("${PROJECT_SOURCE_DIR}/test/bandit")

if(USE_MINISAT)
	include_directories("${MINISAT_INCLUDE_DIR}")
	add_executable(test_minisat minisat.cc)
	target_link_libraries(test_minisat ${MINISAT_LIBRARY})
endif(USE_MINISAT)

if(USE_CRYPTOMINISAT)
	find_package(Threads)
	include_directories("${CRYPTOMINISAT_INCLUDE_DIR}")
	add_executable(test_cryptominisat cryptominisat.cc)
	target_link_libraries(test_cryptominisat
	    ${CRYPTOMINISAT_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
endif(USE_CRYPTOMINISAT)

if(USE_LINGELING)
	include_directories("${LINGELING_INCLUDE_DIR}")
	add_executable(test_lingeling lingeling.cc)
	target_link_libraries(test_lingeling ${LINGELING_LIBRARY})
endif(USE_LINGELING)

if(USE_PICOSAT)
	include_directories("${PICOSAT_INCLUDE_DIR}")
	add_executable(test_picosat picosat.cc)
	target_link_libraries(test_picosat ${PICOSAT_LIBRARY})
endif(USE_PICOSAT)
