#include <string>
#include <string_view>
#include <vector>

#include "token.h"
#include "token_char.h"

#ifndef LEXER_H
#define LEXER_H

class Lexer
{
public:
    inline explicit Lexer(const std::string_view input_data) noexcept
        : m_input_data {input_data}
    {}

    Lexer(const Lexer&) = delete;
    Lexer& operator=(const Lexer&) = delete;

    std::vector<Token> Tokenize() noexcept;

private:
    const std::string m_input_data {};
    std::vector<Token> m_tokens_list {};
    size_t m_current_position {};

    inline void addToken(const TokenType token_type, const std::string_view token_data = {}) noexcept
    { m_tokens_list.emplace_back(token_type, token_data); }

    TokenChar peek(const size_t at_index) const noexcept;

    inline TokenChar nextCharacter() noexcept
    {
        m_current_position++;
        return peek(0);
    }

    void tokenizeNumber() noexcept;
    void tokenizeWord() noexcept;
    void tokenizeOperator() noexcept;
    inline void tokenizeVariable() noexcept
    {
        addToken(TokenType::VARIABLE);
        nextCharacter();
        tokenizeWord();
    }
};

#endif // LEXER_H
