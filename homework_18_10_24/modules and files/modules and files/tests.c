#include <stdio.h>
#include <stdbool.h>
#include "tests.h"


bool testTheMostCommonElement() {
	int array[] = { 1, 2, -3, 4, 5, -3 };
	return theMostCommonElement(array, 5) == -3;
}