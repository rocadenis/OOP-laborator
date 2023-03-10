#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height) : width(width), height(height)
{
    matrix = new char*[height];
    for (int i = 0; i < height; ++i)
    {
        matrix[i] = new char[width];
        for (int j = 0; j < width; ++j)
        {
            matrix[i][j] = ' ';
        }
    }
}

Canvas::~Canvas()//destructor
{
    for (int i = 0; i < height; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int cx = ray;
    int cy = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (ray << 1);

    while (cx >= cy)
    {
        SetPoint(x + cx, y + cy, ch);
        SetPoint(x + cy, y + cx, ch);
        SetPoint(x - cy, y + cx, ch);
        SetPoint(x - cx, y + cy, ch);
        SetPoint(x - cx, y - cy, ch);
        SetPoint(x - cy, y - cx, ch);
        SetPoint(x + cy, y - cx, ch);
        SetPoint(x + cx, y - cy, ch);

        if (err <= 0)
        {
            cy++;
            err += dy;
            dy += 2;
        }
        if (err > 0)
        {
            cx--;
            dx += 2;
            err += dx - (ray << 1);
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = x - ray; i <= x + ray; i++)
    {
        for (int j = y - ray; j <= y + ray; j++)
        {
            if (std::sqrt(std::pow(i - x, 2) + std::pow(j - y, 2)) <= ray)
            {
                SetPoint(i, j, ch);
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    DrawLine(left, top, right, top, ch);
    DrawLine(right, top, right, bottom, ch);
    DrawLine(right, bottom, left, bottom, ch);
    DrawLine(left, bottom, left, top, ch);
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; ++i)
    {
        for (int j = left; j <= right; ++j)
        {
            SetPoint(j, i, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        matrix[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    while (x1 != x2 || y1 != y2)
    {
        SetPoint(x1, y1, ch);
        int e2 = err << 1;//siftam la stanga cu un bit echivalent cu *2
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
    SetPoint(x2, y2, ch);
}

void Canvas::Print()
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void Canvas::Clear()
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            matrix[i][j] = ' ';
        }
    }
}


