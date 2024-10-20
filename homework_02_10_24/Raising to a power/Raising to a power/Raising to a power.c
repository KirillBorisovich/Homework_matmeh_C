#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

float raisingToAPower(int number, int degree) {
    float result = 1;
    for (int i = 0; i < abs(degree); ++i) {
        result *= number;
    }
    if (degree >= 0) {
        return result;
    }
    else {
        return (1 / result);
    }
}
float fastRaisingToAPower(int number, int degree) {
    float result = 1;
    int degreeAbs = abs(degree);
    while (degreeAbs) {
        if (degreeAbs % 2 == 0) {
            degreeAbs /= 2;
            number *= number;
        }
        else {
            degreeAbs--;
            result *= number;
        }
    }
    if (degree >= 0) {
        return result;
    }
    else {
        return 1 / result;
    }

}

bool testRaisingToAPower() {
    return ((raisingToAPower(10, 2) == 100) && (raisingToAPower(10, 0) == 1) && (raisingToAPower(-10, 1) == -10)
        && (raisingToAPower(10, -1) == 0, 1) && (raisingToAPower(10, 1) == 10) && (raisingToAPower(-10, 2) == 100)
        && (raisingToAPower(-10, -1) == -0, 1) && (raisingToAPower(-10, -2) == -0, 01));
}
bool testFastRaisingToAPower() {
    return ((fastRaisingToAPower(10, 2) == 100) && (fastRaisingToAPower(10, 0) == 1) && (fastRaisingToAPower(-10, 2) == 100)
        && (fastRaisingToAPower(10, -1) == 0, 1) && (fastRaisingToAPower(10, 1) == 10) && (fastRaisingToAPower(-10, 1) == -10)
        && (fastRaisingToAPower(-10, -1) == -0, 1) && (fastRaisingToAPower(-10, -2) == -0, 01));
}

int main(void) {
    if (!testRaisingToAPower() && !testFastRaisingToAPower()) {
        printf("Test failed");
        return -1;
    }
    printf("\nRaising to a power\n Ordinary: %f\n Fast: %f\n----------",
        raisingToAPower(-10, -1),
        fastRaisingToAPower(-10, 2));
}