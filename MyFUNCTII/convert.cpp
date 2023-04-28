#include <string>

int string_to_int(const std::string& str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Verifica semnul numarului
    if (str[i] == '-') {
        sign = -1;
        ++i;
    } else if (str[i] == '+') {
        ++i;
    }

    // Calculeaza valoarea numarului
    for (; i < str.length(); ++i) {
        if (str[i] < '0' || str[i] > '9') {
            // Caracterul nu face parte din numar
            break;
        }
        result = result * 10 + (str[i] - '0');
    }

    return sign * result;
}
