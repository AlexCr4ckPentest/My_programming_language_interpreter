#include "include/lexer.h"

#include <algorithm>

inline static constexpr TokenType operator_token_types[]
{
    TokenType::OPERATOR_ADD, TokenType::OPERATOR_SUB,
    TokenType::OPERATOR_MUL, TokenType::OPERATOR_DIV,
    TokenType::OPERATOR_ASSIG
};

static const std::vector<TokenChar> operator_characters {'+', '-', '*', '/', '='};



std::vector<Token> Lexer::Tokenize() noexcept
{
    TokenChar current_char {};

    while (m_current_position < static_cast<size_t>(m_input_data.size())) {
        current_char = peek(0);
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
            nextCharacter();
        }
    }

    return m_tokens_list;
}



TokenChar Lexer::peek(const size_t at_index) const noexcept
{
    const size_t position {m_current_position + at_index};

    if (position >= static_cast<size_t>(m_input_data.size())) {
        return '\0';
    }

    return m_input_data.at(position);
}



void Lexer::tokenizeNumber() noexcept
{
    TokenChar current_char {peek(0)};
    std::string token_data {};

    while (current_char.isNumber() || current_char == '.') {
        token_data += current_char.toStdChar();
        current_char = nextCharacter();
    }

    addToken(TokenType::NUMBER, token_data);
}



void Lexer::tokenizeWord() noexcept
{
    TokenChar current_char {peek(0)};
    std::string token_data {};

    while (current_char.isLetterOrNumber() || current_char == '_') {
        token_data += current_char.toStdChar();
        current_char = nextCharacter();
    }

    addToken(TokenType::WORD, token_data);
}



void Lexer::tokenizeOperator() noexcept
{
    uint8_t index {static_cast<uint8_t>(std::distance(operator_characters.cbegin(),
                                                      std::find(operator_characters.cbegin(),
                                                                operator_characters.cend(), peek(0))))};
    addToken(operator_token_types[index]);
    nextCharacter();
}
