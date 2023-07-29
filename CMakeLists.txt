cmake_minimum_required(VERSION 3.0)
project(Interpreter)

# Set the C++ standard to C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the source files to your project
set(SOURCES
    Lexer.cpp
    Token.cpp
    main.cpp
)

# Add header files to your project
set(HEADERS
    Lexer.h
    Token.h
    UnitTests/MyTests.h
    UnitTests/Tests.h
)

# Create an executable for your project
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
