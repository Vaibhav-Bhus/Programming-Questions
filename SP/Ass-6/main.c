#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
#define ad_max 5
#define is_max 11
#define reg_max 4
#define cond_max 6

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
char reg[4][10] = {"AREG","BREG","CREG","DREG"};
char ad[5][10] = {"START","END","ORIGIN","EQU","LTORG"};
char is[11][10] = 	{"STOP","ADD","SUB","MULT","MOVER","MOVEM","COMP","BC","DIV","READ","PRINT"};
char cond[6][10] = {"LT","LE","GT","GE","EQ","ANY"};
int reg_search(char s[])
{
    int i;
    for(i=0; i<reg_max; i++)
    {
        if(strcmp(reg[i],s)==0)
            return i;
    }
    return -1;
}
int ad_search(char s[])
{
    int i;
    for(i=0; i<ad_max; i++)
    {
        if(strcmp(ad[i],s)==0)
            return i;
    }
    return -1;
}
int is_search(char s[])
{
    int i;
    for(i=0; i<is_max; i++)
    {
        if(strcmp(is[i],s)==0)
            return i;
    }
    return -1;
}
int cond_search(char s[])
{
    int i;
    for(i=0; i<cond_max; i++)
    {
        if(strcmp(cond[i],s)==0)
            return i;
    }
    return -1;
}
int sym_search(char tok[])
{
    int i;
    for(i=0; i<sym_count; i++)
    {
        if(strcmp(s[i].sym,tok)==0)
            return i;
    }
    return -1;
}
int lit_search(char s[])
{
    int i;
    for(i=pool_table[pool_count]; i<lit_count; i++)
    {
        if(strcmp(l[i].lit,s)==0)
            return i;
    }
    return -1;
}
void display_sym_table()
{
    int i;
    fp2=fopen("Symbol.txt","w");
    printf("Symbol\tAddress\n");
    for(i=0; i<sym_count; i++)
    {
        fprintf(fp2,"%s\t%d\n",s[i].sym,s[i].addr);
        printf("%s\t%d\n",s[i].sym,s[i].addr);
    }
    fclose(fp2);
}
void display_lit_table()
{
    int i;
    fp2=fopen("Literal.txt","w");
    printf("Count\tLiteral\tAddress\n");
    for(i=0; i<lit_count; i++)
    {
        printf("%d\t%s\t%d\n",i,l[i].lit,l[i].addr);
        fprintf(fp2,"%d\t%s\t%d\n",i,l[i].lit,l[i].addr);
    }
    fclose(fp2);
}
void display_pool_table()
{
    int i;
    printf("index\tBase\n");
    fp2=fopen("pooltab.txt","w");
    for(i=0; i<pool_count; i++)
    {
        fprintf(fp2,"%d\t%d\n",i,pool_table[i]);
        printf("%d\t%d\n",i,pool_table[i]);
    }
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
    while(fgets(buffer,80,fp))
        printf("%s",buffer);
    fclose(fp);
}
void onePass()
{
    fp1 = fopen("input.txt","r");
    if(fp1==NULL)
    {
        printf("Can't open file 1\n");
        exit(0);
    }
    fp2 = fopen("output.txt","w");
    if(fp2==NULL)
    {
        printf("Can't open file 2\n");
        exit(0);
    }
    while(fgets(buffer,80,fp1))
    {
        strcpy(tok1," ");
        strcpy(tok2," ");
        strcpy(tok3," ");
        strcpy(tok4," ");
        token_count	= sscanf(buffer,"%s %s %s %s",tok1,tok2,tok3,tok4);
        switch(token_count)
        {
        case 1:
            i = is_search(tok1);
            if(i==0)
            {
                fprintf(fp2,"(IS, %02d)\n",i);
                break;
            }
            i = ad_search(tok1);
            if(i==0)
            {
                fprintf(fp2,"(AD, %02d)\n",i+1);
                lc = -1;
                break;
            }
            if(i==1 || i==4)
            {
                fprintf(fp2,"(AD, %02d)\n",i+1);
                for(k=pool_table[pool_count]; k<lit_count; k++)
                    l[k].addr = lc++;
                pool_table[++pool_count] = lit_count;
                lc--;
            }
            break;
        case 2:
            i = ad_search(tok1);
            if(i==0 || i==2)
            {
                lc = atoi(tok2)-1;
                fprintf(fp2,"(AD, %02d) (C, %02d)\n",i+1,lc+1);
                break;
            }
            i = is_search(tok1);
            if(i==9 || i==10)
            {
                j = sym_search(tok2);
                if(j==-1)
                {
                    fprintf(fp2,"(IS, %02d) (S,%02d)\n",i,sym_count+1);
                    strcpy(s[sym_count++].sym,tok2);
                    break;
                }
                else
                    fprintf(fp2,"(IS, %02d) (S, %02d)\n",i,j+1);
            }
            break;
        case 3:
            i = is_search(tok1);
            if(i>=1 && i<=9)
            {
                if(tok3[0]=='=')
                {
                    j = lit_search(tok3);
                    if(j==-1)
                    {
                        sprintf(temp,"(L, %02d)",lit_count+1);
                        strcpy(l[lit_count++].lit,tok3);
                    }
                    else
                        sprintf(temp,"(L, %02d)",j+1);
                }
                else
                {
                    j = sym_search(tok3);
                    if(j==-1)
                    {
                        sprintf(temp,"(S, %02d)",sym_count+1);
                        strcpy(s[sym_count++].sym,tok3);
                    }
                    else
                        sprintf(temp,"(S, %02d)",j+1);
                }
                tok2[strlen(tok2)-1] = '\0';
                if(i==7)
                    j = cond_search(tok2);
                else
                    j = reg_search(tok2);
                fprintf(fp2,"(IS, %02d) (%d) %s\n",i,j+1,temp);
                break;
            }
            if(strcmp(tok2,"DC")==0)
            {
                j = sym_search(tok1);
                if(j==-1)
                {
                    strcpy(s[sym_count].sym,tok1);
                    s[sym_count++].addr = lc;
                }
                else
                    s[j].addr = lc;
                fprintf(fp2,"(DL, 01) (C, %02d)\n",atoi(tok3+1));
                break;
            }
            if(strcmp(tok2,"DS")==0)
            {
                j = sym_search(tok1);
                if(j==-1)
                {
                    strcpy(s[sym_count].sym,tok1);
                    s[sym_count++].addr = lc;
                }
                else
                    s[j].addr = lc;
                lc = lc + atoi(tok3)-1;
                fprintf(fp2,"(DL, 02) (C, %02d)\n",atoi(tok3));
                break;
            }
            j = ad_search(tok2);
            if(j==3)
            {
                i = sym_search(tok1);
                k = sym_search(tok3);
                if(i==-1)
                {
                    strcpy(s[sym_count].sym,tok1);
                    s[sym_count++].addr = s[k].addr;
                }
                else
                    s[j].addr = s[k].addr;
                fprintf(fp2,"(AD, %02d)\n",j+1);
                lc--;
                break;
            }
            break;
        case 4:
            j = sym_search(tok1);
            if(j==-1)
            {
                strcpy(s[sym_count].sym,tok1);
                s[sym_count++].addr = lc;
            }
            else
                s[j].addr = lc;
            i = is_search(tok2);
            if(i>=1 && i<=9)
            {
                if(tok4[0]=='=')
                {
                    j = lit_search(tok4);
                    if(j==-1)
                    {
                        sprintf(temp,"(L, %02d)",lit_count+1);
                        strcpy(l[lit_count++].lit,tok4);
                    }
                    else
                        sprintf(temp,"(L, %02d)",j+1);
                }
                else
                {
                    j = sym_search(tok4);
                    if(j==-1)
                    {
                        sprintf(temp,"(S, %02d)",sym_count+1);
                        strcpy(s[sym_count++].sym,tok4);
                    }
                    else
                        sprintf(temp,"(S, %02d)",j+1);
                }
                tok3[strlen(tok3)-1] = '\0';
                if(i==7)
                    j = cond_search(tok3);
                else
                    j = reg_search(tok3);
                fprintf(fp2,"(IS, %02d) (%d) %s\n",i,j+1,temp);
                break;
            }
            break;
        }
        lc++;
    }
    fclose(fp1);
    fclose(fp2);
}

