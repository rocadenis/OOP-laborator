#include "Student.h"
#include "CompareStudents.h"
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
    s2.SetName("Dumitru Andrei");
    CompNames(s1,s2);
    s1.SetEnglishGrade(3);
    s1.SetHistoryGrade(6);
    s1.SetMatheGrade(2);
    s2.SetEnglishGrade(8);
    s2.SetHistoryGrade(5);
    s2.SetMathGrade(9);
    CompMatheGrades(s1,s2);
    CompHistoryGrades(s1,s2);
   printf("Average mark for %s is : %f ! ",s1.GetName().c_str(), s1.GetAverageGrade());
 return 0;
}