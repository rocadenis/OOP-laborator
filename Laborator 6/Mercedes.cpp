#include "Mercedes.h"

Mercedes::Mercedes() {
    speed = 210;
    total_fuel = 70;
    fuel_consumption = 8.4;
    name = "Merceds";
}

float Mercedes::GetSpeed(Weather w) {
    switch (w) {
        case Weather::Sunny:
            return speed;
        case Weather::Rainy:
            return speed * 0.8;
        case Weather::Snowy:
            return speed * 0.55;
        default:
            return speed;
    }
}

float Mercedes::GetTotalFuel() {
    return total_fuel;
}

float Mercedes::GetFuelConsumption(Weather w) {
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

std::string Mercedes::GetName() {
    return name;
}
