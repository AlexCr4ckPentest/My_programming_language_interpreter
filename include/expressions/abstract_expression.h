#include <memory>

#ifndef ABSTRACT_EXPRESSION_H
#define ABSTRACT_EXPRESSION_H

namespace Expressions
{

class AbstractExpression
{
public:
    virtual long double eval() const noexcept = 0;
};

namespace __detail
{

using AbstractExpressionPtr = std::shared_ptr<AbstractExpression>;

} // namespace __detail

} // namespace Expressions

#endif // ABSTRACT_EXPRESSION_H
