#include "abstract_expression.h"

#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

class NumberExpression : public AbstractExpression
{
public:
    inline NumberExpression(const long double value) noexcept
        : m_value {value}
    {}

    inline long double eval() const noexcept override
    { return m_value; }

private:
    const long double m_value {};
};

#endif // NUMBER_EXPRESSION_H
