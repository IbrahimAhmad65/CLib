cmake_minimum_required(VERSION 3.24)
project(MathLib)

set(CMAKE_CXX_STANDARD 17)

add_library(MathLib SHARED library.cpp LinearAlgebra/Matrix.cpp LinearAlgebra/Matrix.h LinearAlgebra/Vector.cpp LinearAlgebra/Vector.h)
