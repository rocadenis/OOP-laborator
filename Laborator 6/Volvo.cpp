#include "Volvo.h"

Volvo::Volvo() {
    speed = 180;
    total_fuel = 90;
    fuel_consumption = 10;
    name = "Volvo";
}

float Volvo::GetSpeed(Weather w) {
    switch (w) {
        case Weather::Sunny:
            return speed;
        case Weather::Rainy:
            return speed * 0.8;
        case Weather::Snowy:
            return speed * 0.6;
        default:
            return speed;
    }
}

float Volvo::GetTotalFuel() {
    return total_fuel;
}

float Volvo::GetFuelConsumption(Weather w) {
    switch (w) {
        case Weather::Sunny:
            return fuel_consumption;
        case Weather::Rainy:
            return fuel_consumption * 1.1;
        case Weather::Snowy:
            return fuel_consumption * 1.4;
        default:
            return fuel_consumption;
    }
}

std::string Volvo::GetName() {
    return name;
}
