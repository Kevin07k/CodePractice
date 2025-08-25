cmake_minimum_required(VERSION 3.31)
project(Contest)

set(CMAKE_CXX_STANDARD 20)

#[[add_executable(Contest
        elemental/modulo_5/clases/intro_dp.cpp
        elemental/modulo_5/clases/D.cpp
        elemental/modulo_6/dfs_modificado.cpp
        elemental/modulo_6/dfs.cpp
        elemental/modulo_6/Contest/A.cpp
        elemental/modulo_6/dfs_topological_sort.cpp
        elemental/modulo_6/bfs.cpp
        elemental/modulo_6/Contest/B-flood_fill.cpp
)]]

add_executable(B-flod_fill elemental/modulo_6/Contest/B-flood_fill.cpp)
