#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>


bool palindrome(const char* string) {
	int stringLen = strlen(string);
	int counter = 0;
	char *stringWithoutSpaces = (char*)calloc(stringLen + 1, sizeof(char));
	if (stringWithoutSpaces == NULL) {
		return -1;
	}
	for (int i = 0; i < stringLen; ++i) {
		if (string[i] != ' ') {
			stringWithoutSpaces[counter] = string[i];
			++counter;
		}
	}
	for (int i = 0; i < counter / 2; ++i) {
		if ((stringWithoutSpaces[i] != stringWithoutSpaces[counter - i - 1])) {
			free(stringWithoutSpaces);
			return false;
		}
	}
	free(stringWithoutSpaces);
	return true;
}

bool testPalindrome() {
	return palindrome("БУБ") && palindrome("BUU B") && palindrome("б уб")
		&& !palindrome(" БУЛБ ") && !palindrome("B UK") && palindrome("buub ");
}

int main(void) {
	setlocale(LC_ALL, "Rus");
	if (!testPalindrome()) {
		printf("Test failed");
		return -1;
	}
	char * string = " B U U B";
	if (palindrome(string)) {
		printf("Строка является палиндромом\n");
	}
	else {
		printf("Строка не является палиндромом\n");
	}
}
