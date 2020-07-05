#include <string>
#include <string_view>
#include <vector>

#include "token.h"

#ifndef LEXER_H
#define LEXER_H

class Char
{
public:
    inline Char(char character) noexcept
        : m_character {character}
    {}

    inline Char(const Char& other) noexcept
    { m_character = other.m_character; }

    inline bool isNumber() const noexcept
    { return (m_character >= '0' && m_character <= '9'); }

    inline bool isLetter() const noexcept
    { return ((m_character >= 'A' && m_character <= 'z') && (m_character >= 'a' || m_character <= 'Z')); }

    bool isLetterOrNumber() const noexcept
    { return (isLetter() || isNumber()); }

    inline bool operator ==(const char character) const noexcept
    { return (m_character == character); }

    inline bool operator ==(const Char& other) const noexcept
    { return (m_character == other.m_character); }

    inline void operator =(const Char& other)
    { m_character = other.m_character; }

    inline char toStdChar() const noexcept
    { return m_character; }

private:
    char m_character {};
};

class Lexer
{
public:
    Lexer(const std::string_view input_data) noexcept;
    std::vector<Token> Tokenize() noexcept;

    Lexer(const Lexer&) = delete ;
    Lexer& operator=(const Lexer&) = delete;

private:
    const std::string m_input_data {};
    std::vector<Token> m_tokens_list {};
    uint32_t m_current_position {};

    inline void addToken(const TokenType token_type, const std::string_view token_data = {}) noexcept
    { m_tokens_list.emplace_back(token_type, token_data); }

    Char peek(const uint32_t at_index) const noexcept;
    inline Char nextToken() noexcept
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
        nextToken();
        tokenizeWord();
    }
};

#endif // LEXER_H
