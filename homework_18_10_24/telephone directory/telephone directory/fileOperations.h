#pragma once

// Function to read from file
int readFromFile(char* filePath, ameAndPhoneNumber* data, int* numberOfLines);

// Function to write to file
int writeToFile(char* filePath, NameAndPhoneNumber* data, int numberOfLines, bool* changeData);