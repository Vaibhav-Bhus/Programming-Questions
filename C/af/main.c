#include <stdio.h>
#include<stdlib.h>
#define max 100

int length(char s[])
{
    int i = 0;
    while(s[i] != '\0')
        i++;
    return(i);
}

void concatenate(char s1[],char s2[])
{
    int i=0,j=0;
    while(s1[i]!='\0')
        i++;
    while(s2[j]!='\0')
    {
        s1[i]=s2[j];
        i++;
        j++;
    }
    s1[i]='\0';
    printf("Concatenated String : %s",s1);
}

void compare(char s1[],char s2[])
{
    int i=0,j=0;
    while(s1[i]==s2[j])
    {
        if(s1[i]!='\0'&&s2[j]!='\0')
        {
            i++;
            j++;
        }
        else
            break;
    }
    if(s1[i]=='\0'&&s2[j]=='\0')
        printf("Strings Are Same");
    else
        printf("Strings Are Not Same");
}

void copy(char s1[],char s2[])
{
    int i=0,j=0;
    while(s1[i]!='\0')
    {
        s2[i]=s1[i];
        i++;
    }
    s2[i]='\0';
    printf("\nAfter Copying String 1 is %s and String 2 is %s",s1,s2);
}

void lowercase(char s[])
{
    int l;
    l = length(s);
    for(int i=0;i<=l;i++)
    {
      if(s[i]>='A'&&s[i]<='Z')
         s[i]=s[i]+32;
    }
   printf("\nLower Case String is: %s",s);
}

void uppercase(char s[])
{
    int l;
    l = length(s);
    for(int i=0;i<=l;i++)
    {
      if(s[i]>='a'&&s[i]<='z')
         s[i]=s[i]-32;
    }
   printf("\nUpper Case String is: %s",s);
}

int main()
{
    char s1[max],s2[max];
    int c,x;
    printf("\n1. length of string \n2. copy strings \n3.concatenate two strings \n4. compare two strings \n5. Convert to uppercase \n6. Convert to lowercase\n7. Exit");
    do
    {
        printf("\nEnter Your Choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("Enter String:");
            scanf("%s",s1);
            x=length(s1);
            printf("Length of String: %d",x);
            break;
        case 2:
            printf("Enter first String:");
            scanf("%s",s1);
            printf("Enter Second String:");
            scanf("%s",s2);
            printf("Before Copying String 1 is %s and String 2 is %s",s1,s2);
            copy(s1,s2);
            break;
        case 3:
            printf("Enter first String:");
            scanf("%s",s1);
            printf("Enter Second String:");
            scanf("%s",s2);
            concatenate(s1,s2);
            break;
        case 4:
            printf("Enter first String:");
            scanf("%s",s1);
            printf("Enter Second String:");
            scanf("%s",s2);
            compare(s1,s2);
            break;
        case 5:
            printf("Enter String:");
            scanf("%s",s1);
            uppercase(s1);
            break;
        case 6:
            printf("Enter String:");
            scanf("%s",s1);
            lowercase(s1);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Choice");
        }
        printf("\n");
    }
    while(c!=7);
}
