#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void swap(int* left, int* right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}
void printArray(int array[], int lengh) {
	for (int i = 0; i < lengh; ++i) {
		printf("%d ", array[i]);
	}
}
void fillArray(int array[], int lengh) {
	for (int i = 0; i < lengh; ++i) {
		array[i] = rand();
	}
}

int theMostCommonElement(int array[], int lengh) {
	int min = array[0], max = array[0];
	for (int i = 0; i < lengh; ++i) {
		if (min > array[i]) {
			min = array[i];
		}
		if (max < array[i]) {
			max = array[i];
		}
	}
	int* auxiliaryArray = (int*)calloc(max - min + 1, sizeof(int));
	if (auxiliaryArray == NULL) {
		return -1;
	}
	for (int i = 0; i < lengh; ++i) {
		++auxiliaryArray[array[i] - min];
	}
	int counterMax = 0, frequentEment = 0;
	for (int i = 0; i <= max - min + 1; ++i) {
		if (counterMax < auxiliaryArray[i]) {
			frequentEment = i + min;
			counterMax = auxiliaryArray[i];
		}
	}
	free(auxiliaryArray);
	return frequentEment;
}
void wrapperTheMostCommonElement() {
	int array[] = { 1, 2, 3, 3, 4, 5, 1, 2, 3, 7 };
	printf("\n----------\nThe most common element: %d\nArray: ", theMostCommonElement(array, 10));
	printArray(array, 10);
	printf("\n----------");
}

bool testTheMostCommonElement() {
	int array[] = { 1, 2, -3, 4, 5, -3 };
	return theMostCommonElement(array, 5) == -3;
}

int main(void) {
	if (!testTheMostCommonElement()) {
		printf("Test failed");
		return -1;
	}
	wrapperTheMostCommonElement();
}