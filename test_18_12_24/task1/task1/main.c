#include <stdio.h>
#include <string.h>

int power(int number, int degree) {
    if (degree == 0) {
        return 1;
    }
    int result = number;
    for (int i = 0; i < degree - 1; ++i) {
        result *= number;
    }
    return result;
}

int translationFromTheNumberSystem(char* string) {
    int result = 0;
    int stringLen = strlen(string);
    for (int i = 0; i < stringLen; ++i) {
        int symbol = string[i] - '0';
        result += symbol * power(2, stringLen - 1 - i);
    }
    return result;
}

int main(void) {
    if (power(2, 3) != 8 || translationFromTheNumberSystem("1111") != 15) {
        printf("Test failed!\n");
        return 123;
    }
    char* string = "1010";
    printf("%d", translationFromTheNumberSystem(string));
}