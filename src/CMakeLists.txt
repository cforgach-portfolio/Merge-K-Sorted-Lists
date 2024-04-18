cmake_minimum_required(VERSION 3.27.4)

project(MergeKSorted)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MergeKSorted main.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(MergeKSorted PUBLIC OpenMP::OpenMP_CXX)
endif()

