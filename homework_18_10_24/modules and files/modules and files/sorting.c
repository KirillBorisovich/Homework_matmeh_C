#include <stdio.h>
#include "sorting.h"

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

void qSort(int array[], int first, int last) {
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
		qSort(array, first, right);
		qSort(array, left, last);
	}
}

void smartQSort(int array[], int first, int last) {
	if (last - first + 1 < 10) {
		insertSort(array, first, last);
	}
	else {
		qSort(array, first, last);
	}
}
