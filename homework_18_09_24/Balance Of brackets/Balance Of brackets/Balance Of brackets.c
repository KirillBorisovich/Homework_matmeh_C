#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void balanceOfBrackets(const char string[]) {
    int counter = 0;
    int indexCounter = 0;
    while (string[indexCounter] != '\0') {
        if (string[indexCounter] == '(') {
            counter += 1;
        }
        else if (string[indexCounter] == ')') {
            counter -= 1;
        }
        if (counter < 0) {
            break;
        }
        indexCounter += 1;
    }
    if (counter == 0) {
        printf("\nBalance of brackets:\n successfully\n----------");
    }
    else {
        printf("\nBalance of brackets:\n Error: The balance of the brackets is out of balance\n----------");
    }
}

int main(void) {
    balanceOfBrackets("())()");
}