#include <cstdio>

float operator""_Kelvin(unsigned long long a) {
    return  a - 273.15;
}

float operator""_Fahrenheit(unsigned long long b) {
    unsigned long long x=(b - 32)/ 1.8;
    return x;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    printf("%f\n", a);
    printf("%f\n", b);
    return 0;
}