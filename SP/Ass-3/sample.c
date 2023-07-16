//C Program
/*  Vaibhav Bhus
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
   FILE *fp;
   char ch;
   fp = fopen("sample.txt", "r");

   if (fp == NULL)
      perror("Error while opening the file.\n");

   printf("The contents of file are: \n");

   while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);
    printf("\n\nFile Content Read Successfully.");
   fclose(fp);
   return 0;
}


