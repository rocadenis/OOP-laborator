#include "Audi.h"

Audi::Audi() {
    speed = 220;
    total_fuel = 70;
    fuel_consumption = 9.3;
    name = "Audi";
}

float Audi::GetSpeed(Weather w) {
    switch (w) {
        case Weather::Sunny:
            return speed;
        case Weather::Rainy:
            return speed * 0.75;
        case Weather::Snowy:
            return speed * 0.5;
        default:
            return speed;
    }
}

float Audi::GetTotalFuel() {
    return total_fuel;
}

float Audi::GetFuelConsumption(Weather w) {
    switch (w) {
        case Weather::Sunny:
            return fuel_consumption;
        case Weather::Rainy:
            return fuel_consumption * 1.15;
        case Weather::Snowy:
            return fuel_consumption * 1.5;
        default:
            return fuel_consumption;
    }
}

std::string Audi::GetName() {
    return name;
}
