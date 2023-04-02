#pragma once

#include "Weather.h"
#include "Car.h"
#include <vector>

class Circuit {
public:
    Circuit(double length, Weather condition);

    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
    void SetLength(double length);
    void SetWeather(Weather w);

private:
    double length;
    Weather condition;
    std::vector<Car*> cars;
    std::vector<std::pair<Car*, int>> car_times;
    std::vector<Car*> cars_that_did_not_finish;
};
