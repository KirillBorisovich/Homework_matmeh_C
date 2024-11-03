#pragma once

// Check for a number
bool recognizeTheNumber(char element);

// Converting number to literal
char meaningTranslated(int number);

// Convert an expression from infix to postfix form
char* transformTheFormOfExpression(char* string, int* errorCode);
