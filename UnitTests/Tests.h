#pragma once

#include "MyTests.h"
#include "../Lexer.h"

void TestLexer()
{
    auto input =
        "let five = 5;"
        "let ten = 10;"
        "let add = fn(x, y) {"
        "    x + y;"
        "};"
        "let result = add(five, ten);";

    Token expected_result[] = {
        Token(LET, "let"),
        Token(IDENT, "five"),
        Token(ASSIGN, "="),
        Token(INT, "5"),
        Token(SEMICOLON, ";"),
        Token(LET, "let"),
        Token(IDENT, "ten"),
        Token(ASSIGN, "="),
        Token(INT, "10"),
        Token(SEMICOLON, ";"),
        Token(LET, "let"),
        Token(IDENT, "add"),
        Token(ASSIGN, "="),
        Token(FUNCTION, "fn"),
        Token(LPAREN, "("),
        Token(IDENT, "x"),
        Token(COMMA, ","),
        Token(IDENT, "y"),
        Token(RPAREN, ")"),
        Token(LBRACE, "{"),
        Token(IDENT, "x"),
        Token(PLUS, "+"),
        Token(IDENT, "y"),
        Token(SEMICOLON, ";"),
        Token(RBRACE, "}"),
        Token(SEMICOLON, ";"),
        Token(LET, "let"),
        Token(IDENT, "result"),
        Token(ASSIGN, "="),
        Token(IDENT, "add"),
        Token(LPAREN, "("),
        Token(IDENT, "five"),
        Token(COMMA, ","),
        Token(IDENT, "ten"),
        Token(RPAREN, ")"),
        Token(SEMICOLON, ";"),
        Token(EndOfFile, "")
    };

    Lexer lexer(input);
    size_t index = 0;
    while (index < sizeof(expected_result)/sizeof(expected_result[0]))
    {
        AssertEqual(expected_result[index], lexer.NextToken(), "Script input");
        index++;
    }
}

void TestAll()
{
    TestRunner tr;
    tr.RunTest(TestLexer, "TestLexer");
}