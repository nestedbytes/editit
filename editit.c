#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to editit\n");
    printf("Enter the name of the file you want to open or create: ");
    char file_name[100];
    scanf("%s", file_name);
    FILE *file = fopen(file_name, "a+"); // Open or create the file in append mode
    if (file == NULL) {
        printf("Error opening/creating file\n");
        return 1;
    }

    printf("\nFile Content:\n");
    char c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
    rewind(file); // Move the file pointer to the beginning of the file

    printf("\n\nType your changes and press enter. Type ':quitit' to save and exit.\n");
    char input[100];
    while (1) {
        printf(">> ");
        scanf("%s", input);
        if (strcmp(input, ":quitit") == 0) {
            break;
        }
        fprintf(file, "%s\n", input); // Write the input to the file
    }

    fclose(file);

    return 0;
}
