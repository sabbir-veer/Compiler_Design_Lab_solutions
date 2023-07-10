#include <stdio.h>

void printLinesWithLineNumbers(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening the file.\n");
        return;
    }

    int lineNumber = 1;
    int currentChar;

    while ((currentChar = fgetc(file)) != EOF) {
        printf("%d ", lineNumber);

        while (currentChar != EOF && currentChar != '\n') {
            putchar(currentChar);
            currentChar = fgetc(file);
        }

        putchar('\n');
        lineNumber++;
    }

    fclose(file);
}

int main() {
    char filename[256] = "hello.txt";

    printLinesWithLineNumbers(filename);

    return 0;
}
