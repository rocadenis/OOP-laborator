#pragma once

#include "Weather.h"
#include <string>


class Car {
public:
    virtual float GetSpeed(Weather w) = 0;
    virtual float GetTotalFuel() = 0;
    virtual float GetFuelConsumption(Weather w) = 0;
    virtual  std::string GetName() = 0;
    virtual ~Car() {}
};
