#include <stdio.h>
#include <stdlib.h>

void printLinesWithLineNumbers(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening the file.\n");
        return;
    }

    char buffer[256];
    int lineNumber = 1;

    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%d %s", lineNumber, buffer);
        lineNumber++;
    }
    printf("\n");
    fclose(file);
}

int main() {
    char filename[256] = "hello.txt";

    printLinesWithLineNumbers(filename);

    return 0;
}
