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
bool arrayComparison(int array1[], int array2[], int lenghs) {
	for (int i = 0; i < lenghs; ++i) {
		if (array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}

void insertSort(int array[], int first, int last) {
	int newElement = 0, location = 0;
	for (int i = first; i <= last; ++i) {
		newElement = array[i];
		location = i - 1;
		while (location >= 0 && array[location] > newElement) {
			array[location + 1] = array[location];
			--location;
		}
		array[location + 1] = newElement;
	}
}
void smartQSort(int array[], int first, int last) {
	if (last - first + 1 < 10) {
		insertSort(array, first, last);
	}
	else {
		if (first < last) {
			int supportingElement = array[first];
			int left = first;
			int right = last;
			while (left <= right) {
				while ((array[left] < supportingElement) && (left <= right)) {
					++left;
				}
				while ((supportingElement < array[right]) && (left <= right)) {
					--right;
				}
				if (left <= right) {
					swap(&array[left], &array[right]);
					++left;
					--right;
				}
			}
			smartQSort(array, first, right);
			smartQSort(array, left, last);
		}
	}
}

bool testSmartQSort() {
	int array[] = { 3, 2, 3, 1, 8, 5, 9, 0, 4 };
	int sortedArray[] = { 0, 1, 2, 3, 3, 4, 5, 8, 9 };
	smartQSort(array, 0, 8);
	return arrayComparison(array, sortedArray, 9);
}

int main(void) {
	if (!testSmartQSort()) {
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