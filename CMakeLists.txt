cmake_minimum_required(VERSION 3.19)
project(Task_31_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task_31_2 main.cpp src/IGraph.cpp src/ListGraph.cpp src/MatrixGraph.cpp src/AdjacencyMatrix.cpp)