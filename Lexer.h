#pragma once

#include "Token.h"
#include <iostream>
#include <unordered_map>
#include <ctype.h>
class Lexer
{
public:
    Lexer(std::string input);
    void readChar();
    Token NextToken();
    Token AlphaDigitToken(); // Check if lexeme is an identifier or integer
    TokenType LookupIdent(std::string ident); // Check if lexeme is a keyword
    void SkipWhitespace();
    char peekChar();
private:
    std::string input;
    int position;
    int readPosition;
    char ch;
    std::unordered_map<std::string, TokenType> keywords = {
        {"fn", FUNCTION},
        {"let", LET},
        {"true", TRUE},
        {"false", FALSE},
        {"if", IF},
        {"else", ELSE},
        {"return", RETURN}
    };
};
