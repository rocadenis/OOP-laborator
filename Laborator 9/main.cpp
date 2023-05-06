#include <iostream>
#include "Map.h"

int main() {
Map<int, const char *> m;
m.set(10, "C++");
m.set(20, "test");
m.set(30, "Poo");
for (auto[key, value, index] : m) {
printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
}
m.set(20, "result");
return 0;
}