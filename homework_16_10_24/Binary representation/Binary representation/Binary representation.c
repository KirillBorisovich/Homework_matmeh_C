#include <stdio.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "Rus");
	int firstNumber = 0, secondNumber = 0, sum = 0;
	printf("Введите первое число: ");
	scanf_s("%d", &firstNumber);
	printf("\nВведите второе число: ");
	scanf_s("%d", &secondNumber);

}