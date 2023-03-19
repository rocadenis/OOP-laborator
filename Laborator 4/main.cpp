#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
#include <iostream>

int main() {

    Sort s1(4, 8, 27); // constructor with random values
    s1.BubbleSort(true);
    s1.Print();

    Sort s2{ 6,3,7,10 }; // constructor with initializer list
    s2.QuickSort(false);
    s2.Print();

    Sort s3(4 ,2,5,4 ,1);//constructor with existing vector
    s3.InsertSort(false);
    s3.Print();

    Sort s4(4, 3, 4 ,2, 2);// constructor with va_args
    s4.BubbleSort(true);
    s4.Print();

    Sort s5("10,40,100,5,70"); // constructor with string
    s5.InsertSort(true);
    s5.Print();
    printf("%d", s5.GetElementFromIndex(3));
    return 0;
}
