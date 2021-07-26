#include "cars.h"
#include <iostream>

//======================================================================================================
// Реализация методов class  Car
//------------------------------------------------------------------------------------------------------

Car::Car(std::string company, std::string model): m_company(company), m_model(model)
{
    std::cout << "Car" << std::endl;
}

Car::~Car() {}

//======================================================================================================
// Реализация методов class  PassengerCar
//------------------------------------------------------------------------------------------------------

PassengerCar::PassengerCar(std::string company, std::string model, std::string body) : Car(company, model), m_body(body)
{
    std::cout << "PassengerCar" << std::endl;
}

PassengerCar::~PassengerCar() {}

//======================================================================================================
// Реализация методов class  Bus
//------------------------------------------------------------------------------------------------------

Bus::Bus(std::string company, std::string model, int capacity) : Car(company, model), m_capacity(capacity)
{
    std::cout << "Bus" << std::endl;
}

Bus::~Bus() {}

//======================================================================================================
// Реализация методов class  Minivan
//------------------------------------------------------------------------------------------------------

Minivan::Minivan(std::string company, std::string model, std::string body, int capacity) : Bus(company, model, capacity), PassengerCar(company, model, body), Car(company, model)
{
    std::cout << "Minivan" << std::endl;
}

Minivan::~Minivan() {}