# Set minimum cmake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(BitVector)

# Find Boost
Set(Boost_INCLUDE_DIR "/mnt/d/Program\ Files/boost_1_78_0")
#message(STATUS "include dir: ${Boost_INCLUDE_DIR}")
message(STATUS "include dir: ${Boost_INCLUDE_DIR}/boost")
find_package(Boost 1.78.0 REQUIRED)
IF(Boost_FOUND)
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ENDIF()

# Add the executables
add_executable(BitVector Main.cpp BitVector.hpp BitVector.cpp)

# add testing executables
add_executable(tests Testing/Tests.cpp
		Testing/catch.hpp
		BitVector.hpp
		BitVector.cpp
)