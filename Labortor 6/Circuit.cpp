#include "Circuit.h"
#include <vector>
#include <stdio.h>
#include <math.h>
#include "Car.h"
#include "Weather.h"
#include <iostream>
#include <algorithm>

Circuit::Circuit(double length, Weather condition) {
    this->length = length;
    this->condition = condition;
}

void Circuit::SetLength(double length) {
    this->length = length;
}

void Circuit::SetWeather(Weather w) {
    this->condition = w;
}

void Circuit::AddCar(Car* car) {
    cars.push_back(car);
}

void Circuit::Race() {
    for (Car* car : cars) {
        int fuel_needed = length * car->GetFuelConsumption(condition);
        if (fuel_needed <= car->GetTotalFuel()) {
            int time = length / car->GetSpeed(condition);
            car_times.push_back(std::make_pair(car, time));
        }
        else {
            cars_that_did_not_finish.push_back(car);
        }
    }
    std::sort(car_times.begin(), car_times.end(), [](const auto& p1, const auto& p2) {
        return p1.second < p2.second;
    });
}

void Circuit::ShowFinalRanks() {
    for (auto& p : car_times) {
        std::cout << p.first->GetName() << " finished in " << p.second << " seconds." << std::endl;
    }
}

void Circuit::ShowWhoDidNotFinish() {
    std::cout << "The following cars did not finish the race:" << std::endl;
    for (Car* car : cars_that_did_not_finish) {
        std::cout << car->GetName() << std::endl;
    }
}
