#include "Token.h"

Token::Token(TokenType type, std::string literal) :
    type(type),
    literal(literal)
{
}

std::ostream& operator<< (std::ostream &out, const Token &token)
{
    out << "Token(" << token.type << ": " << token.literal << ")";
    return out;
}