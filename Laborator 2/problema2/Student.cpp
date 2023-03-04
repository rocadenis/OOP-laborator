// Student.cpp
#include "Student.h"
#include <algorithm>
int result;
void Student::SetName(const std::string& name) {
    this->name = name;
}

std::string Student::GetName() const {
    return name;
}

void Student::SetMathGrade(float grade) {
    if(grade<=10 && grade>=1)
    mathgrade=grade;
}

float Student::GetMathGrade() const {
    return mathgrade;
}

void Student::SetEnglishGrade(float grade) {
   if(grade<=10 && grade>=1)
   englishgrade = grade;
}

float Student::GetEnglishGrade() const {
    return englishgrade;
}

void Student::SetHistoryGrade(float grade) {
    if(grade<=10 && grade>=1)
    historygrade =grade;
}

float Student::GetHistoryGrade() const {
    return historygrade;
}

float Student::GetAverageGrade() const {
    return (historygrade + englishgrade + mathgrade) / 3;
}