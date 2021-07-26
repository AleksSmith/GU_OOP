#ifndef CARS_H
#define CARS_H

#include <string>

class Car
{
private:
    std::string m_company;
    std::string m_model;

public:
    Car(std::string company, std::string model);
    ~Car();
};



class PassengerCar : virtual public Car
{
private:
    std::string m_body;

public:
    PassengerCar(std::string company, std::string model, std::string body);
    ~PassengerCar();
};



class Bus : virtual public Car
{
private:
    int m_capacity;

public:
    Bus(std::string company, std::string model, int capacity);
    ~Bus();
};



class Minivan : public PassengerCar, public Bus
{
public:
    Minivan(std::string company, std::string model, std::string body, int capacity);
    ~Minivan();
};

#endif