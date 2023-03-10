#pragma once
#include <cstdarg>

class Math
{
public:
    static int Add(int x, int y);
    static int Add(int a, int b, int c);
    static double Add(double d, double f);
    static double Add(double g, double h, double i);
    static int Mul(int j, int k);
    static int Mul(int l, int m, int n);
    static double Mul(double o, double p);
    static double Mul(double q, double r, double s);
    static int Add(int count, ...); // sums up a list of integers
    static char* Add(const char* u, const char* v);
};
