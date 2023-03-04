#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdio>
using namespace std;
char s[101][10001];
int main()
{
    char str[10001];
    int count = 0;
    fgets(str, 1000, stdin);
    char *p = strtok(str, " ");
    while (p)
    {
        strcpy(s[count++], p);
        if (p[strlen(p) - 1] == '\n')
            p[strlen(p) - 1] = '\0';
        p = strtok(NULL, " ");
    }
    count--;
    int length[1000];
    for (int i = 0; i <= count; ++i)
        length[i] = strlen(s[i]);
    for (int i = 0; i <= count; ++i)
        for (int j = i + 1; j <= count; ++j)
            if (length[i] < length[j])
            {
                swap(s[i], s[j]);
                swap(length[i], length[j]);
            }
            else if (length[i] == length[j] && strcmp(s[i], s[j]) == 1)
            {
                swap(s[i], s[j]);
                swap(length[i], length[j]);
            }
    for (int i = 0; i <= count; ++i)
        printf("%s\n", s[i]);
    return 0;
}