#include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    // Write to the file using fprintf
    fprintf(fp, "Hello, world!\n");
    fprintf(fp, "This is a test file.");

    // Close the file
    fclose(fp);

    return 0;
}