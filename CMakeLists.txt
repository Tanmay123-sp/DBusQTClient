cmake_minimum_required(VERSION 3.16)

project(dbusClient)

# Find required Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core DBus Widgets)

# Enable AUTOMOC for Q_OBJECT macros
set(CMAKE_AUTOMOC ON)

# Add the executable for the D-Bus client
add_executable(dbusClient dbusClient.cpp dbusClient.h main.cpp)

# Link Qt libraries to the target
target_link_libraries(dbusClient Qt6::Core Qt6::DBus Qt6::Widgets)

# Specify C++ standard
set_target_properties(dbusClient PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
