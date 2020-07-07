#include "abstract_expression.h"

#include <memory>

#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H

class UnaryExpression : public AbstractExpression
{
public:
    inline UnaryExpression(const std::shared_ptr<AbstractExpression> right_expression,
                           const char operation) noexcept
        : m_right_expression {right_expression}
        , m_operation {operation}
    {}

    inline long double eval() const noexcept override
    { return (m_operation == '-' ? -m_right_expression->eval() : m_right_expression->eval()); }

private:
    const std::shared_ptr<AbstractExpression> m_right_expression {};
    const char m_operation {};
};

#endif // UNARY_EXPRESSION_H
