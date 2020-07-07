#include "abstract_expression.h"

#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H

namespace Expressions
{

class BinaryExpression : public AbstractExpression
{
    using AbstractExpressionPtr = __detail::AbstractExpressionPtr;

public:
    inline BinaryExpression(const AbstractExpressionPtr& left_expression,
                            const AbstractExpressionPtr& right_expression,
                            const char operation) noexcept
        : m_left_expression {left_expression}
        , m_right_expression {right_expression}
        , m_operation {operation}
    {}

    BinaryExpression(const BinaryExpression&) = delete;
    BinaryExpression& operator =(const BinaryExpression&) = delete;

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
    const AbstractExpressionPtr m_left_expression {};
    const AbstractExpressionPtr m_right_expression {};
    const char m_operation {};
};

} // namespace Expressions

#endif // BINARY_EXPRESSION_H
