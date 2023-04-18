#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float score;
} Student;

int main() {
    FILE *file = fopen("data.bin", "rb");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    Student student;
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        printf("ID: %d\n", student.id);
        printf("Name: %s\n", student.name);
        printf("Score: %.2f\n", student.score);
        printf("--------------------------\n");
    }

    fclose(file);
    return 0;
}
