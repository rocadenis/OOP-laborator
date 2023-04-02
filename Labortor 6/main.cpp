#define CRT_SECURE_NO_WARNINGS
#include "Circuit.h"
#include "Car.h"
#include "BMW.h"
#include "Mercedes.h"
#include "Audi.h"
#include "Volvo.h"
#include <iostream>

int main()
{
   Circuit c(7,Weather::Rainy);
   c.AddCar(new Volvo());
   c.AddCar(new BMW());
   c.AddCar(new Mercedes);
   c.Race();
   c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
   //c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
   return 0;
}