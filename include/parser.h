#include <vector>
#include <stack>
#include <memory>
#include <stdexcept>

#include "token.h"

#include "expressions/abstract_expression.h"
#include "expressions/number_expression.h"
#include "expressions/binary_expression.h"

#ifndef PARSER_H
#define PARSER_H

class Parser
{
public:
    inline explicit Parser(const std::vector<Token>& tokens_list) noexcept
        : m_tokens_list {tokens_list}
    {}

    Parser(const Parser&) = delete;
    Parser& operator =(const Parser&) = delete;

    std::vector<std::shared_ptr<AbstractExpression> > parse() noexcept;

    Token peek(const size_t at_index) const noexcept;
    inline Token nextToken() noexcept
    {
        m_current_position++;
        return peek(0);
    }

    bool match(const TokenType token_type) noexcept;

    inline std::shared_ptr<AbstractExpression> expression()
    { return additive(); }

    std::shared_ptr<AbstractExpression> primary();
    std::shared_ptr<AbstractExpression> unary();

    std::shared_ptr<AbstractExpression> additive();
    std::shared_ptr<AbstractExpression> multiplicative();

private:
    const Token EOF_token {TokenType::END_OF_FILE};

    const std::vector<Token> m_tokens_list {};
    std::stack<std::shared_ptr<AbstractExpression> > m_expression_ptrs {};
    size_t m_current_position {};
};

#endif // PARSER_H
