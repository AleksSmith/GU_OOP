#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>


class Fraction
{
private:
    int m_num;
    int m_den;

public:
    Fraction(int num);
    Fraction(int num, int den);
    static int gcd(int a, int b);
    Fraction reduce();
    friend std::ostream& operator<<(std::ostream &out, const Fraction &frct);
    friend Fraction operator*(const Fraction &frct_1, const Fraction &frct_2);
    friend Fraction operator*(const Fraction &frct, int n);
    friend Fraction operator*(int n, const Fraction &frct);
    friend Fraction operator/(const Fraction &frct_1, const Fraction &frct_2);
    friend Fraction operator/(const Fraction &frct, int n);
    friend Fraction operator/(int n, const Fraction &frct);
    friend Fraction operator+(const Fraction &frct_1, const Fraction &frct_2);
    friend Fraction operator+(const Fraction &frct, int n);
    friend Fraction operator+(int n, const Fraction &frct);
    friend Fraction operator-(const Fraction &frct_1, const Fraction &frct_2);
    friend Fraction operator-(const Fraction &frct, int n);
    friend Fraction operator-(int n, const Fraction &frct);
    
    //... Пока доделать не успел

    ~Fraction();
   
};


#endif