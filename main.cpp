#include <iostream>
#include "Lexer.h"

int main()
{
    auto input = "+=(){},;f";
    Lexer lexer(input);
    Token tok = Token();

    while( tok.getTokenType() != EndOfFile )
    {
        tok = lexer.NextToken();
        std::cout << tok << std::endl;
    }
    return 0;
}