#include "include/lexer.h"

#include <algorithm>

inline static constexpr TokenType operator_token_types[]
{
    TokenType::OPERATOR_ADD, TokenType::OPERATOR_SUB,
    TokenType::OPERATOR_MUL, TokenType::OPERATOR_DIV,
    TokenType::OPERATOR_ASSIG
};

static const std::vector<Char> operator_characters {'+', '-', '*', '/', '='};

Lexer::Lexer(const std::string_view input_data) noexcept
    : m_input_data {input_data}
{}

std::vector<Token> Lexer::Tokenize() noexcept
{
    while (m_current_position < static_cast<uint32_t>(m_input_data.size())) {
        const Char current_char {peek(0)};
        if (current_char.isNumber()) {
            tokenizeNumber();
        }
        else if (std::find(operator_characters.cbegin(), operator_characters.cend(), current_char.toStdChar()) != operator_characters.cend()) {
            tokenizeOperator();
        }
        else if (current_char.isLetter() || current_char == '_') {
            tokenizeWord();
        }
        else if (current_char == '$') {
            tokenizeVariable();
        }
        else {
            nextToken();
        }
    }

    return m_tokens_list;
}

Char Lexer::peek(const uint32_t at_index) const noexcept
{
    const uint32_t position {m_current_position + at_index};

    if (position >= static_cast<uint32_t>(m_input_data.size())) {
        return '\0';
    }

    return m_input_data.at(position);
}

void Lexer::tokenizeNumber() noexcept
{
    Char current_char {peek(0)};
    std::string token_data {};

    while (current_char.isNumber() || current_char == '.') {
        token_data += current_char.toStdChar();
        current_char = nextToken();
    }

    addToken(TokenType::NUMBER, token_data);
}

void Lexer::tokenizeWord() noexcept
{
    Char current_char {peek(0)};
    std::string token_data {};

    while (current_char.isLetterOrNumber() || current_char == '_') {
        token_data += current_char.toStdChar();
        current_char = nextToken();
    }

    addToken(TokenType::WORD, token_data);
}

void Lexer::tokenizeOperator() noexcept
{
    uint8_t index {static_cast<uint8_t>(std::distance(operator_characters.cbegin(),
                                                      std::find(operator_characters.cbegin(),
                                                                operator_characters.cend(), peek(0))))};
    addToken(operator_token_types[index]);
    nextToken();
}
