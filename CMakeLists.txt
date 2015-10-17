cmake_minimum_required(VERSION 2.6)
project(ensemble)

add_executable(ensemble main.cpp)

install(TARGETS ensemble RUNTIME DESTINATION bin)
