#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

#include "NumberList.cpp"

int main()
{ 
    NumberList numbers;
    numbers.Init();
    numbers.Add(3);
    numbers.Add(5);
    numbers.Init();
    numbers.Add(6);
    numbers.Add(9);
    numbers.Add(2);
    numbers.Sort();
    numbers.Print();
}