#include "include/token.h"

Token::Token(const TokenType type, const std::string_view data) noexcept
    : m_token_type {type}
    , m_token_data {data}
{}
