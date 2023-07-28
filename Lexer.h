#include "Token.h"
#include <iostream>
class Lexer
{
public:
    Lexer(std::string input);
    void readChar();
    Token NextToken();
private:
    std::string input;
    int position;
    int readPosition;
    char ch;
};
