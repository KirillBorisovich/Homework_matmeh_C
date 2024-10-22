#include <stdio.h>
#include <stdbool.h>
#include "functionsFromPreviousTasks.h"
#include "sorting.h"
#include "tests.h"

int main(void) {
	if (!testProgram()) {
		printf("\nTest failed");
		return -1;
	}
	int array[15] = { 0 };
	int lengh = 15;
	fillArray(array, lengh);
	printf("\nSmart QSort\n array: ");
	printArray(array, lengh);
	smartQSort(array, 0, lengh - 1);
	printf("\n sorted array: ");
	printArray(array, lengh);
}