#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fileOperations.h"
#include "structure.h"

typedef struct {
    char name[80];
    char phone[20];
} NameAndPhoneNumber;

void printDatabase(NameAndPhoneNumber **data, int numberOfLines) {
    printf("----------\n");
    for (int i = 0; i < numberOfLines; i++) {
        printf("%d: %s %s\n", i + 1, data[i]->name, data[i]->phone);
    }
    printf("----------\n");
}
void printInstruction() {
    printf("Maximum number of records: 100\n");
    printf("Maximum value for name input: 80\nMaximum value for phone number input: 20\n");
    printf("Operation numbers:\n");
    printf("0 - exit\n");
    printf("1 - add a record (name and phone)\n");
    printf("2 - print all available records\n");
    printf("3 - find phone by name\n");
    printf("4 - find name by phone\n");
    printf("5 - save current data to file\n----------\n");
}
char* findPhoneByName(NameAndPhoneNumber **data, int numberOfLines, char name[]) {
    for (int i = 0; i < numberOfLines; ++i) {
        if (!strcmp(name, data[i]->name)) {
            return data[i]->phone;
        }
    }
    return "Nothing found";
}
char* findNameByPhone(NameAndPhoneNumber **data, int numberOfLines, char phone[]) {
    for (int i = 0; i < numberOfLines; ++i) {
        if (!strcmp(phone, data[i]->phone)) {
            return data[i]->name;
        }
    }
    return "Nothing found";
}

int fillValuesIntoTheTestDatabase(NameAndPhoneNumber** data) {
    char* name[5] = { "testName1", "testName2", "testName3", "testName4" , "testName5" };
    char* phones[5] = {"123132123", "456456123", "7891234", "123456742" , "123412344" };
    for (int i = 0; i < 5; ++i) {
        NameAndPhoneNumber* element = malloc(sizeof(NameAndPhoneNumber));
        if (element == NULL) {
            printf("Memory allocation failed!\n");
            return 2;
        }
        strcpy_s(element->name, 80, name[i]);
        strcpy_s(element->phone, 20, phones[i]);

        element->name[9] = '\0';
        element->phone[9] = '\0';

        data[i] = element;
    }
}

bool testReadFromFile(NameAndPhoneNumber **data, int *numberOfRecordsInTheDatabase){
    NameAndPhoneNumber* testDatabase[5];
    fillValuesIntoTheTestDatabase(testDatabase);
    readFromFile("reference file for reading.txt", data, numberOfRecordsInTheDatabase);
    for (int i = 0; i < 5; i++) {
        if (data[i] == NULL || testDatabase == NULL) {
            return false;
        }
        if (strcmp(data[i]->name, testDatabase[i]->name)
            || strcmp(data[i]->phone, testDatabase[i]->phone)) {
            printf("%s\n", testDatabase[i]->phone);
            return false;
        }
        free(testDatabase[i]);
    }
    return true;
}
bool testWriteToFile(NameAndPhoneNumber **data, int numberOfRecordsInTheDatabase) {
    bool changeData = true;
    writeToFile("test file for writing.txt", data, numberOfRecordsInTheDatabase, &changeData);
    FILE* referenceFile = fopen("reference file for reading.txt", "r");
    FILE* testFile = fopen("test file for writing.txt", "r");
    int linesRead = 0;
    while (linesRead < 100) {
        char* buffer1 = malloc(sizeof(char) * 100);
        char* buffer2 = malloc(sizeof(char) * 100);

        if (buffer1 == NULL || buffer2 == NULL) {
            printf("Memory allocation failed!\n");
            return 2;
        }

        if (fgets(buffer1, 100, referenceFile) != NULL && fgets(buffer2, 100, testFile) != NULL) {
            buffer1[strcspn(buffer1, "\n")] = 0;
            buffer2[strcspn(buffer2, "\n")] = 0;
            if (strcmp(buffer1, buffer2)) {
                free(buffer1);
                free(buffer2);
                return false;
            }
            free(buffer1);
            free(buffer2);
        }
        else {
            free(buffer1);
            free(buffer2);
            break;
        }
    }
    fclose(referenceFile);
    fclose(testFile);
    return true;
}
bool testFindPhoneByName() {
    NameAndPhoneNumber* testDatabase[5];
    fillValuesIntoTheTestDatabase(testDatabase);
    char* name = "testName3";
    if (!strcmp(findPhoneByName(testDatabase, 5, name), "7891234")) {
        return true;
    }
    return false;
}
bool testFindNameByPhone() {
    NameAndPhoneNumber* testDatabase[5];
    fillValuesIntoTheTestDatabase(testDatabase);
    char* phone = "7891234";
    if (!strcmp(findNameByPhone(testDatabase, 5, phone), "testName3")) {
        return true;
    }
    return false;
}
bool testPtogram() {
    NameAndPhoneNumber* database[5] = { NULL };
    int numberOfRecordsInTheDatabase = 0;
    return testReadFromFile(database, &numberOfRecordsInTheDatabase) && testWriteToFile(database, numberOfRecordsInTheDatabase)
        && testFindPhoneByName() && testFindNameByPhone();
}

int main(void) {
    if (!testPtogram()) {
        printf("Test failed");
        return -1;
    }
    char* filePath = "Database.txt";
    bool changeData = false;
    NameAndPhoneNumber *database[100];
    int numberOfRecordsInTheDatabase = 0;
    readFromFile(filePath, database, &numberOfRecordsInTheDatabase);
    int operationNumber = 9;
    printInstruction();
    while (operationNumber != 0) {
        printf("Enter operation number: ");

        scanf_s("%d", &operationNumber);
        getchar();
        if (operationNumber == 0) {
            for (int i = 0; i < numberOfRecordsInTheDatabase; ++i) {
                free(database[i]);
            }
            printf("The program is complete\n");
            return 0;
        }
        else if (operationNumber == 1) {
            printf("----------\n");
            if (numberOfRecordsInTheDatabase >= 100) {
                printf("Number of entries exceeded!\n");
            }
            else {
                NameAndPhoneNumber* temporaryVariable = malloc(sizeof(NameAndPhoneNumber));
                if (temporaryVariable == NULL) {
                    printf("Memory allocation failed!\n");
                    return 2;
                }
                printf("Enter name: ");
                scanf_s("%s", temporaryVariable->name, 80);
                printf("Enter phone: ");
                scanf_s("%s", temporaryVariable->phone, 20);
                database[numberOfRecordsInTheDatabase] = temporaryVariable;
                ++numberOfRecordsInTheDatabase;
                changeData = true;
            }
            printf("----------\n");

        }
        else if (operationNumber == 2) {
            printDatabase(database, numberOfRecordsInTheDatabase);
        }
        else if (operationNumber == 3) {
            char name[80];
            printf("----------\n");
            printf("Enter name: ");
            scanf_s("%s", &name, 80);
            printf("Found phone number: \n");
            printf("%s\n", findPhoneByName(database, numberOfRecordsInTheDatabase, name));
            printf("----------\n");
        }
        else if (operationNumber == 4) {
            char phone[20];
            printf("----------\n");
            printf("Enter name: ");
            scanf_s("%s", &phone, 20);
            printf("Found phone number: \n");
            printf("%s\n", findNameByPhone(database, numberOfRecordsInTheDatabase, phone));
            printf("----------\n");
        }
        else if (operationNumber == 5) {
            if (!writeToFile(filePath, database, numberOfRecordsInTheDatabase, &changeData)) {
                printf("Data saved\n");
            }
            else {
                printf("First you need to add data\n");
            }
        }
    }
}