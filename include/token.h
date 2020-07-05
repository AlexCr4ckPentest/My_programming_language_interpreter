#include <string>
#include <string_view>
#include <ostream>

#include "token_types.h"

#ifndef TOKEN_H
#define TOKEN_H

class Token
{
public:
    Token(const TokenType type, const std::string_view data) noexcept;

    Token& operator=(const Token&) = delete;

    inline TokenType getType() const noexcept
    { return m_token_type; }

    inline std::string getData() const noexcept
    { return m_token_data; }

    inline friend std::ostream& operator <<(std::ostream& out, const Token& token)
    { return (out << "Token: (type=" << token.m_token_type << ", data='" << token.m_token_data << "')"); }

private:
    const TokenType m_token_type {};
    const std::string m_token_data {};
};

#endif // TOKEN_H
