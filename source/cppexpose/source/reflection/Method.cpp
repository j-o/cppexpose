
#include <cppexpose/reflection/Method.h>

#include <cppexpose/function/AbstractFunction.h>


namespace cppexpose
{


Method::Method(AbstractFunction * func, PropertyGroup * parent)
: Function(func)
, m_name("")
, m_parent(parent)
{
}

Method::Method(const std::string & name, AbstractFunction * func, PropertyGroup * parent)
: Function(func)
, m_name(name)
, m_parent(parent)
{
}

Method::~Method()
{
}

std::string Method::name() const
{
    return m_name;
}

PropertyGroup * Method::parent() const
{
    return m_parent;
}


} // namespace cppexpose
