#include "Student.cpp"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Create two students
    Student s1;
    Student s2;
    s1.SetName("Bulai Ioan");
    s2.SetName("Dumitru Ioan");
    s1.SetEnglishGrade(10);
    s1.SetHistoryGrade(1);
    s1.SetMathGrade(2);
    s2.SetEnglishGrade(8);
    s2.SetHistoryGrade(9);
    s2.SetMathGrade(9);
    CompareEngGrades(s1,s2);
    CompareHistGrades(s1,s2);
    CompareAverages(s1,s2);
    printf("Average mark for %s is : %f ! ",s1.GetName().c_str(), s1.GetAverageGrade());
 return 0;
}