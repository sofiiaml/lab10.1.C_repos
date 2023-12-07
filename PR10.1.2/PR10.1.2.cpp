#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Count(const char* filename, int counts[256]) {
    FILE* file = fopen(filename, "r");

    if (!file) {
        printf("Error during opening file\n");
        return;
    }

    int s;
    while ((s = fgetc(file)) != EOF) {
        if (s == '+' || s == '-' || s == '=') {
            counts[s]++;
        }
    }

    fclose(file);
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    int occurrences[256] = { 0 };
    Count(filename, occurrences);

    // Виведення результатів
    printf("Occurrences in file '%s':\n", filename);
    printf("Symbol '+' %d times.\n", occurrences['+']);
    printf("Symbol '-' %d times.\n", occurrences['-']);
    printf("Symbol '=' %d times.\n", occurrences['=']);

    return 0;
}
