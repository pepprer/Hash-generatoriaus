cmake_minimum_required(VERSION 3.17)
project(hash_generatorius)

set(CMAKE_CXX_STANDARD 14)

add_executable(hash_generatorius main.cpp header.h cppFiles/ReadWrite.cpp hFiles/ReadWrite.h cppFiles/Hash.cpp hFiles/Hash.h cppFiles/Test.cpp hFiles/Test.h cppFiles/Sha256.cpp hFiles/Sha256.h)