#include <stdio.h>
#include "parseTree.h"
#include "testsParseTree.h"

int main() {
    if (!testTree()) {
        printf("Test failed");
        return 123;
    }
    
}