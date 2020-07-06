#include "abstract_expression.h"

#include <memory>

#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H

class BinaryExpression : public AbstractExpression
{
public:
    inline BinaryExpression(const std::shared_ptr<AbstractExpression>& left_expression,
                            const std::shared_ptr<AbstractExpression>& right_expression,
                            const char operation) noexcept
        : m_left_expression {left_expression}
        , m_right_expression {right_expression}
        , m_operation {operation}
    {}

    inline long double eval() const noexcept override
    {
        return (
            m_operation == '+' ? m_left_expression->eval() + m_right_expression->eval() :
            m_operation == '-' ? m_left_expression->eval() - m_right_expression->eval() :
            m_operation == '*' ? m_left_expression->eval() * m_right_expression->eval() :
            m_operation == '/' ? m_left_expression->eval() / m_right_expression->eval() : 0
        );
    }

private:
    const std::shared_ptr<AbstractExpression> m_left_expression {};
    const std::shared_ptr<AbstractExpression> m_right_expression {};
    const char m_operation {};
};

#endif // BINARY_EXPRESSION_H
