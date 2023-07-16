#include <stdio.h>
#include <stdlib.h>

FILE *fp1,*fp2;

void tabsNewLine()
{
    char ch2;
    ch2 = fgetc(fp1);
    if(ch2 == 'n'||ch2 == 't')
        return;

}

void ifComment(char c)
{
    char ch;
    if(c == '\\')
        tabsNewLine();
    else if(c == '/')
    {
        ch = fgetc(fp1);
        if(ch == '*')
            multiLineComment();
        else if(ch == '/')
            singleLineComment();
    }
    else
        return;
}

void multiLineComment()
{
    char ch1, ch2;
    while((ch1=fgetc(fp1)) != EOF)
        if(ch1 == '*')
        {
            ch2 = fgetc(fp1);
            if(ch2 == '/')
                return;
        }
}

void singleLineComment()
{
    char ch;
    while((ch=fgetc(fp1)) != EOF)
        if(ch == '\n')
            return;
}




int main()
{
    char ch;
    fp1 = fopen("source.c", "r");
    fp2 = fopen("destination.c", "w");
    if(fp1 == NULL)
    {
        printf("Error while Opening the File");
        exit(0);
    }
    else
    {
        while((ch=fgetc(fp1)) != EOF)
        {
            ifComment(ch);
            if(ch==' '|| ch=='\n'||ch=='\t'||ch == '/' || ch == '\\')
                continue ;
            else
                fprintf(fp2, "%c", ch);
        }
    }
    printf("Comments and White Spaces removed\n\n");
    fclose(fp1);
    fclose(fp2);
    remove("source.c");
    rename("destination.c", "source.c");
    fp1 = fopen("source.c", "r");
    while((ch=fgetc(fp1)) != EOF)
        printf("%c",ch);
    fclose(fp1);
    return 0;
}

