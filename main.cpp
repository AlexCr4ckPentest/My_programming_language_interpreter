#include <iostream>
#include <string>

#include "include/lexer.h"

int main()
{
    const std::string test_expr {"Test 1.2 + 2.33 - 3.444 * 4.5555 / 5.66666"};

    Lexer lexer {test_expr};
    auto tokens_list {lexer.Tokenize()};

    std::cout << "Expression: " << test_expr << "\n";

    for (auto token : tokens_list) {
        std::cout << token << "\n";
    }

    return 0;
}
