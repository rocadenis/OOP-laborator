#ifndef SORT_H
#define SORT_H
//sau #pragma once (evita includerea de fisiere header multiple sau redefinirea)

#include <vector>

class Sort {
private:
    std::vector<int> elements;

public:
    Sort();
    Sort(int count, int min_val, int max_val);
    Sort(std::initializer_list<int> list);
    Sort(std::vector<int> vec, int count);
    Sort(int count, ...);
    Sort(const char* str);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};

#endif
