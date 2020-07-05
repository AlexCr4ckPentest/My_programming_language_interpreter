#include <ostream>

#ifndef TOKEN_TYPES_H
#define TOKEN_TYPES_H

enum class TokenType
{
    NUMBER,
    WORD,
    VARIABLE,
    PREPROCESSOR_COMMAND,
    PREPROCESSOR_VALUE,
    PREPROCESSOR_NAME,

    OPERATOR_ADD,
    OPERATOR_SUB,
    OPERATOR_MUL,
    OPERATOR_DIV,
    OPERATOR_ASSIG,

    SUBEXPR_BEGIN,
    SUBEXPR_END,

    END_OF_FILE
};

[[maybe_unused]]
inline static std::ostream& operator <<(std::ostream& out, const TokenType& token_type)
{
    const char* token_type_str
    {
        token_type == TokenType::NUMBER                 ? "TokenType::NUMBER" :
        token_type == TokenType::WORD                   ? "TokenType::WORD" :
        token_type == TokenType::VARIABLE               ? "TokenType::VARIABLE" :
        token_type == TokenType::PREPROCESSOR_COMMAND   ? "TokenType::PREPROCESSOR_COMMAND" :
        token_type == TokenType::PREPROCESSOR_VALUE     ? "TokenType::PREPROCESSOR_VALUE" :
        token_type == TokenType::PREPROCESSOR_NAME      ? "TokenType::PREPROCESSOR_NAME" :

        token_type == TokenType::OPERATOR_ADD           ? "TokenType::OPERATOR_ADD" :
        token_type == TokenType::OPERATOR_SUB           ? "TokenType::OPERATOR_SUB" :
        token_type == TokenType::OPERATOR_MUL           ? "TokenType::OPERATOR_MUL" :
        token_type == TokenType::OPERATOR_DIV           ? "TokenType::OPERATOR_DIV" :
        token_type == TokenType::OPERATOR_ASSIG         ? "TokenType::OPERATOR_ASSIG" :

        token_type == TokenType::SUBEXPR_BEGIN          ? "TokenType::SUBEXPR_BEGIN" :
        token_type == TokenType::SUBEXPR_END            ? "TokenType::SUBEXPR_END" :
        token_type == TokenType::END_OF_FILE            ? "TokenType::SUBEXPR_END" :
                                                          "UNKNOWN"
    };
    return (out << token_type_str);
}

#endif // TOKEN_TYPES_H
