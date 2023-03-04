//#include "Student.h"
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include "CompareStudents.h"
void CompNames(const Student& s1, const Student& s2) {
    int result = (s1.GetName().compare(s2.GetName()));
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

void CompMathGrades(const Student& s1, const Student& s2) {
    float diff = s1.GetMathGrade() - s2.GetMathGrade();
    int result=(diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
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
void CompEngGrades(const Student& s1, const Student& s2) {
    float diff = s1.GetEnglishGrade() - s2.GetEnglishGrade();
    int result= (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
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
void CompHistGrades(const Student& s1, const Student& s2) {
    float diff = s1.GetHistoryGrade() - s2.GetHistoryGrade();
    int result= (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
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
void CompAverages(const Student& s1, const Student& s2) {
    float diff = s1.GetAverageGrade() - s2.GetAverageGrade();
    int result=0;
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