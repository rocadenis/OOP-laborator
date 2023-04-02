#include "BMW.h"

BMW::BMW() {
    speed = 230;
    total_fuel = 65;
    fuel_consumption = 13;
    name = "BMW";
}

float BMW::GetSpeed(Weather w) {
    switch (w) {
        case Weather::Sunny:
            return speed;
        case Weather::Rainy:
            return speed * 0.7;
        case Weather::Snowy:
            return speed * 0.3;
        default:
            return speed;
    }
}

float BMW::GetTotalFuel() {
    return total_fuel;
}

float BMW::GetFuelConsumption(Weather w) {
    switch (w) {
        case Weather::Sunny:
            return fuel_consumption;
        case Weather::Rainy:
            return fuel_consumption * 1.2;
        case Weather::Snowy:
            return fuel_consumption * 1.5;
        default:
            return fuel_consumption;
    }
}

std::string BMW::GetName() {
    return name;
}
