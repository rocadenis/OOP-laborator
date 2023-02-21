#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

int main() {
    char sentence[MAX_WORDS * MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int i, j, k, n;

    printf("Introduceti o propozitie: ");
    scanf("%[^\n]", sentence);

    // Separare cuvinte
    n = 0;
    i = 0;
    while (sentence[i] != '\0') {
        while (sentence[i] == ' ') {
            i++;
        }
        j = 0;
        while (sentence[i] != ' ' && sentence[i] != '\0') {
            words[n][j] = sentence[i];
            j++;
            i++;
        }
        words[n][j] = '\0';
        n++;
    }

    // Sortare cuvinte
    char temp[MAX_WORD_LENGTH];
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strlen(words[i]) < strlen(words[j]) ||
                (strlen(words[i]) == strlen(words[j]) &&
                 strcmp(words[i], words[j]) > 0)) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    // Afisare cuvinte
    for (i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
