#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

bool stringMatching(const char* string, const char* substringint, int substringLen, int i) {
    for (int j = 0; j < substringLen; ++j) {
        if (string[i + j] != substringint[j]) {
            return false;
            printf("%c%c ", string[i], string[i + 1]);
        }
    }
    return true;
}
int countString(const char* string, const char* substring) {
    int stringLen = strlen(string);
    const int substringLen = strlen(substring);
    int counter = 0;
    for (int i = 0; i < stringLen - substringLen + 1; ++i) {
        if (stringMatching(string, substring, substringLen, i)) {
            ++counter;
        }
    }
    return counter;
}

int main(void) {
    printf("\nSubstring:\n number of substrings: %d\n----------", countString("qwqwqw", "wq"));
}