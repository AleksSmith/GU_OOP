#include <string>
#include "classes.h"
//==============================================================
// Реализация методов class Person
//--------------------------------------------------------------

Person::Person(std::string name = "none", int age = 0, std::string sex = "none", int weight = 0) : m_name(name), m_age(age), m_sex(sex), m_weight(weight){};

void Person::setName(std::string name) { m_name = name; }

std::string Person::getName() const { return m_name; }

void Person::setAge(int age) { m_age = age; }

int Person::getAge() const { return m_age; }

void Person::setSex(std::string sex) { m_sex = sex; }

std::string Person::getSex() const { return m_sex; }

void Person::setWeight(int weight) { m_weight = weight; }

int Person::getWeight() const { return m_weight; }

Person::~Person() {}

//==============================================================
// Реализация методов class Student
//--------------------------------------------------------------

Student::Student(std::string name, int y_begin, int y_end) : Person(name), begin_year(y_begin), end_year(y_end)
{
    if (y_begin >= y_end)
    { // Если год начала больше года окончания меняем их местами
        begin_year = y_end;
        end_year = y_begin;
    }
    students++;
}

void Student::setYearsOfStudies(int y_begin, int y_end)
{
    if (y_begin >= y_end)
    { // Если год начала больше года окончания меняем их местами
        begin_year = y_end;
        end_year = y_begin;
    }
    else
    {
        begin_year = y_begin;
        end_year = y_end;
    }
}

int Student::getBeginOfStudy() const { return begin_year; }

int Student::getEndOfStudy() const { return end_year; }

void Student::extension() { end_year++; } // Метод увеличения года окончания на 1

Student::~Student() { students--; }

//==============================================================
// Реализация методов class Fruit
//--------------------------------------------------------------

Fruit::Fruit(std::string name = "none", std::string color = "none") : m_name(name), m_color(color) {}

std::string Fruit::getName() const { return m_name; }

std::string Fruit::getColor() const { return m_color; }

Fruit::~Fruit() {}

//==============================================================
// Реализация методов class Apple
//--------------------------------------------------------------

Apple::Apple() : Fruit("apple", "green") {}

Apple::Apple(const std::string &color) : Fruit("apple", color) {}

Apple::~Apple() {}

//==============================================================
// Реализация методов class Banana
//--------------------------------------------------------------

Banana::Banana() : Fruit("banana", "yellow") {}

Banana::Banana(const std::string &color) : Fruit("banana", color) {}

Banana::~Banana() {}

//==============================================================
// Реализация методов class GrannySmith
//--------------------------------------------------------------

GrannySmith::GrannySmith() : Apple(), m_sort("GrannySmith") {}

GrannySmith::~GrannySmith() {}

std::string GrannySmith::getName() const { return (m_sort + " " + m_name); }