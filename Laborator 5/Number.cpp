#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include "Number.h"

// Constructor with string value and base
Number::Number(const char* value, int base) {
    this->value = nullptr;
    this->length = 0;
    this->base = base;

    int len = strlen(value);
    char* tempValue = new char[len + 1];
    strcpy(tempValue, value);

    // remove leading zeros
    while (len > 1 && tempValue[0] == '0') {
        len--;
        tempValue++;
    }

    // check if the value is valid
    for (int i = 0; i < len; i++) {
        char c = tempValue[i];

        if (c >= '0' && c <= '9') {
            c = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            c = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            c = c - 'A' + 10;
        } else {
            printf("Invalid character '%c' in value %s\n", c, value);
            return;
        }

        if (c >= base) {
            printf("Invalid digit '%c' for base %d in value %s\n", tempValue[i], base, value);
            return;
        }
    }

    // allocate memory for the value
    this->length = len;
    this->value = new char[len + 1];
    strcpy(this->value, tempValue);
}

// Constructor with integer value (default base 10)
Number::Number(int value) : Number(std::to_string(value).c_str(), 10) {}

// Copy constructor
Number::Number(const Number& other) {
    this->value = nullptr;
    this->length = 0;
    this->base = other.base;

    this->length = other.length;
    this->value = new char[this->length + 1];
    strcpy(this->value, other.value);
}

// Move constructor
Number::Number(Number&& other) {
    this->value = other.value;
    this->length = other.length;
    this->base = other.base;

    other.value = nullptr;
    other.length = 0;
}

// Destructor
Number::~Number() {
    if (this->value != nullptr) {
        delete[] this->value;
    }
}

// Copy assignment operator
Number& Number::operator=(const Number& other) {
    if (this != &other) {
        this->base = other.base;

        delete[] this->value;
        this->length = other.length;
        this->value = new char[this->length + 1];
        strcpy(this->value, other.value);
    }

    return *this;
}

// Move assignment operator
Number& Number::operator=(Number&& other) {
    if (this != &other) {
        this->value = other.value;
        this->length = other.length;
        this->base = other.base;

        other.value = nullptr;
        other.length = 0;
    }

    return *this;
}

// Index operator
char Number::operator[](int index) const {
    if (index < 0 || index >= this->length) {
        printf("Index out of bounds: %d\n", index);
        return '\0';
    }

    return this->value[index];
}

// Equality operator
bool Number::operator==(const Number& other) const {
    if (this->length != other.length || this->base != other.base) {
        return false;
    }

    for (int i = 0; i < this->length; i++) {
        if (this->value[i] != other.value[i]) {
            return false;
        }
    }

    return true;
}
bool Number::operator!=(const Number& other) const {
    return !(*this == other);
}
bool Number::operator<(const Number& other) const {
    if (this->base != other.base) {
        printf("Cannot compare numbers with different bases\n");
        return false;
    }

    if (this->length < other.length) {
        return true;
    } else if (this->length > other.length) {
        return false;
    }

    for (int i = 0; i < this->length; i++) {
        if (this->value[i] < other.value[i]) {
            return true;
        } else if (this->value[i] > other.value[i]) {
            return false;
        }
    }

    return false;
}
bool Number::operator<=(const Number& other) const {
    return (*this < other) || (*this == other);
}
bool Number::operator>(const Number& other) const {
    return !(*this <= other);
}
bool Number::operator>=(const Number& other) const {
    return !(*this < other);
}
Number Number::operator+(const Number& other) const {
    // Aduna valoarea curenta cu valoarea obiectului other
    Number result(*this);
    int carry = 0;
    for (int i = length - 1, j = other.length - 1; i >= 0 || j >= 0 || carry; i--, j--) {
        int sum = (i >= 0 ? value[i] - '0' : 0) + (j >= 0 ? other.value[j] - '0' : 0) + carry;
        result.value[i] = sum % base + '0';
        carry = sum / base;
    }
    //result.TrimLeadingZeros();
    return result;
}

Number Number::operator-(const Number& other) const {
    // Scade valoarea obiectului other din valoarea curenta
    Number result(*this);
    int borrow = 0;
    for (int i = length - 1, j = other.length - 1; i >= 0 || j >= 0; i--, j--) {
        int diff = (i >= 0 ? value[i] - '0' : 0) - (j >= 0 ? other.value[j] - '0' : 0) - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.value[i] = diff + '0';
    }
    //result.TrimLeadingZeros();
    return result;
}

Number& Number::operator+=(const Number& other) {
    // Aduna valoarea obiectului other la valoarea curenta
    *this = *this + other;
    return *this;
}

Number& Number::operator-=(const Number& other) {
    // Scade valoarea obiectului other din valoarea curenta
    *this = *this - other;
    return *this;
}

Number& Number::operator--() {
    // Scade 1 din valoarea curenta
    Number one("1", base);
    *this -= one;
    return *this;
}

Number Number::operator--(int) {
    // Scade 1 din valoarea curenta si returneaza valoarea veche
    Number result(*this);
    --(*this);
    return result;
}

void Number::SwitchBase(int newBase) {
    // Converteste valoarea curenta in noua baza
    if (newBase != base) {
        base = newBase;
    }
}

void Number::Print() const {
    printf("%s\n", value);

}



int Number::GetDigitsCount() const {
    // Returneaza numarul de cifre al valorii curente
    return length;
}

int Number::GetBase() const {
    // Returneaza baza curenta
    return base;
}
