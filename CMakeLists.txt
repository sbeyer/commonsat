cmake_minimum_required(VERSION 3.0)

find_package(Doxygen)
add_custom_target(doc ${DOXYGEN_EXECUTABLE} doxygen.cfg)
