# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# project name
project(simple_nlp_codegen)

# creates the variable EXEC and sets it to hello
# set(EXEC nlp_codegen)

# set the C++11 standard
set(CMAKE_CXX_STANDARD 11)

# I../includes
include_directories(includes /usr/local/include /usr/local/include/casadi)

# Add IPOPT link directories
if(WITH_IPOPT)
  link_directories(${IPOPT_LIBRARY_DIRS})
endif()

# puts all .cpp files inside src to the SOURCES variable
# file(GLOB SOURCES src/*.cpp)

# compiles the files defined by SOURCES to generante the executable defined by EXEC
# add_executable(${EXEC} ${SOURCES})

# Solve linear system of equations
add_executable(simple_nlp_codegen src/simple_nlp_codegen.cpp)
target_link_libraries(simple_nlp_codegen casadi)

