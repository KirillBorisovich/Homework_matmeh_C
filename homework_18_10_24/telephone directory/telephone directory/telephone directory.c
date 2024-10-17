#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[80];
    char phone[20];
} NameAndPhoneNumber;

int readFromFile(FILE *file, char **data, int *numberOfLines) {
    int linesRead = 0;
    while (linesRead < 100) { // Проверка на переполнение массива
        char* buffer = malloc(sizeof(char) * 100);
        if (buffer == NULL) { // Проверка на успешное выделение памяти
            printf("Memory allocation failed!\n");
            return 2;
        }

        if (fgets(buffer, 100, file) != NULL) { // Чтение строки
            buffer[strcspn(buffer, "\n")] = 0; // Удаление символа новой строки
            NameAndPhoneNumber temporaryVariable;
            int spaceIndex = strcspn(buffer, " ");
            for (int i = 0; i < spaceIndex; ++i) {
                temporaryVariable.name[i] = buffer[i];
            }
            int j = 0;
            for (int i = spaceIndex + 1; i < strlen(buffer); ++i) {
                temporaryVariable.phone[j] = buffer[i];
                ++j;
            }
            temporaryVariable.name[spaceIndex] = '\0';
            temporaryVariable.phone[j] = '\0';
            data[linesRead] = &temporaryVariable; // Сохранение указателя на структру
            linesRead++;
        }
        else {
            free(buffer); // Освобождение памяти, если чтение не удалось
            return 0;
        }
    }
    *numberOfLines = linesRead;
    return 0;
}
int writeToFile(char **data, int numberOfLines) {
    FILE* file = fopen("Database.txt", "w");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    for (int i = 0; i < numberOfLines; ++i) {
        fprintf(file, "%s\n", data[i]);
        free(data[i]);
    }
    fclose(file);
    return 0;
}
void readDatabase(char **data, int numberOfLines) {
    for (int i = 0; i < numberOfLines; i++) {
        printf("%d: %s %s\n", i + 1, data[i]->name, data[i]->phone);
    }
}

int main(void) {
    FILE* file = fopen("Database.txt", "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    char* database[100];
    int numberOfLines = 0;
    readFromFile(file, database, &numberOfLines);
    fclose(file);

    int operationNumber = 9;
    while (operationNumber != 0) {
        printf("Enter operation number: ");
        scanf_s("%d", &operationNumber);
        getchar();
        if (operationNumber == 0) {
            printf("The program is complete");
            return 0;
        }
        else if (operationNumber == 1) {
            char* buffer = malloc(sizeof(char) * 100);
            if (buffer == NULL) {
                printf("Memory allocation failed!\n");
                break;
            }
            printf("Enter name and phone number: ");
            fgets(buffer, 100, stdin);
            if (strlen(buffer) > 0) { 
                buffer[strcspn(buffer, "\n")] = 0;
                database[numberOfLines] = buffer;
                ++numberOfLines;
            }
        }
        else if (operationNumber == 2) {
            readDatabase(database, numberOfLines);
        }
        else if (operationNumber == 3) {

        }
        else if (operationNumber == 4) {
            
        }
        else if (operationNumber == 5) {
            writeToFile(database, numberOfLines);
        }
    }
    return 0;
}