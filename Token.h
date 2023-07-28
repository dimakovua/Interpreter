#pragma once 

#include <string>
#include <iostream>
#define TokenType std::string


//Defining tokens
//----------------------------------------------------------------
#define ILLEGAL "ILLEGAL"
#define EndOfFile "EOF"

//Identifiers + literals
#define IDENT "IDENT" //add, foobar, x, y, ...
#define INT "INT" // 1343456

//Operators
#define ASSIGN "="
#define PLUS "+"

//Delimiters
#define COMMA ","
#define SEMICOLON ";"

#define LPAREN "("
#define RPAREN ")"
#define LBRACE "{"
#define RBRACE "}"

//Keywords
#define FUNCTION "FUNCTION"
#define LET "LET"
//----------------------------------------------------------------

class Token
{
public:
    Token(TokenType type, std::string literal);
    Token()
    {
        type = "";
        literal = "";
    }

    TokenType getTokenType() const { return type; }

private:
    TokenType type;
    std::string literal;

friend std::ostream& operator<< (std::ostream &out, const Token &token);
};

