#include <stdio.h>
#include <stdbool.h>

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
bool arrayComparison(int array1[], int array2[], int lenghs) {
	for (int i = 0; i < lenghs; ++i) {
		if (array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}
