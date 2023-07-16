#include <stdio.h>
#include <stdlib.h>
#define max 100
int main()
{
    FILE *file;
    char str[max];
    char ch;
    int character = 0,lines = 0;
    file=fopen("sample.txt","r");
    if(file==NULL)
        printf("File is not available");

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n' || ch == '\0')
            lines++;
        character++;
    }
    if (character > 0)
        lines++;


    printf("\nTotal No of characters is %d", character);
    printf("\nTotal No of lines is %d\n", lines);
    fclose(file);
    return 0;
}
