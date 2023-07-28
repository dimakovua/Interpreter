cmake_minimum_required(VERSION 2.4)

project(lexer)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(app main.cpp Lexer.cpp Token.cpp)