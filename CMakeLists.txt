cmake_minimum_required(VERSION 3.0)

project(CommonSAT)

add_subdirectory(direct_solver_usage)

find_package(Doxygen)
add_custom_target(doc ${DOXYGEN_EXECUTABLE} doxygen.cfg)
