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

void Lexer::SkipWhitespace()
{
    while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
        readChar();
}

Token Lexer::AlphaDigitToken()
{
    if (isalpha(ch))
    {
        std::string literal = "";
        while(isalpha(ch))
        {
            literal += ch;
            readChar();
        }
        return Token(LookupIdent(literal), literal);;
    }
    else if(isdigit(ch))
    {
        std::string literal;
        while(isdigit(ch))
        {
            literal += ch;
            readChar();
        }
        return Token(INT, literal);
    }
    else
        return Token(ILLEGAL, std::string(1, ch));
}

Token Lexer::NextToken()
{
    auto token = Token();
    SkipWhitespace();
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
            return AlphaDigitToken();;
    }
    readChar();
    return token;
}

TokenType Lexer::LookupIdent(std::string ident)
{
    if (keywords.find(ident) != keywords.end())
        return keywords[ident];
    return IDENT;
}