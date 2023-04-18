#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL) {
        printf("Failed to open input.txt\n");
        return 1;
    }

    if (outputFile == NULL) {
        printf("Failed to create output.txt\n");
        fclose(inputFile);
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        char *found = strstr(line, "red");
        while (found != NULL) {
            
            strncpy(found, "blue", 4);
            found = strstr(found + 4, "red"); 
        }

        fputs(line, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Text successfully replaced and written to output.txt\n");

    return 0;
}
