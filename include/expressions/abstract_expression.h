#ifndef ABSTRACT_EXPRESSION_H
#define ABSTRACT_EXPRESSION_H

class AbstractExpression
{
public:
    virtual long double eval() const noexcept = 0;
};

#endif // ABSTRACT_EXPRESSION_H
