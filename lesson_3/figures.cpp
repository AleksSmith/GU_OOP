#include "figures.h"
#include <cmath>
#include <iostream>

#define _USE_MATH_DEFINES

//======================================================================================================
// Реализация методов class  Parallelogram
//------------------------------------------------------------------------------------------------------

Parallelogram::Parallelogram(double a, double b = 0, double alpha = 90) : m_a(a), m_b(b), m_alpha(alpha)
{
    if (!b)
        m_b = a;
};

Parallelogram::~Parallelogram() {}

double Parallelogram::getA() const { return m_a; }

double Parallelogram::getB() const { return m_b; }

double Parallelogram::getAlpha() const { return m_alpha; }

void Parallelogram::setAlpha(double alpha) { m_alpha = alpha; }

double Parallelogram::area() { return m_a * m_b * std::sin(m_alpha); }

//======================================================================================================
// Реализация методов class  Circle
//------------------------------------------------------------------------------------------------------

Circle::Circle(double r) : m_rds(r) {}

Circle::~Circle() {}

double Circle::area() { return (double)M_PI * (pow(m_rds, 2)); }

//======================================================================================================
// Реализация методов class  Rectangle
//------------------------------------------------------------------------------------------------------

Rectangle::Rectangle(int a, int b) : Parallelogram(a, b){};

Rectangle::~Rectangle(){};

double Rectangle::area() { return Parallelogram::getA() * Parallelogram::getB(); }

//======================================================================================================
// Реализация методов class  Square
//------------------------------------------------------------------------------------------------------

Square::Square(double a) : Parallelogram(a) {}

Square::~Square() {}

double Square::area() { return Parallelogram::getA() * Parallelogram::getA(); }

//======================================================================================================
// Реализация методов class  Rhombus
//------------------------------------------------------------------------------------------------------

Rhombus::Rhombus(double a, double alpha) : Parallelogram(a)
{
    Parallelogram::setAlpha(alpha);
}

Rhombus::~Rhombus() {}

//======================================================================================================
// Реализация функций
//------------------------------------------------------------------------------------------------------

void printArea(Figure &fig)
{
    std::cout << "Area of figure = " << fig.area() << std::endl;
}