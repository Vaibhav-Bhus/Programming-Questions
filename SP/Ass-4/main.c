#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct symbol
{
    char str[50];
};
int cnt = 1, add = 0;//declare starting addaress

void INT(char s[])
{


    int i = 3;
    if (add == 0)
        add = &s[4];
    printf("\n%d\t", cnt);
    while(1)
    {
        if(s[i] == ';')
        {
            printf("\tint\t  %d\t%d",sizeof(int), add);
            add+=sizeof(int);
            cnt++;
            return;
        }

        else if(s[i] == ',')
        {
            printf("\tint\t  %d\t%d",sizeof(int), add);
            add+=sizeof(int);
            cnt++;
            printf("\n%d\t", cnt);
        }
        else if(s[i] == ' ')
            printf("");
        else
            printf("%c", s[i]);
        i++;

    }
}

void FLOAT(char s[])
{
    int i = 5;
    if (add == 0)
        add = &s[6];
    printf("\n%d\t", cnt);
    while(1)
    {
        if(s[i] == ';')
        {
            printf("\tfloat\t  %d\t%d",sizeof(float), add);
            add+=sizeof(float);
            cnt++;
            return;
        }

        else if(s[i] == ',')
        {
            printf("\tfloat\t  %d\t%d",sizeof(float), add);
            add+=sizeof(float);
            cnt++;
            printf("\n%d\t", cnt);
        }
        else if(s[i] == ' ')
            printf("");
        else
            printf("%c", s[i]);
        i++;

    }
}

void DOUBLE(char s[])
{
    int i = 6;
    if (add == 0)
        add = &s[7];
    printf("\n%d\t", cnt);
    while(1)
    {
        if(s[i] == ';')
        {
            printf("\tdouble\t  %d\t%d",sizeof(double), add);
            add+=sizeof(double);
            cnt++;
            return;
        }

        else if(s[i] == ',')
        {
            printf("\tdouble\t  %d\t%d",sizeof(double), add);
            add+=sizeof(double);
            cnt++;
            printf("\n%d\t", cnt);
        }
        else if(s[i] == ' ')
            printf("");
        else
            printf("%c", s[i]);
        i++;

    }
}

void CHAR(char s[])
{
    int i = 4;
    if (add == 0)
        add = &s[5];
    printf("\n%d\t", cnt);
    while(1)
    {
        if(s[i] == ';')
        {
            printf("\tchar\t  %d\t%d",sizeof(char), add);
            add+=sizeof(char);
            cnt++;
            return;
        }

        else if(s[i] == ',')
        {
            printf("\tchar\t  %d\t%d",sizeof(char), add);
            add+=sizeof(char);
            cnt++;
            printf("\n%d\t", cnt);
        }
        else if(s[i] == ' ')
            printf("");
        else
            printf("%c", s[i]);
        i++;

    }
}

int main()
{
    int N;
    printf("Enter No. of Statements : ");
    scanf("%d", &N);
    struct symbol s[N];
    fflush(stdin);
    for (int i=0; i<N; i++)
    {
        printf("Enter Statement %d: ", i+1);
        fgets(s[i].str, sizeof(s[i].str), stdin);
    }
    printf("Sr_No\tSymbol\tType\tLength\tAddress");
    for (int i=0; i<N; i++)
    {
        if(strstr(s[i].str, "int"))
            INT(s[i].str);
        else if(strstr(s[i].str, "float"))
            FLOAT(s[i].str);
        else if(strstr(s[i].str, "double"))
            DOUBLE(s[i].str);
        else if(strstr(s[i].str, "char"))
            CHAR(s[i].str);
    }
}



