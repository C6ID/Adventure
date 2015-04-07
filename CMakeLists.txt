project(Adventure)
cmake_minimum_required(VERSION 3.0)

# We use C++14. Period.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include(FindPkgConfig)

add_subdirectory(engine)
add_subdirectory(launcher)
