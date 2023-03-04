#pragma once
#include "Student.h"
//pentru functiile urmatoare voi afisa in functie de valorile -1,0,1
//dar pentru o mai buna vizualizare voi afisa rezultatul intr o propozitie
int CompareNames(const Student& s1, const Student& s2);
int CompHistoryGrades(const Student& s1, const Student& s2);
int CompEnglishGrades(const Student& s1, const Student& s2);
int CompMatheGrades(const Student& s1, const Student& s2);
int CompSAverages(const Student& s1, const Student& s2);