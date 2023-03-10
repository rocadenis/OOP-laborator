#pragma once

class Canvas
{
private:
    int width; // latimea canvasului
    int height; // inaltimea canvasului
    char** matrix; // matricea care reprezinta canvas-ul

public:
    Canvas(int width, int height); // constructor care initializeaza dimensiunile canvasului
    ~Canvas(); // destructor care elibereaza memoria alocata pentru matrice
    void DrawCircle(int x, int y, int ray, char ch); // deseneaza un cerc
    void FillCircle(int x, int y, int ray, char ch); // umple un cerc
    void DrawRect(int left, int top, int right, int bottom, char ch); // deseneaza un dreptunghi
    void FillRect(int left, int top, int right, int bottom, char ch); // umple un dreptunghi
    void SetPoint(int x, int y, char ch); // seteaza un punct la coordonatele date
    void DrawLine(int x1, int y1, int x2, int y2, char ch); // deseneaza o linie intre doua puncte
    void Print(); // afiseaza continutul canvasului
    void Clear(); // sterge continutul canvasului
};
