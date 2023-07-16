#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    char ch;
    fp=fopen("sample.txt","w");
    if(fp == NULL)
        printf("File is not present");
    printf("Enter data and press * after end : \n");
    while(1)
    {
        ch=getche();
        if(ch=='*')
            exit(0);
        putc(ch,fp);
    }
    return 0;
}
