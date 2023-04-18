#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() {
    char fileName[MAX_LINE_LENGTH];
    char searchString[MAX_LINE_LENGTH];

    
    printf("Enter the name of the file: ");
    fgets(fileName, MAX_LINE_LENGTH, stdin);

    
    fileName[strcspn(fileName, "\n")] = '\0';

    
    printf("Enter the search string: ");
    fgets(searchString, MAX_LINE_LENGTH, stdin);

    
    searchString[strcspn(searchString, "\n")] = '\0';

    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Failed to open file: %s\n", fileName);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(line, searchString) != NULL) {
            printf("%s", line);
            found = 1;
        }
    }

    fclose(file);

    if (!found) {
        printf("No lines containing the search string found.\n");
    }

    return 0;
}
