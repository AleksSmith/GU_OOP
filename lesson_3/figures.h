#ifndef FIGURES_H
#define FIGURES_H


class Figure
{
public:
    virtual double area() = 0;
};

class Parallelogram : public Figure
{
private:
    double m_a;
    double m_b;
    double m_alpha;

public:
    Parallelogram(double a, double b, double alpha);
    ~Parallelogram();
    double getA() const;
    double getB() const;
    double getAlpha() const;
    void setAlpha(double alpha);
    double area() override;
};



class Circle : public Figure
{
private:
    double m_rds;

public:
    Circle(double r);
    ~Circle();
    double area() override;
};



class Rectangle : public Parallelogram
{
public:
    Rectangle(int a, int b);
    ~Rectangle();
    double area() override;
};



class Square : public Parallelogram
{
public:
    Square(double a);
    ~Square();
    double area() override;
};



class Rhombus : public Parallelogram
{
public:
    Rhombus(double a, double alpha);
    ~Rhombus();
};



void printArea(Figure &fig);

#endif