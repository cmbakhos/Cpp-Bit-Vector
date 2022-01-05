# Set minimum cmake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(BitVector)

# Add the executables
add_executable(BitVector Tests.cpp BitVector.hpp BitVector.cpp)

# add testing executables
add_executable(Tests Testing/Tests.cpp
		Testing/catch.hpp
		BitVector.hpp
		BitVector.cpp
)