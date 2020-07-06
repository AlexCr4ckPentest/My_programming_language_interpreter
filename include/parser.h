#include <vector>
#include <stack>
#include <memory>

#include "token.h"
#include "expressions/abstract_expression.h"

#ifndef PARSER_H
#define PARSER_H

class Parser
{
public:
    inline explicit Parser(const std::vector<Token>& tokens_list) noexcept
        : m_tokens_list {tokens_list}
    {}

    void parse() noexcept;

private:
    const std::vector<Token> m_tokens_list {};
    std::stack<std::unique_ptr<AbstractExpression> > m_expression_ptrs {};
};

#endif // PARSER_H
