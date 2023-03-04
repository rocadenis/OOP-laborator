#pragma once
#include <string>
//#include "Student.cpp"
class Student 
{
    int result;
    std::string name;
    float mathgrade;
    float englishgrade;
    float historygrade;
public:
    void SetName(const std::string& name);
    std::string GetName() const;
    
    void SetMathGrade(float grade);
    float GetMathGrade() const;
    
    void SetEnglishGrade(float grade);
    float GetEnglishGrade() const;
    
    void SetHistoryGrade(float grade);
    float GetHistoryGrade() const;
    
    float GetAverageGrade() const;
};
