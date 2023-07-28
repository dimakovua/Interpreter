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

bool operator== (const Token &t1, const Token &t2)
{
    return (t1.type == t2.type &&
            t2.literal == t2.literal);
}

bool operator!= (const Token &t1, const Token &t2)
{
    return !(t1== t2);
}