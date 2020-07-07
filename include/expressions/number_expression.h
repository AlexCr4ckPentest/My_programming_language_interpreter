#include "abstract_expression.h"

#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

namespace Expressions
{

class NumberExpression : public AbstractExpression
{
public:
    inline NumberExpression(const long double value) noexcept
        : m_value {value}
    {}

    NumberExpression(const NumberExpression&) = delete;
    NumberExpression& operator =(const NumberExpression&) = delete;

    inline long double eval() const noexcept override
    { return m_value; }

private:
    const long double m_value {};
};

} // namespace Expressions

#endif // NUMBER_EXPRESSION_H
