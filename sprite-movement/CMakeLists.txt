project(sprite-movement CXX)

cmake_minimum_required(VERSION 3.2.2)

add_definitions(-DVERSION_MAJOR=0)
add_definitions(-DVERSION_MINOR=0)
add_definitions(-DVERSION_PATCH=1)
add_definitions(-DAPPLICATION_NAME="Sprite Movement")

find_package(Qt5 COMPONENTS Core Gui Widgets Qml Quick)

set(CMAKE_AUTOMOC TRUE)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/plugins/nwoki/qml/SpriteMovementSettings)

# custom variables
set(MAPS_DIRECTORY ${CMAKE_SOURCE_DIR}/assets/maps/)
set(SPRITES_DIRECTORY ${CMAKE_SOURCE_DIR}/assets/sprites/)
set(PLUGIN_DIRECTORY ${CMAKE_BINARY_DIR}/output/plugins)
set(SETTINGS_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/settings)

# C++11
add_definitions("-std=gnu++11")

# src
add_subdirectory(src)
add_subdirectory(plugins)
