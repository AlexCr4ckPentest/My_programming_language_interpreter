#include <iostream>
#include <string>

#include "include/lexer.h"
#include "include/parser.h"

int main()
{
    const std::string test_expr1 {"2 + 2 * 2"};

    Lexer lexer {test_expr1};
    auto tokens_list {lexer.Tokenize()};

    Parser parser {tokens_list};
    auto expressions {parser.parse()};

    std::cout << "Expression: " << test_expr1 << "\n";

    for (auto result : expressions) {
        std::cout << "Result: " << result->eval() << "\n";
    }

    return 0;
}
