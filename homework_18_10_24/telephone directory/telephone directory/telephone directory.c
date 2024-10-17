#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[80];
    char phone[20];
} NameAndPhoneNumber;

int readFromFile(FILE *file, NameAndPhoneNumber **data, int *numberOfLines) {
    int linesRead = 0;
    while (linesRead < 100) { // Проверка на переполнение массива
        char *buffer = malloc(sizeof(char) * 100);
        if (buffer == NULL) { // Проверка на успешное выделение памяти
            printf("Memory allocation failed!\n");
            return 2;
        }

        if (fgets(buffer, 100, file) != NULL) { // Чтение строки
            buffer[strcspn(buffer, "\n")] = 0; // Удаление символа новой строки
            NameAndPhoneNumber *temporaryVariable = malloc(sizeof(NameAndPhoneNumber));
            if (temporaryVariable == NULL) {
                printf("Memory allocation failed!\n");
                return 2;
            }
            size_t spaceIndex = strcspn(buffer, " ");
            for (int i = 0; i < spaceIndex; ++i) {
                temporaryVariable->name[i] = buffer[i];
            }
            int j = 0;
            for (int i = spaceIndex + 1; i < strlen(buffer); ++i) {
                temporaryVariable->phone[j] = buffer[i];
                ++j;
            }
            temporaryVariable->name[spaceIndex] = '\0';
            temporaryVariable->phone[j] = '\0';
            data[linesRead] = temporaryVariable; // Сохранение указателя на структру
            ++linesRead;
        }
        else {
            free(buffer); // Освобождение памяти, если чтение не удалось
            break;
        }
        free(buffer);
    }

    *numberOfLines = linesRead;
    return 0;
}
int writeToFile(NameAndPhoneNumber **data, int numberOfLines, bool *changeData) {
    if (!*changeData) {
        printf("First you need to add data\n");
        return 0;
    }
    FILE* file = fopen("Database.txt", "w");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    for (int i = 0; i < numberOfLines; ++i) {
        fprintf(file, "%s %s\n", data[i]->name, data[i]->phone);
    }
    fclose(file);
    *changeData = false;
    printf("Data saved\n");
    return 0;
}
void readDatabase(NameAndPhoneNumber **data, int numberOfLines) {
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
void findPhoneByName(NameAndPhoneNumber **data, int numberOfLines) {
    printf("----------\n");
    bool found = false;
    char name[80];
    printf("Enter name: ");
    scanf_s("%s", &name, 80);
    printf("Found phone numbers: \n");
    for (int i = 0; i < numberOfLines; ++i) {
        if (!strcmp(name, data[i]->name)) {
            printf("%s\n", data[i]->phone);
            found = true;
        }
    }
    if (!found) {
        printf("Nothing found\n");
    }
    printf("----------\n");

}
void findNameByPhone(NameAndPhoneNumber **data, int numberOfLines) {
    printf("----------\n");
    bool found = false;
    char phone[80];
    printf("Enter phone: ");
    scanf_s("%s", &phone, 80);
    printf("Found name: \n");
    for (int i = 0; i < numberOfLines; ++i) {
        if (!strcmp(phone, data[i]->phone)) {
            printf("%s\n", data[i]->name);
            found = true;
        }
    }
    if (!found) {
        printf("Nothing found\n");
    }
    printf("----------\n");

}

int main(void) {
    FILE* file = fopen("Database.txt", "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    bool changeData = false;
    NameAndPhoneNumber *database[100];
    int numberOfRecordsInTheDatabase = 0;
    readFromFile(file, database, &numberOfRecordsInTheDatabase);
    fclose(file);
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
            readDatabase(database, numberOfRecordsInTheDatabase);
        }
        else if (operationNumber == 3) {
            findPhoneByName(database, numberOfRecordsInTheDatabase);
        }
        else if (operationNumber == 4) {
            findNameByPhone(database, numberOfRecordsInTheDatabase);
        }
        else if (operationNumber == 5) {
            writeToFile(database, numberOfRecordsInTheDatabase, &changeData);
        }
    }
}