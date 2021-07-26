#include "fraction.h"
#include <cassert>


//======================================================================================================
// Реализация методов class Fraction
//------------------------------------------------------------------------------------------------------

Fraction::Fraction(int num = 0) : m_num(num){ m_den = 1;}

Fraction::Fraction(int num, int den = 1) : m_num(num), m_den(den)
{
    assert(den && "Denominator = 0!");
    if (den < 0)
    {
        m_den = -den;
        m_num = -num;
    }
    reduce();
}


int Fraction::gcd(int a, int b)
{
    return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
}


Fraction Fraction::reduce()
{
    int i_gcd = Fraction::gcd(m_num, m_den);
    m_num /= i_gcd;
    m_den /= i_gcd;
}


//======================================================================================================
// Реализация friend функций class Fraction
//------------------------------------------------------------------------------------------------------

Fraction::~Fraction() {}


std::ostream& operator<< (std::ostream &out, const Fraction &frct)
{
    if (frct.m_den == 1)
        std::cout << frct.m_num;
    else
        std::cout << frct.m_num << "/" << frct.m_den;
}


Fraction operator*(const Fraction &frct_1, const Fraction &frct_2)
{
    return Fraction(frct_1.m_num * frct_2.m_num, frct_1.m_den * frct_2.m_den);
}


Fraction operator*(const Fraction &frct, int n)
{
    return Fraction(frct.m_num * n, frct.m_den);
}


Fraction operator*(int n, const Fraction &frct)
{
    return Fraction(frct.m_num * n, frct.m_den);
}


Fraction operator/(const Fraction &frct_1, const Fraction &frct_2)
{
    return Fraction(frct_1.m_num * frct_2.m_den, frct_1.m_den * frct_2.m_num);
}


Fraction operator/(const Fraction &frct, int n)
{
    return Fraction(frct.m_num, frct.m_den * n);
}

Fraction operator/(int n, const Fraction &frct)
{
    return Fraction(n * frct.m_den, frct.m_num);
}


Fraction operator+(const Fraction &frct_1, const Fraction &frct_2)
{
    return Fraction(frct_1.m_num * frct_2.m_den + frct_2.m_num * frct_1.m_den, frct_1.m_den * frct_2.m_den);
}


Fraction operator+(const Fraction &frct, int n)
{
    return Fraction(frct.m_num + n * frct.m_den, frct.m_den);
}


Fraction operator+(int n, const Fraction &frct)
{
    return Fraction(frct.m_num + n * frct.m_den, frct.m_den);
}


Fraction operator-(const Fraction &frct_1, const Fraction &frct_2)
{
    return Fraction(frct_1.m_num * frct_2.m_den - frct_2.m_num * frct_1.m_den, frct_1.m_den * frct_2.m_den);
}


Fraction operator-(const Fraction &frct, int n)
{
    return Fraction(frct.m_num - n * frct.m_den, frct.m_den);
}


Fraction operator-(int n, const Fraction &frct)
{
    return Fraction(n * frct.m_den - frct.m_num, frct.m_den);
}