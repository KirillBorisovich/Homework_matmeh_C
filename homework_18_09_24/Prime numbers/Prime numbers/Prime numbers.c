#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void primeNumbers(int theGivenNumber) {
    printf("\Prime numbers:\n");
    for (int number = 2; number <= theGivenNumber; ++number) {
        int counter = 0;
        for (int divider = 2; divider < (int)sqrt(number) + 1; ++divider) {
            if (number % divider == 0) {
                ++counter;
                break;
            }
        }
        if (counter == 0) {
            printf(" %d", number);
        }
    }
    printf("\n----------");
}

int main(void) {
    setlocale(LC_ALL, "Rus");
    primeNumbers(100);
}