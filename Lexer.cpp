#include "Lexer.h"

Lexer::Lexer(std::string input) :
    input(input),
    position(0),
    readPosition(0),
    ch(0)
{
    readChar();
}

void Lexer::readChar()
{
    if (readPosition >= input.length())
        ch = 0;
    else
        ch = input[readPosition];
    position = readPosition;
    readPosition++;
}

Token Lexer::NextToken()
{
    auto token = Token();
    switch (ch)
    {
        case '=':
            token = Token(ASSIGN, "=");
            break;
        case ';':
            token = Token(SEMICOLON, ";");
            break;
        case '(':
            token = Token(LPAREN, "(");
            break;
        case ')':
            token = Token(RPAREN, ")");
            break;
        case ',':
            token = Token(COMMA, ",");
            break;
        case '+':
            token = Token(PLUS, "+");
            break;
        case '{':
            token = Token(LBRACE, "{");
            break;
        case '}':
            token = Token(RBRACE, "}");
            break;
        case 0:
            token = Token(EndOfFile, "");
            break;
        default:
            token = Token(ILLEGAL, std::string(1, ch));
    }
    readChar();
    return token;
}