void twoPass()
{
    lc = 0;
    fp2 = fopen("output.txt","r");
    fp = fopen("final.txt","w");
    while(fgets(buffer,80,fp2))
    {


        token_count	= sscanf(buffer,"%s %s %s %s %s",tok1,tok2,tok3,tok4,tok5);   //MOVER A, B
        tok1[strlen(tok1)-1]='\0';
        tok2[strlen(tok2)-1]='\0';
        //tok3[strlen(tok3)-1]='\0';
        tok4[strlen(tok4)-1]='\0';                 //index  lit  addr
        tok5[strlen(tok5)-1]='\0';				  //  0	  ='9'   206
        //printf("%s\n",tok1);                    //  1   ='5'   212

        switch(token_count)
        {
        case 2:                                                  //index  base_of_lit
            tok3[strlen(tok3)-1]='\0';                           // 0        0
            if(strcmp(tok1+1,"AD")==0)	// LTORG, END            // 1        1
            {
                for(j=0; j<pool_count; j++)
                    if(l[pool_table[j]].addr==lc)
                        break;
                for(i=pool_table[j]; i<pool_table[j+1]; i++)
                {
                    strcpy(temp,l[i].lit);
                    temp[strlen(temp)-1]='\0';                           //='9
                    fprintf(fp,"%d) + 00 0 %03d\n",lc++,atoi(strstr(temp,"'")+1));
                }
                lc--;
            }
            else if(strcmp(tok1+1,"IS")==0)// STOP
            {
                fprintf(fp,"%d) + 00 0 000\n",lc);
            }
            break;

        case 4:
            //printf("%s",tok1+1);
            tok3[strlen(tok3)-1]='\0';
            if(strcmp(tok1+1,"AD")==0)	// START, ORIGIN
            {
                lc = atoi(tok4)-1;
            }

            else if(strcmp(tok1+1,"IS")==0)	// READ, PRINT
            {
                fprintf(fp,"%d) + %02d 0 %03d\n",lc,atoi(tok2),s[atoi(tok4)].addr);
            }
            else if(strcmp(tok1+1,"DL")==0)
            {
                if(atoi(tok2)==1)		   		// DS == 01
                {
                    for(i=0; i<atoi(tok4); i++)
                        fprintf(fp,"%d)\n",lc++);
                    lc--;
                }
                else if(atoi(tok2)==0)			    	// DC
                {
                    fprintf(fp,"%d) + 00 0 %03d\n",lc,atoi(tok4));
                }
            }
            break;

        case 5:
            /*Tok2[strlen(Tok2)-1]='\0';
            Tok3[strlen(Tok3)-1]='\0';
            Tok5[strlen(Tok5)-1]='\0';*/
            if(tok4[1]=='S')		// ADD-DIV with symbols
            {
                fprintf(fp,"%d) + %02d %d %03d\n",lc,atoi(tok2),atoi(tok3),s[atoi(tok5)].addr);
            }
            else if(tok4[1]=='L')		// ADD-DIV with literals
            {
                fprintf(fp,"%d) + %02d %d %03d\n",lc,atoi(tok2),atoi(tok3),l[atoi(tok5)].addr);
            }
            break;


        }
        lc++;
    }
    fclose(fp2);
    fclose(fp);

}

int main()
{
    onePass();
    print_file("output.txt");
    twoPass();
    print_file("final.txt");
    return 0;
}
