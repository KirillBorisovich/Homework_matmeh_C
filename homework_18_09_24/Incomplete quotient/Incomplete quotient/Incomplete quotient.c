#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int incompleteQuotient(const int a, const int b, int* errorCode) {
    if (b == 0) {
        *errorCode = 1;
        return 0;
    }
    *errorCode = 0;
    int dividend = fabs(a), divider = fabs(b);
    int counter = 0;
    while (dividend >= divider) {
        dividend -= divider;
        ++counter;
    }
    if ((a >= 0 && b > 0) || (a < 0 && b < 0)) {
        return counter;
    }
    else if ((dividend == 0) || (b < 0)) {
        return -counter;
    }
    else {
        return -counter - 1;
    }
}

int main(void) {
    setlocale(LC_ALL, "Rus");
    int errorCode = 0;
    int result = incompleteQuotient(13, -5, &errorCode);
    if (errorCode != 0) {
        printf("\nНеполное частное:\n Error: Нельзя делить на ноль\n---------");
    }
    else {
        printf("\nНеполное частное:\n Ответ: %d\n----------", result);
    }
}