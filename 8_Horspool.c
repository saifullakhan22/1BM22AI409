#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

void shiftTable(char pattern[], int patternLength, int shiftTable[]) {
    for (int i = 0; i < MAX_CHAR; i++) {
        shiftTable[i] = patternLength;
    }

    for (int j = 0; j < patternLength - 1; j++) {
        shiftTable[pattern[j]] = patternLength - 1 - j;
    }
}

int horspoolSearch(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int shiftTables[MAX_CHAR];
    shiftTable(pattern, patternLength, shiftTables); // Corrected function name

    int i = patternLength - 1;
    while (i < textLength) {
        int k = 0;
        while (k < patternLength && pattern[patternLength - 1 - k] == text[i - k]) {
            k++;
        }

        if (k == patternLength) {
            return i - patternLength + 1; // Match found
        } else {
            i += shiftTables[text[i]];
        }
    }

    return -1; // Match not found
}

int main() {
    char text[1000], pattern[100];

    printf("Enter the text: ");
    gets(text);

    printf("Enter the pattern to search for: ");
    gets(pattern);

    int result = horspoolSearch(text, pattern);

    if (result != -1) {
        printf("Pattern found at index: %d\n", result);
    } else {
        printf("Pattern not found in the text.\n");
    }

    return 0;
}
