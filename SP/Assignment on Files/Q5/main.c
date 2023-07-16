#include <stdio.h>
#include <stdlib.h>
int main()
{
    int upper = 0, lower = 0, digit = 0, special_symbol = 0;
    char ch;
    FILE *fp;
    fp = fopen("sample.txt", "r");
    if(fp==NULL)
        printf("File Not found");
    while(1)
    {
        if ((ch=fgetc(fp)) == EOF)
            break;
        else if (ch >= 'A' && ch <= 'Z')
            upper++;
        else if (ch >= 'a' && ch <= 'z')
            lower++;
        else if (ch >= '0' && ch <= '9')
            digit++;
        else
            special_symbol++;
    }
    fclose(fp);

    printf("\nUppercase: %d\nLowercase: %d\nNumbers: %d\nSpecial Symbol: %d", upper, lower, digit, special_symbol);
    return 0;
}
