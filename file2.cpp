#include <stdio.h>

int main()
{
    FILE *file_ptr;
    char buffer[100]; // Buffer to store the read data

    // Open the file in read mode ("r")
    file_ptr = fopen("test.txt", "r");

    // Check if file was opened successfully
    if (file_ptr == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    // Read and print each line from the file
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file_ptr);

    return 0;
}
