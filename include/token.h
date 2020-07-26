#include <string>
#include <string_view>
#include <sstream>
#include <ostream>

#include "token_types.h"

#ifndef TOKEN_H
#define TOKEN_H

class Token
{
public:
    Token(const TokenType token_type, const std::string_view token_data = {}) noexcept
        : m_token_type {token_type}
        , m_token_data {token_data}
    {}

    Token& operator =(const Token&) = delete;

    inline TokenType getType() const noexcept
    { return m_token_type; }

    inline std::string getData() const noexcept
    { return m_token_data; }

    inline std::string toString() const noexcept
    {
        std::ostringstream ss {};
        ss << "Token: (type=" << m_token_type << ", data='" << m_token_data << "')";
        return ss.str();
    }

    inline friend std::ostream& operator <<(std::ostream& out, const Token& token)
    { return (out << token.toString()); }

private:
    const TokenType m_token_type {};
    const std::string m_token_data {};
};

#endif // TOKEN_H
