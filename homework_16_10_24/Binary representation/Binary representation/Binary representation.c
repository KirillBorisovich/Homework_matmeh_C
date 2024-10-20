#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

bool arrayComparison(char array1[], char array2[], int lenghs) {
	for (int i = 0; i < lenghs; ++i) {
		if (array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}

float fastRaisingToAPower(int number, int degree) {
	float result = 1;
	int degreeAbs = abs(degree);
	while (degreeAbs) {
		if (degreeAbs % 2 == 0) {
			degreeAbs /= 2;
			number *= number;
		}
		else {
			degreeAbs--;
			result *= number;
		}
	}
	if (degree >= 0) {
		return result;
	}
	else {
		return 1 / result;
	}
}

int conversionToDecimalSystem(char *numberBinary) {
	int counter = 0;
	int indexCounter = 0;
	while (numberBinary[indexCounter] != '\0') {
		if (numberBinary[indexCounter] == '1') {
			counter += fastRaisingToAPower(2, (sizeof(int) * 8) - 1 - indexCounter);
		}
		++indexCounter;
	}
	return counter;
}
void translationIntoAdditionalCode(int number, char *numberBinary) {
	int mask = 1;
	for (int i = (sizeof(int) * 8) - 1; i >= 0; --i) {
		numberBinary[i] = number & mask ? '1' : '0';
		mask = mask << 1;
	}
	numberBinary[sizeof(int) * 8] = '\0';
}
void additionOfBinaryDigits(char *firstNumberBinary, char *secondNumberBinary, char *binarySum) {
	bool nextRank = false;
	for (int i = (sizeof(int) * 8) - 1; i >= 0; --i) {
		if ((firstNumberBinary[i] == '1' && secondNumberBinary[i] == '1')) {
			binarySum[i] = nextRank ? '1' : '0';
			nextRank = true;
		}
		else if ((firstNumberBinary[i] == '0' && secondNumberBinary[i] == '1') 
			|| (firstNumberBinary[i] == '1' && secondNumberBinary[i] == '0')) {
			binarySum[i] = nextRank ? '0' : '1';
		}
		else if ((firstNumberBinary[i] == '0' && secondNumberBinary[i] == '0')) {
			if (nextRank) {
				binarySum[i] = '1';
				nextRank = false;
			}
			else {
				binarySum[i] = '0';
			}
		}
	}
	binarySum[sizeof(int) * 8] = '\0';
}

bool testFastRaisingToAPower() {
	return ((fastRaisingToAPower(10, 2) == 100) && (fastRaisingToAPower(10, 0) == 1) && (fastRaisingToAPower(-10, 2) == 100)
		&& (fastRaisingToAPower(10, -1) == 0, 1) && (fastRaisingToAPower(10, 1) == 10) && (fastRaisingToAPower(-10, 1) == -10)
		&& (fastRaisingToAPower(-10, -1) == -0, 1) && (fastRaisingToAPower(-10, -2) == -0, 01));
}
bool testConversionToDecimalSystem() {
	char* numberBinary1 = "00000000000000000000000000001010";
	char* numberBinary2 = "11111111111111111111111111110011";
	return (conversionToDecimalSystem(numberBinary1) == 10) && (conversionToDecimalSystem(numberBinary2) == -13);
}
bool testTranslationIntoAdditionalCode() {
	int number1 = 10, number2 = -13;
	char numberBinary1[(sizeof(int) * 8) + 1];
	char numberBinary2[(sizeof(int) * 8) + 1];
	translationIntoAdditionalCode(number1, numberBinary1);
	translationIntoAdditionalCode(number2, numberBinary2);
	return (conversionToDecimalSystem(numberBinary1) == number1) && (conversionToDecimalSystem(numberBinary2) == number2);
}
bool testAdditionOfBinaryDigits() {
	int number1 = 10, number2 = -13;
	char numberBinary1[(sizeof(int) * 8) + 1];
	char numberBinary2[(sizeof(int) * 8) + 1];
	char binarySum[(sizeof(int) * 8) + 1];
	translationIntoAdditionalCode(number1, numberBinary1);
	translationIntoAdditionalCode(number2, numberBinary2);
	additionOfBinaryDigits(numberBinary1, numberBinary2, binarySum);
	return conversionToDecimalSystem(binarySum) == number1 + number2;
}
bool testProgram() {
	return testFastRaisingToAPower() && testConversionToDecimalSystem()
		&& testTranslationIntoAdditionalCode() && testAdditionOfBinaryDigits();
}



int main(void) {
	setlocale(LC_ALL, "Rus");
	if (!testProgram()) {
		printf("Test failed"); 
		return -1;
	}
	int firstNumber = 0, secondNumber = 0;
	char firstNumberBinary[(sizeof(int) * 8) + 1];
	char secondNumberBinary[(sizeof(int) * 8) + 1];
	char binarySum[(sizeof(int) * 8) + 1];
	printf("Введите первое число: ");
	scanf_s("%d", &firstNumber);
	printf("Введите второе число: ");
	scanf_s("%d", &secondNumber);
	translationIntoAdditionalCode(firstNumber, firstNumberBinary);
	translationIntoAdditionalCode(secondNumber, secondNumberBinary);
	printf("\nДвоичное представление первого числа(в дополнительном коде):\n%s", firstNumberBinary);
	printf("\nДвоичное представление второго числа(в дополнительном коде):\n%s", secondNumberBinary);
	additionOfBinaryDigits(firstNumberBinary, secondNumberBinary, binarySum);
	printf("\nСумма чисел в двоичном представлении(в дополнительном коде):\n%s", binarySum);
	printf("\nСумма чисел в десятичном представлении:\n%d", conversionToDecimalSystem(binarySum));
}
