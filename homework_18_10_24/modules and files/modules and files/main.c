#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "functionsFromPreviousTasks.h"
#include "sorting.h"
#include "tests.h"

int main(void) {
	if (!testTheMostCommonElement()) {
		printf("Test failed");
		return -1;
	}
	FILE* file = fopen("numbersToSort.txt", "r");
	if (file == NULL) {
		printf("File not found!\n");
		return 1;
	}
	int errorCode = 0;
	int* array = calloc(2, sizeof(int));
	int size = 2;
	int numberOfNumbers = readFromFile(file, &array, &size, &errorCode);
	fclose(file);
	if (errorCode != 0) {
		printf("Memory allocation error!\n");
		return 1;
	}
	printf("The most common element: %d\nArray: ", theMostCommonElement(array, numberOfNumbers));
	printArray(array, numberOfNumbers);
}