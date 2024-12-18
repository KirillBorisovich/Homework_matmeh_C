#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "graph.h"
#include "readingFromFile.h"

int numberOfSpacesInALine(char* string) {
    int stringLen = strlen(string);
    int counter = 0, index = 0;
    while (string[index] != '\0') {
        if (string[index] == ' ') {
            ++counter;
        }
        ++index;
    }
    return counter;
}

void fillingThreeVariablesFromAString(char* buffer, char* name1, char* name2, char* name3) {
    int index = 0, name1Index = 0, name2Index = 0, name3Index = 0;
    int counter = 0;
    while (buffer[index] != NULL) {
        if (buffer[index] == ' ') {
            ++counter;
            ++index;
        }
        switch (counter) {
        case 0:
            name1[name1Index] = buffer[index];
            ++name1Index;
            break;
        case 1:
            name2[name2Index] = buffer[index];
            ++name2Index;
            break;
        case 2:
            name3[name3Index] = buffer[index];
            ++name3Index;
            break;
        }
        ++index;
    }
}

void readingFromFile(FILE* file, Graph* graph, int* errorCode) {
    char buffer[100] = { '\0' };

    while (true) {
        if (fgets(buffer, 100, file) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0;
            int numberOfSpacesInAString = numberOfSpacesInALine(buffer);
            if (numberOfSpacesInAString == 2) {
                char departurePoint[30] = { '\0' };
                char arrivalPoint[30] = { '\0' };
                char length[30] = { '\0' };
                fillingThreeVariablesFromAString(
                    buffer, departurePoint,
                    arrivalPoint, length);
                createAPath(graph, strtol(departurePoint, NULL, 10),
                    strtol(arrivalPoint, NULL, 10), strtol(length, NULL, 10), errorCode);
            }
            else if (numberOfSpacesInAString == 0) {
                if (fgets(buffer, 100, file) != NULL) {
                    buffer[strcspn(buffer, "\n")] = 0;
                    char name[30] = { '\0' };
                    int index = 0;
                    while (buffer[index] != '\0') {
                        if (buffer[index] != ' ') {
                            name[index] = buffer[index];
                        }
                        else {
                            int intName = strtol(name, NULL, 10);
                            Node* node = findNodeInGraph(graph, intName);
                            if (node == NULL) {
                                node = createNode(intName, errorCode);
                            }
                            addElementToGraph(graph, node, errorCode);
                        }
                    }
                }
            }
        }
        else {
            break;
        }
    }
}