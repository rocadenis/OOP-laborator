#ifndef NUMBER_H
#define NUMBER_H

class Number {
public:
    Number(const char* value, int base);
    Number(int value = 0);
    Number(const Number& other);
    Number(Number&& other);
    ~Number();
    Number& operator=(const Number& other);
    Number& operator=(Number&& other);

    char operator[](int index) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator>(const Number& other) const;
    bool operator>=(const Number& other) const;
    Number operator+(const Number& other) const;
    Number operator-(const Number& other) const;
    Number& operator+=(const Number& other);
    Number& operator-=(const Number& other);
    Number& operator--();
    Number operator--(int);

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

private:
    char* value;
    int base;
    int length;

    void ConvertToBase(int newBase);
};

#endif
