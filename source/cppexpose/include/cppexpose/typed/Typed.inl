
#pragma once


#include <typeinfo>

#include <cppexpose/variant/Variant.hh>


namespace
{


template <typename T>
struct VariantConversionHelper
{
    template <typename BASE>
    static cppexpose::Variant toVariant(const cppexpose::Typed<T, BASE> * typed)
    {
        return cppexpose::Variant::fromValue<T>(typed->value());
    }

    template <typename BASE>
    static void fromVariant(cppexpose::Typed<T, BASE> * typed, const cppexpose::Variant & variant)
    {
        typed->setValue(variant.value<T>());
    }
};

template <>
struct VariantConversionHelper<cppexpose::Variant>
{
    template <typename BASE>
    static cppexpose::Variant toVariant(const cppexpose::Typed<cppexpose::Variant, BASE> * typed)
    {
        return typed->value();
    }

    template <typename BASE>
    static void fromVariant(cppexpose::Typed<cppexpose::Variant, BASE> * typed, const cppexpose::Variant & variant)
    {
        typed->setValue(variant);
    }
};


} // namespace


namespace cppexpose
{


template <typename T, typename BASE>
Typed<T, BASE>::Typed()
{
}

template <typename T, typename BASE>
Typed<T, BASE>::Typed(const Variant & options)
: BASE(options)
{
}

template <typename T, typename BASE>
Typed<T, BASE>::~Typed()
{
}

template <typename T, typename BASE>
const std::type_info & Typed<T, BASE>::type() const
{
    return typeid(T);
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isReadOnly() const
{
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isComposite() const
{
    return false;
}

template <typename T, typename BASE>
size_t Typed<T, BASE>::numSubValues() const
{
    return 0;
}

template <typename T, typename BASE>
AbstractTyped * Typed<T, BASE>::subValue(size_t)
{
    return nullptr;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isEnum() const
{
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isArray() const
{
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isVariant() const
{
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isString() const
{
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isBool() const
{
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isNumber() const
{
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isIntegral() const
{
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isSignedIntegral() const
{
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isUnsignedIntegral() const
{
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::isFloatingPoint() const
{
    return false;
}

template <typename T, typename BASE>
Variant Typed<T, BASE>::toVariant() const
{
    return VariantConversionHelper<T>::toVariant(this);
}

template <typename T, typename BASE>
bool Typed<T, BASE>::fromVariant(const Variant & variant)
{
    VariantConversionHelper<T>::fromVariant(this, variant);
    return true;
}

template <typename T, typename BASE>
std::string Typed<T, BASE>::toString() const
{
    // Unsupported for unknown types
    return "";
}

template <typename T, typename BASE>
bool Typed<T, BASE>::fromString(const std::string &)
{
    // Unsupported for unknown types
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::toBool() const
{
    // Unsupported for unknown types
    return false;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::fromBool(bool)
{
    // Unsupported for unknown types
    return false;
}

template <typename T, typename BASE>
long long Typed<T, BASE>::toLongLong() const
{
    // Unsupported for unknown types
    return 0ll;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::fromLongLong(long long)
{
    // Unsupported for unknown types
    return false;
}

template <typename T, typename BASE>
unsigned long long Typed<T, BASE>::toULongLong() const
{
    // Unsupported for unknown types
    return 0ull;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::fromULongLong(unsigned long long)
{
    // Unsupported for unknown types
    return false;
}

template <typename T, typename BASE>
double Typed<T, BASE>::toDouble() const
{
    // Unsupported for unknown types
    return 0.0;
}

template <typename T, typename BASE>
bool Typed<T, BASE>::fromDouble(double)
{
    // Unsupported for unknown types
    return false;
}

template <typename T, typename BASE>
void Typed<T, BASE>::onValueChanged(const T &)
{
    // To be implemented in derived classes
}


} // namespace cppexpose
