
#pragma once

#include <string>

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

//pentru functiile urmatoare voi afisa in functie de valorile -1,0,1
//dar pentru o mai buna vizualizare voi afisa rezultatul intr o propozitie
int CompareNames(const Student& s1, const Student& s2);
int CompareGrades(const Student& s1, const Student& s2);
int CompareAverages(const Student& s1, const Student& s2);
};
