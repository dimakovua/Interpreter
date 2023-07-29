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
#define MINUS "-"
#define BANG "!"
#define ASTERISK "*"
#define SLASH "/"
#define LT "<"
#define GT ">"
#define EQ "=="
#define NOT_EQ "!="
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
#define TRUE "TRUE"
#define FALSE "FALSE"
#define IF "IF"
#define ELSE "ELSE"
#define RETURN "RETURN"
//----------------------------------------------------------------

class Token
{
public:
//Constructors
    Token(TokenType type, std::string literal);
    Token()
    {
        type = "";
        literal = "";
    }

//Getters and setters
    TokenType getTokenType() const { return type; }

private:
    TokenType type;
    std::string literal;

//Operators
friend std::ostream& operator<< (std::ostream &out, const Token &token);
friend bool operator== (const Token &t1, const Token &t2);
friend bool operator!= (const Token &t1, const Token &t2);
};

