#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

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
