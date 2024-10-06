#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void luckyTickets() {
    int array[28] = { 0 };
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 10; k++) {
            for (int j = 0; j < 10; j++) {
                ++array[i + k + j];
            }
        }
    }
    int result = 0;
    for (int i = 0; i < 28; i++) {
        result += array[i] * array[i];
    }
    printf("----------\nLucky tickets: %d\n----------", result);
}

int main(void) {
    luckyTickets();
}