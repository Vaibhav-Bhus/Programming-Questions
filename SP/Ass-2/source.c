#include<stdio.h>#include<stdlib.h>intmain(){FILE*fp;charch;fp=fopen("sample.txt","r");if(fp==NULL)perror("Errorwhileopeningthefile.");printf("Thecontentsoffileare:");while((ch=fgetc(fp))!=EOF)printf("%c",ch);printf("FileContentReadSuccessfully.");fclose(fp);return0;}