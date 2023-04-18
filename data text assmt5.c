#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int main() {
    FILE *dataFile = fopen("data.txt", "r");
    FILE *statisticsFile = fopen("statistics.txt", "w");

    if (dataFile == NULL) {
        printf("Failed to open data.txt\n");
        return 1;
    }

    if (statisticsFile == NULL) {
        printf("Failed to create statistics.txt\n");
        fclose(dataFile);
        return 1;
    }

    int letterCounts[ALPHABET_SIZE] = {0};
    char c;

    while ((c = fgetc(dataFile)) != EOF) {
        if (isalpha(c)) {
            
            c = toupper(c);
        
            letterCounts[c - 'A']++;
        }
    }

    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        fprintf(statisticsFile, "%c: %d\n", 'A' + i, letterCounts[i]);
    }

    fclose(dataFile);
    fclose(statisticsFile);

    printf("Letter statistics written to statistics.txt\n");

    return 0;
}
