#include "../include/parser.h"

#include <stdexcept>

std::vector<std::shared_ptr<AbstractExpression> > Parser::parse() noexcept
{
    std::vector<std::shared_ptr<AbstractExpression> > ret {};

    while (!match(TokenType::END_OF_FILE)) {
        ret.emplace_back(expression());
    }

    return ret;
}



Token Parser::peek(const size_t at_index) const noexcept
{
    const size_t position {m_current_position + at_index};

    if (position >= static_cast<size_t>(m_tokens_list.size())) {
        return EOF_token;
    }

    return m_tokens_list.at(position);
}



bool Parser::match(const TokenType token_type) noexcept
{
    const TokenType current_token_type {peek(0).getType()};

    if (token_type != current_token_type) {
        return false;
    }

    m_current_position++;
    return true;
}



std::shared_ptr<AbstractExpression> Parser::primary()
{
    const Token current_token {peek(0)};

    if (match(TokenType::NUMBER)) {
        return std::make_shared<NumberExpression>(std::stold(current_token.getData()));
    }

    throw std::runtime_error("Error: unknown token type!\n");
}



std::shared_ptr<AbstractExpression> Parser::unary()
{
    if (match(TokenType::OPERATOR_SUB)) {
        return std::make_shared<UnaryExpression>(primary(), '-');
    }
    return primary();
}



std::shared_ptr<AbstractExpression> Parser::additive()
{
    std::shared_ptr<AbstractExpression> result {multiplicative()};

    while (true) {
        if (match(TokenType::OPERATOR_ADD)) {
            result = std::make_shared<BinaryExpression>(result, multiplicative(), '+');
        }
        else if (match(TokenType::OPERATOR_SUB)) {
            result = std::make_shared<BinaryExpression>(result, multiplicative(), '-');
        }
        else {
            break;
        }
    }

    return result;
}



std::shared_ptr<AbstractExpression> Parser::multiplicative()
{
    std::shared_ptr<AbstractExpression> result {unary()};

    while (true) {
        if (match(TokenType::OPERATOR_MUL)) {
            result = std::make_shared<BinaryExpression>(result, unary(), '*');
        }
        else if (match(TokenType::OPERATOR_DIV)) {
            result = std::make_shared<BinaryExpression>(result, unary(), '/');
        }
        else {
            break;
        }
    }

    return result;
}
