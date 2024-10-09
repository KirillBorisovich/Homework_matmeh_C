#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

bool palindrome(const char* string) {
	int stringLen = strlen(string);
	for (int i = 0; i < stringLen / 2; ++i) {
		if ((string[i] != string[stringLen - i - 1])) {
			return false;
		}
	}
		return true;
}

bool testPalindrome() {
	return palindrome("БУБ") && palindrome("BUUB") && palindrome("буб")
		&& !palindrome("БУЛБ") && !palindrome("BUK") && palindrome("buub");
}

int main(void) {
	setlocale(LC_ALL, "Rus");
	if (!testPalindrome()) {
		printf("Test failed");
		return -1;
	}
	char * string = "BUUIB";
	printf("%d", palindrome(string));
}
