#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int countString(const char* string, const char* substring) {
    int stringLen = strlen(string);
    const int substringLen = strlen(substring);
    int counter = 0;
    for (int i = 0; i < stringLen - substringLen; ++i) {
        char* sliseString = (char*)calloc(substringLen + 1, sizeof(char));
        for (int j = 0; j < substringLen; ++j) {
            sliseString[j] = string[i + j];
        }
        if (strcmp(sliseString, substring) == '\0') {
            ++counter;
        }
        free(sliseString);
    }

    return counter;
}

int main(void) {
    printf("\nSubstring:\n number of substrings: %d\n----------", countString("qwqwqwqw", "qw"));
}