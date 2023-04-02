#pragma once
#include "Car.h"
#include <string>
class Volvo : public Car {
public:
    Volvo();
    virtual float GetSpeed(Weather w);
    virtual float GetTotalFuel();
    virtual float GetFuelConsumption(Weather w);
    virtual std::string GetName();

private:
    float speed;
    float total_fuel;
    float fuel_consumption;
    std::string name;
};
