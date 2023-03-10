#include "Math.h"
#include <cstring>
#include <cstdarg>

int Math::Add(int x, int y) {
    return x + y;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

double Math::Add(double d, double f) {
    return d + f;
}

double Math::Add(double g, double h, double i) {
    return g * h * i;
}

int Math::Mul(int j, int k) {
    return j * k;
}

int Math::Mul(int l, int m, int n) {
    return l * m * n;
}

double Math::Mul(double o, double p) {
    return o * p;
}

double Math::Mul(double q, double r, double s) {
    return q * r * s;
}

int Math::Add(int count, ...) {
    va_list list;
    va_start(list, count);
   
    int sum = 0;

    for (int i = 0; i < count; ++i) {
        int t = va_arg(list, int);
        sum += t;
    }

    va_end(list);
    return sum;
}

char* Math::Add(const char* u, const char* v) {
    char* w = new char[strlen(u) + strlen(v) + 1];
    strcpy(w, v);
    strcat(w, u);
    return w;
}

