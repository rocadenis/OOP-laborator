#include "sort.h"
#include <algorithm>
#include <iostream>
#include <sstream>

Sort::Sort() {}

//1 
Sort::Sort(int count, int min_val, int max_val) {
    for (int i = 0; i < count; i++) {
        int random_val = rand() % (max_val - min_val + 1) + min_val;
        elements.push_back(random_val);
    }
}
//2
Sort::Sort(std::initializer_list<int> list) {
    for (auto& element : list) {
        elements.push_back(element);
    }
}
//3
Sort::Sort(std::vector<int> vec, int count) {
    for (int i = 0; i < count; i++) {
        elements.push_back(vec[i]);
    }
}
//4
Sort::Sort(int count, ...) {
        va_list args;
        va_start(args, count);
        for (int i = 0; i < count; i++) {
            int value = va_arg(args, int);
            elements.push_back(value);
        }
        va_end(args);
    }
//5
Sort::Sort(const char* str) {
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, ',')) {
        int val = stoi(token);
        elements.push_back(val);
    }
}

void Sort::InsertSort(bool ascendent) {
    if (ascendent) {
        std::sort(elements.begin(), elements.end());
    }
    else {
        std::sort(elements.begin(), elements.end(), std::greater<int>());
    }
}

void Sort::QuickSort(bool ascendent) {
    if (ascendent) {
        std::sort(elements.begin(), elements.end());
    }
    else {
        std::sort(elements.begin(), elements.end(), std::greater<int>());
    }
}

void Sort::BubbleSort(bool ascendent) {
    int n = elements.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; i++) {
            if ((ascendent && elements[i - 1] > elements[i]) || (!ascendent && elements[i - 1] < elements[i])) {
                std::swap(elements[i - 1], elements[i]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);
}

void Sort::Print() {
    for (auto& element : elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int Sort::GetElementsCount() {
    return elements.size();
}

int Sort::GetElementFromIndex(int index) {
    return elements[index];
}
