#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
struct sym_table
{
    char sym[15];
    int addr;
} s[max];
struct lit_table
{
    char lit[5];
    int addr;
} l[max];
int pool_table[max],sym_count=0,lit_count=0,pool_count=0,token_count=0,lc=-1,i,j,k;
char tok1[max],tok2[max],tok3[max],tok4[max],tok5[max],buffer[80],temp[max];
FILE *fp1,*fp2,*fp;
void Read_symbol_table()
{
    int i=0;
    fp2=fopen("Symbol.txt","r");
    printf("Symbol\tAddress\n");
    while(fscanf(fp2,"%s\t%d",s[i].sym,&s[i].addr)!=EOF)
    {
        printf("%s\t%d\n",s[i].sym,s[i].addr);
        ++i;
    }
    sym_count=i;
    fclose(fp2);
}
void Read_literal_table()
{
    int i=0;
    fp2=fopen("Literal.txt","r");
    printf("Count\tLiteral\tAddress\n");
    while(fscanf(fp2,"%d\t%s\t%d",&i,l[i].lit,&l[i].addr)!=EOF)
    {
        printf("%d\t%s\t%d\n",i,l[i].lit,l[i].addr);
        ++i;
    }
    lit_count=i;
    fclose(fp2);
}
void Read_pooltab()
{
    int i=0;
    fp2=fopen("pooltab.txt","r");
    printf("index\tBase\n");
    while(fscanf(fp2,"%d\t%d\n",&i,&pool_table[i])!=EOF)
    {
        printf("%d\t%d\n",i,pool_table[i]);
        ++i;
    }
    pool_count=i;
    fclose(fp2);
}
void print_file(char fn[])
{
    FILE *fp = fopen(fn,"r");
    if(fp==NULL)
    {
        printf("Can't open file\n");
        exit(0);
    }
    while(fgets(buffer,80,fp)) printf("%s",buffer);
    fclose(fp);
}
void twoPass()
{
    lc = 0,i=0;
    fp2 = fopen("output.txt","r");
    fp = fopen("final.txt","w");
    while(fgets(buffer,80,fp2))
    {
        token_count = sscanf(buffer,"%s %s %s %s %s",tok1,tok2,tok3,tok4,tok5);
        tok1[strlen(tok1)-1]='\0';
        tok2[strlen(tok2)-1]='\0';
        tok3[strlen(tok3)-1]='\0';
        tok4[strlen(tok4)-1]='\0';
        tok5[strlen(tok5)-1]='\0';
        switch(token_count)
        {
        case 2:
            tok3[strlen(tok3)-1]='\0';
            if(strcmp(tok1+1,"AD")==0)
            {
                for(j=0; j<=pool_count; j++) if(l[pool_table[j]].addr==lc) break;
                for(i=pool_table[j]; i<pool_table[j+1]; i++)
                {
                    strcpy(temp,l[i].lit);
                    temp[strlen(temp)-1]='\0';
                    fprintf(fp,"%d) + 00 0 %03d\n",lc++,atoi(strstr(temp,"'")+1));
                }
                if(strcmp(tok2,"02")==0)
                {
                    strcpy(temp,l[pool_table[pool_count-1]].lit);
                    temp[strlen(temp)-1]='\0';
                    fprintf(fp,"%d) + 00 0 %03d\n",lc++,atoi(strstr(temp,"'")+1));
                }
                lc--;
            }
            else if(strcmp(tok1+1,"IS")==0) fprintf(fp,"%d) + 00 0 000\n",lc);
            break;
        case 4:
            tok3[strlen(tok3)-1]='\0';
            if(strcmp(tok1+1,"AD")==0) lc = atoi(tok4)-1;
            else if(strcmp(tok1+1,"IS")==0) fprintf(fp,"%d) + %02d 0 %03d\n",lc,atoi(tok2),s[atoi(tok4)-1].addr);
            else if(strcmp(tok1+1,"DL")==0)
            {
                if(atoi(tok2)==2) fprintf(fp,"%d)\n",lc);
                else if(atoi(tok2)==1) fprintf(fp,"%d) + 00 0 %03d\n",lc,atoi(tok4));
            }
            else
            {
                fprintf(fp,"%d)\n",lc);
            }
            break;
        case 5:
            if(tok4[1]=='S')
                fprintf(fp,"%d) + %02d %d %03d\n",lc,atoi(tok2),atoi(tok3+1),s[atoi(tok5)-1].addr);
            else if(tok4[1]=='L') fprintf(fp,"%d) + %02d %d %03d\n",lc,atoi(tok2),atoi(tok3+1),l[atoi(tok5)-1].addr);
            break;
        }
        lc++;
    }
    fclose(fp2);
    fclose(fp);
}
int main()
{
    printf("\n*****************************************\n");
    Read_symbol_table();
    printf("\n*****************************************\n");
    Read_literal_table();
    printf("\n*****************************************\n");
    Read_pooltab();
    printf("\n*****************************************\n");
    twoPass();
    print_file("final.txt");
}
