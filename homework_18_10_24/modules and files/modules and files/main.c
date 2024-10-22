#include <stdio.h>
#include <stdbool.h>
#include "functionsFromPreviousTasks.h"
#include "sorting.h"
#include "tests.h"

int main(void) {
	if (!testTheMostCommonElement()) {
		printf("Test failed");
		return -1;
	}
	int array[16] = { 0 };
	int lengh = 16;
	readFromFile("numbersToSort.txt", array, lengh);
	printf("The most common element: %d\nArray: ", theMostCommonElement(array, lengh));
	printArray(array, lengh);
}