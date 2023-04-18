#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *errorLogFile = fopen("error_log.txt", "w");

    if (inputFile == NULL) {
        printf("Failed to open input.txt\n");
        return 1;
    }

    if (errorLogFile == NULL) {
        printf("Failed to create error_log.txt\n");
        fclose(inputFile);
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        if (strstr(line, "error") != NULL) {
            fputs(line, errorLogFile);
        }
    }

    fclose(inputFile);
    fclose(errorLogFile);

    FILE *errorLogFileRead = fopen("error_log.txt", "r");

    if (errorLogFileRead == NULL) {
        printf("Failed to open error_log.txt\n");
        return 1;
    }

    printf("Contents of error_log.txt:\n");
    while (fgets(line, MAX_LINE_LENGTH, errorLogFileRead) != NULL) {
        printf("%s", line);
    }

    fclose(errorLogFileRead);

    return 0;
}
