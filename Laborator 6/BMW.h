#pragma once
#include <string>
#include "Car.h"

class BMW : public Car {
public:
    BMW();
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
