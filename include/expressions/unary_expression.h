#include "abstract_expression.h"

#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H

namespace Expressions
{

class UnaryExpression : public AbstractExpression
{

using AbstractExpressionPtr = __detail::AbstractExpressionPtr;

public:
    inline UnaryExpression(const AbstractExpressionPtr& right_expression,
                           const char operation) noexcept
        : m_right_expression {right_expression}
        , m_operation {operation}
    {}

    UnaryExpression(const UnaryExpression&) = delete;
    UnaryExpression& operator =(const UnaryExpression&) = delete;

    inline long double eval() const noexcept override
    { return (m_operation == '-' ? -(m_right_expression->eval()) : m_right_expression->eval()); }

private:
    const AbstractExpressionPtr m_right_expression {};
    const char m_operation {};
};

} // namespace Expressions

#endif // UNARY_EXPRESSION_H
