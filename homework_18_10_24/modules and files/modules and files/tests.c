#include <stdio.h>
#include <stdbool.h>
#include "tests.h"


bool testInsertSort() {
	int array[] = { 3, 2, 3, 1, 8, 5, 9, 0, 4 };
	int sortedArray[] = { 0, 1, 2, 3, 3, 4, 5, 8, 9 };
	insertSort(array, 0, 8);
	return arrayComparison(array, sortedArray, 9);
}
bool testSmartQSort() {
	int array[] = { 3, 2, 3, 1, 8, 5, 9, 0, 4 };
	int sortedArray[] = { 0, 1, 2, 3, 3, 4, 5, 8, 9 };
	smartQSort(array, 0, 8);
	return arrayComparison(array, sortedArray, 9);
}
bool testProgram() {
	return testInsertSort() && testSmartQSort();
}