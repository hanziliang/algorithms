project(algorithms)

cmake_minimum_required(VERSION 3.14)

project(algorithms)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(average-tree-)
include_directories(dynamic/knapsack)
include_directories(dynamic/match_sum)
include_directories(kmp)

aux_source_directory(./kmp kmp_src)
aux_source_directory(./examples example)
aux_source_directory(./dynamic/match_sum match_sum_src)
aux_source_directory(./dynamic/knapsack knapsack_src)
aux_source_directory(./dynamic/floyd floyd_src)

MESSAGE("the src is : ${kmp_src}")

MESSAGE("match-sum-src : ${match_sum_src}")

add_executable(kmp ./examples/kmp.example.cpp ${kmp_src})
add_executable(matchsum ./examples/match.sum.example.cpp ${match_sum_src})
add_executable(knapsack ./examples/knapsack.example.cpp ${knapsack_src})
add_executable(floyd ./examples/floyd.example.cpp ${floyd_src})
add_executable(allpath ./examples/path/all_path.cpp)

add_executable(algorithms
        average-tree-/avlTree-sample.cpp
        average-tree-/avltree.h)
