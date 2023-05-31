#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
 printf("Welcome to editit 2.0.0\n");
    printf("Made by Shourjjo Majumder, open source and contributions from many developers! https://github.com/shourdev/editit\n");
    printf("Enter the name of the file you want to open or create: ");
    char file_name[100];
    fgets(file_name, sizeof(file_name), stdin);

    // Remove newline character
    file_name[strcspn(file_name, "\n")] = '\0';

    FILE *file = fopen(file_name, "r+");
    if (file == NULL)
    {
        file = fopen(file_name, "w+");
        if (file == NULL)
        {
            printf("Error opening/creating file\n");
            return 1;
        }
    }
    printf("\nFile Content:\n");
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        putchar(c);
    }
    rewind(file); // Move the file pointer to the beginning of the file

    printf("\n\nType your changes and press enter. Type :gotoit to go to a line, :catit to see how the file is now and :quitit to save and exit.\n");
    char input[100];
    int i = 0;
    while (1)
    {
        printf(">> ");
        fflush(stdin);
        fgets(input, 99, stdin);
        input[strlen(input) - 1] = 0;
        if (strcmp(input, ":quitit") == 0)
        {
            break;
        }
        else if (strcmp(input, ":gotoit") == 0)
        {
            int j = 0, l = 1, n;
            printf("What line you want to go? ");
            scanf("%d", &n);
            rewind(file);
            while (l != n)
            {
                j++;
                if(fgetc(file) == '\n'){
                    l++;
                }
            }
            i = j;
            fseek(file, j, SEEK_SET);
        }
        else if (strcmp(input, ":catit") == 0)
        {
            char c;
            rewind(file);
            while ((c = fgetc(file)) != EOF)
            {
                putchar(c);
            }
            fseek(file, i, SEEK_SET);
        }
        else
        {
            fputs(input, file); // Write the input to the file
            fprintf(file, "\n");
            i += strlen(input);
        }
    }

    fclose(file);

    return 0;
}
