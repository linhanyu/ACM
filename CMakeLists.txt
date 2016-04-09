cmake_minimum_required(VERSION 3.5)
project(ACM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    acm_practice_1/acm_practice_1/File_1.cpp
    acm_practice_1/acm_practice_1/File_2.cpp
    acm_practice_1/acm_practice_1/File_3.cpp
    acm_practice_1/acm_practice_1/File_4.cpp
    acm_practice_1/acm_practice_1/File_5.cpp
    acm_practice_1/acm_practice_1/File_6.cpp
    acm_practice_1/acm_practice_1/File_7.cpp
    acm_practice_1/acm_practice_1/File_8.cpp
    acm_practive_bignum/acm_practive_bignum/1002.cpp
    acm_practive_bignum/acm_practive_bignum/1003.cpp
    acm_practive_bignum/acm_practive_bignum/1004.cpp
    acm_practive_bignum/acm_practive_bignum/1005.cpp
    acm_practive_bignum/acm_practive_bignum/1006.cpp
    acm_practive_bignum/acm_practive_bignum/1007.cpp
    Project1/Project1/2_d_tree.cpp
    Project1/Project1/AA_tree.cpp
    Project1/Project1/Red_Black_Tree.cpp
    Project1/Project1/Skip_List.cpp
    Project1/Project1/Splay_Tree.cpp
    Project1/Project1/Treaps.cpp DP/3008.cpp DP/1011.cpp DP/1081.cpp)

add_executable(ACM ${SOURCE_FILES})