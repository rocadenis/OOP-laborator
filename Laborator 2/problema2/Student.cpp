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

void CompareNames(const Student& s1, const Student& s2) {
    result = (s1.GetName().compare(s2.GetName()));
    if (result == 0)
    {
        printf("\nThe students have the same name\n");
    }
    else if (result < 0)
    {
        printf("\n%s comes before %s alphabetically\n", s1.GetName().c_str(), s2.GetName().c_str());
    }
    else
    {
        printf("\n%s comes before %s alphabetically\n", s2.GetName().c_str(), s1.GetName().c_str());
    }
}

void CompareMathGrades(const Student& s1, const Student& s2) {
    float diff = s1.GetMathGrade() - s2.GetMathGrade();
    result=(diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
    if (result == 0)
    {
        printf("\nThe students have the same Math grade\n");
    }
    else if (result == 1)
    {
        printf("\n%s has a higher Math grade than %s\n", s1.GetName().c_str(), s2.GetName().c_str());
    }
    else
    {
        printf("\n%s has a higher Math grade than %s\n", s2.GetName().c_str(), s1.GetName().c_str());
    }
}
void CompareEngGrades(const Student& s1, const Student& s2) {
    float diff = s1.GetEnglishGrade() - s2.GetEnglishGrade();
    result= (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
    if (result == 0)
    {
        printf("\nThe students have the same English grade\n");
    }
    else if (result == 1)
    {
        printf("\n%s has a higher English grade than %s\n", s1.GetName().c_str(), s2.GetName().c_str());
    }
    else
    {
        printf("\n%s has a higher English grade than %s\n", s2.GetName().c_str(), s1.GetName().c_str());
    }

}
void CompareHistGrades(const Student& s1, const Student& s2) {
    float diff = s1.GetHistoryGrade() - s2.GetHistoryGrade();
    result= (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
    if (result == 0)
    {
        printf("\nThe students have the same History grade\n");
    }
    else if (result == 1)
    {
        printf("\n%s has a higher History grade than %s\n", s1.GetName().c_str(), s2.GetName().c_str());
    }
    else
    {
        printf("\n%s has a higher History grade than %s\n", s2.GetName().c_str(), s1.GetName().c_str());
    }
}
void CompareAverages(const Student& s1, const Student& s2) {
    float diff = s1.GetAverageGrade() - s2.GetAverageGrade();
    result=0;
    if (diff != 0) {
        result= ((diff > 0) ? 1 : -1);
    }
    if (result == 0)
    {
        printf("\nThe students have the same average grade\n");
    }
    else if (result == 1)
    {
        printf("\n%s has a higher average grade than %s\n", s1.GetName().c_str(), s2.GetName().c_str());
    }
    else
    {
        printf("\n%s has a higher average grade than %s\n", s2.GetName().c_str(), s1.GetName().c_str());
    }}