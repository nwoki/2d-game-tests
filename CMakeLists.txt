project(2d-game-tests CXX)

cmake_minimum_required(VERSION 3.2.2)

add_definitions(-DVERSION_MAJOR=0)
add_definitions(-DVERSION_MINOR=0)
add_definitions(-DVERSION_PATCH=1)

# src
add_subdirectory(sprite-movement)

