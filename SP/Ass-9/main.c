#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct mnt
{
    char name[30];
    int PP, KP, EV, MDTP, KPDTP, SSTP;
} Mnt;

typedef struct pntab
{
    char name[30];
} Pntab;

typedef struct evntab
{
    char name[30];
} Evntab;

typedef struct ssntab
{
    char name[30];
} Ssntab;

typedef struct kpdtab
{
    char name[30], value[30];
} Kpdtab;

typedef struct aptab
{
    char value[30];
} Aptab;

typedef struct evtab
{
    char value[30];
} Evtab;

typedef struct sstab
{
    int MDT_entry;
} Sstab;

typedef struct mdt
{
    char label[30], opcode[30], operand[30];
} Mdt;

void printMNT(int);
void printPNTAB(int);
void printEVNTAB(int);
void printSSNTAB(int);
void printKPDTAB(int);
void printAPTAB(int);
void printEVTAB(int);
void printSSTAB(int);
void printMDT(int);
int opcode(char*);
int inPNTAB(char*, int);
int inEVNTAB(char*, int);
int inSSNTAB(char*, int);
void expandMacro(int, int);

Mnt MNT[2];
Pntab PNTAB[2][20];
Evntab EVNTAB[2][20];
Ssntab SSNTAB[2][20];
Kpdtab KPDTAB[2][20];
Aptab APTAB[2][20];
Evtab EVTAB[2][20];
Sstab SSTAB[2][20];
Mdt MDT[2][50];

int PNTAB_ptr[2] = {1, 1}, SSNTAB_ptr[2] = {1, 1}, APTAB_ptr[2] = {1, 1}, EVTAB_ptr[2] = {1, 1};
int SSTAB_ptr[2] = {5, 5}, KPDTAB_ptr[2] = {10, 10}, MDT_ptr[2] = {25, 25};
int n = 0;

int main()
{
    FILE* input = fopen("input.txt", "r");
    char** s, statement[100];

    if(input == NULL)
    {
        printf("\nError while opening the files !!\n");
        exit(0);
    }

    printf("-----input-----\n");
    fscanf(input, "%[^\n]", statement);
    fgetc(input);
    puts(statement);

    s = (char**)malloc(40);

    s[0] = strtok(statement, " \t");

    if(s[0] != NULL && !strcmp(s[0], "MACRO"))
    {
        MNT[n].MDTP = MDT_ptr[n];
        MNT[n].KPDTP = KPDTAB_ptr[n];
        MNT[n].SSTP = SSTAB_ptr[n];
    }
    else
    {
        printf("\nFirst statement must be MACRO\n");
        exit(0);
    }

    int t = 0;

    while(!feof(input))
    {
        strcpy(statement, "");

        fscanf(input, "%[^\n]", statement);
        fgetc(input);
        puts(statement);

        int i = 0;

        s[0] = strtok(statement, " \t.&");

        if(s[0] == NULL)
            continue;

        if(!strcmp(s[0], "MEND"))
        {
            n++;
            t = 0;
            continue;
        }

        if(!strcmp(s[0], "MACRO"))
        {
            MNT[n].MDTP = MDT_ptr[n];
            MNT[n].KPDTP = KPDTAB_ptr[n];
            MNT[n].SSTP = SSTAB_ptr[n];
            continue;
        }

        while(s[i] != NULL)
            s[++i] = strtok(NULL, " \t,&+().");

        if(t == 0)
        {
            strcpy(MNT[n].name, s[0]);
            //puts(MNT[n].name);
            t++;

            for(int j = 1; j < i; j++)
            {
                if(strchr(s[j], '=') != NULL)
                {
                    char* t;

                    t = strtok(s[j], " =");

                    strcpy(PNTAB[n][PNTAB_ptr[n]].name, t);
                    strcpy(KPDTAB[n][KPDTAB_ptr[n]].name, t);

                    t = strtok(NULL, "");
                    strcpy(KPDTAB[n][KPDTAB_ptr[n]].value, t);

                    MNT[n].KP++;
                    PNTAB_ptr[n]++;
                    KPDTAB_ptr[n]++;
                }
                else
                {
                    strcpy(PNTAB[n][PNTAB_ptr[n]].name, s[j]);

                    MNT[n].PP++;
                    PNTAB_ptr[n]++;
                }
            }
        }
        else
        {
            int k = 0;

            if(inPNTAB(s[k], n))
            {
                sprintf(MDT[n][MDT_ptr[n]].label, "%s", PNTAB[n][inPNTAB(s[k], n)].name);
                k++;
            }
            else if(inEVNTAB(s[k], n))
            {
                sprintf(MDT[n][MDT_ptr[n]].label, "(E,%d)", inEVNTAB(s[k], n));
                k++;
            }
            else if(!opcode(s[k]) && opcode(s[k + 1]))
            {
                strcpy(SSNTAB[n][SSNTAB_ptr[n]].name, s[k]);
                SSNTAB_ptr[n]++;

                SSTAB[n][SSTAB_ptr[n]].MDT_entry = MDT_ptr[n];
                SSTAB_ptr[n]++;
                k++;
            }

            strcpy(MDT[n][MDT_ptr[n]].opcode, s[k++]);
            char t[30];

            switch(opcode(s[k - 1]))
            {
            case 1:
                for(int j = k; j < i; j++)
                {
                    if(inPNTAB(s[j], n))
                        sprintf(t, "(P,%d)", inPNTAB(s[j], n));
                    else if(inEVNTAB(s[j], n))
                        sprintf(t, "(E,%d)", inEVNTAB(s[j], n));
                    else
                        sprintf(t, s[j]);

                    strcat(MDT[n][MDT_ptr[n]].operand, t);

                    if(j == k)
                        strcat(MDT[n][MDT_ptr[n]].operand, ",");
                    else if(j < i - 1)
                        strcat(MDT[n][MDT_ptr[n]].operand, "+");
                }

                break;

            case 2:
                MNT[n].EV++;

                for(int j = k; j < i; j++)
                {
                    sprintf(MDT[n][MDT_ptr[n]].operand, "(E,%d)", EVTAB_ptr[n]);

                    strcpy(EVNTAB[n][EVTAB_ptr[n]].name, s[j]);
                    EVTAB_ptr[n]++;
                }

                break;

            case 3:
                for(int j = k; j < i; j++)
                {
                    if(inPNTAB(s[j], n))
                        sprintf(t, "(P,%d)", inPNTAB(s[j], n));
                    else if(inEVNTAB(s[j], n))
                        sprintf(t, "(E,%d)", inEVNTAB(s[j], n));
                    else
                        sprintf(t, s[j]);

                    strcat(MDT[n][MDT_ptr[n]].operand, t);

                    if(j < i - 1)
                        strcat(MDT[n][MDT_ptr[n]].operand, "+");

                    if(inEVNTAB(s[0], n) && strlen(EVTAB[n][inEVNTAB(s[0], n)].value) == 0)
                        strcpy(EVTAB[n][inEVNTAB(s[0], n)].value, s[j]);
                }

                break;

            case 4:
                strcat(MDT[n][MDT_ptr[n]].operand, "(");

                for(int j = k; j < i; j++)
                {
                    if(inPNTAB(s[j], n))
                        sprintf(t, "(P,%d)", inPNTAB(s[j], n));
                    else if(inEVNTAB(s[j], n))
                        sprintf(t, "(E,%d)", inEVNTAB(s[j], n));
                    else
                        sprintf(t, s[j]);

                    if(j == i - 1)
                    {
                        strcat(MDT[n][MDT_ptr[n]].operand, ")");
                        sprintf(t, "(S,%d)", inSSNTAB(s[j], n));
                        strcat(MDT[n][MDT_ptr[n]].operand, t);
                    }
                    else
                        strcat(MDT[n][MDT_ptr[n]].operand, t);
                }

                break;

            default:
                for(int j = k; j < i; j++)
                {
                    if(inPNTAB(s[j], n))
                        sprintf(t, "(P,%d)", inPNTAB(s[j], n));
                    else if(inEVNTAB(s[j], n))
                        sprintf(t, "(E,%d)", inEVNTAB(s[j], n));
                    else
                        sprintf(t, s[j]);

                    strcat(MDT[n][MDT_ptr[n]].operand, t);

                    if(j < i - 1)
                        strcat(MDT[n][MDT_ptr[n]].operand, ",");
                }
            }

            MDT_ptr[n]++;
        }
    }

    char call[100];
    printf("\nMacro Call: ");
    gets(call);

    int i = 0;

    s[0] = strtok(call, " \t");

    while(s[i] != NULL)
        s[++i] = strtok(NULL, " \t&,");

    for(int j = 1; j < i; j++)
    {
        if(strchr(s[j], '=') != NULL)
        {
            char* t;

            t = strtok(s[j], " =");
            t = strtok(NULL, "");

            strcpy(APTAB[0][APTAB_ptr[0]].value, t);
            APTAB_ptr[0]++;
        }
        else
        {
            strcpy(APTAB[0][APTAB_ptr[0]].value, s[j]);
            APTAB_ptr[0]++;
        }
    }

    t = MNT[0].KPDTP;

    for(int j = APTAB_ptr[0]; j < MNT[0].PP + MNT[0].KP + 1; j++)
        strcpy(APTAB[0][APTAB_ptr[0]++].value, KPDTAB[0][t++].value);



    printf("\nExpanded Macro:\n");

    expandMacro(0, -1);

    return 0;
}

void printMNT(int j)
{
    printf("\nMNT:\n");
    printf("Name\t\t|#PP\t|#KP\t|#EV\t|MDTP\t|KPDTP\t|SSTP\n");
    printf("--------------------------------------------------------------\n");
    printf("%-16s|%d\t|%d\t|%d\t|%d\t|%d\t|%d\n", MNT[j].name, MNT[j].PP, MNT[j].KP, MNT[j].EV, MNT[j].MDTP, MNT[j].KPDTP, MNT[j].SSTP);
}

void printPNTAB(int j)
{
    printf("\nPNTAB:\n");
    printf("Pointer\t|Parameter Name\n");
    printf("-----------------------\n");

    for(int i = 1; i < PNTAB_ptr[j]; i++)
        printf("%d\t|%s\n", i, PNTAB[j][i].name);
}

void printEVNTAB(int j)
{
    printf("\nEVNTAB:\n");
    printf("Pointer\t|EV Name\n");
    printf("----------------\n");

    for(int i = 1; i < EVTAB_ptr[j]; i++)
        printf("%d\t|%s\n", i, EVNTAB[j][i].name);
}

void printSSNTAB(int j)
{
    printf("\nSSNTAB:\n");
    printf("Pointer\t|SS Name\n");
    printf("----------------\n");

    for(int i = 1; i < SSNTAB_ptr[j]; i++)
        printf("%d\t|%s\n", i, SSNTAB[j][i].name);
}

void printKPDTAB(int j)
{
    printf("\nKPDTAB:\n");
    printf("Pointer\t|Parameter Name\t|Default Value\n");
    printf("---------------------------------------\n");

    for(int i = MNT[j].KPDTP; i < KPDTAB_ptr[j]; i++)
        printf("%d\t|%s\t\t|%s\n", i, KPDTAB[j][i].name, KPDTAB[j][i].value);
}

void printAPTAB(int j)
{
    printf("\nAPTAB:\n");
    printf("Pointer\t|Value\n");
    printf("----------------\n");

    for(int i = 1; i < APTAB_ptr[j]; i++)
        printf("%d\t|%s\n", i, APTAB[j][i].value);
}

void printEVTAB(int j)
{
    printf("\nEVTAB:\n");
    printf("Pointer\t|Value\n");
    printf("----------------\n");

    for(int i = 1; i < EVTAB_ptr[j]; i++)
        printf("%d\t|%s\n", i, EVTAB[j][i].value);
}

void printSSTAB(int j)
{
    printf("\nSSTAB:\n");
    printf("Pointer\t|MDT Entry\n");
    printf("----------------\n");

    for(int i = MNT[j].SSTP; i < SSTAB_ptr[j]; i++)
        printf("%d\t|%d\n", i, SSTAB[j][i].MDT_entry);
}

void printMDT(int j)
{
    printf("\nMDT:\n");
    printf("Pointer\t|Label\t|Opcode\t|Operand\n");
    printf("---------------------------------\n");

    for(int i = MNT[j].MDTP; i < MDT_ptr[j]; i++)
        printf("%d\t|%s\t|%s\t|%s\n", i, MDT[j][i].label, MDT[j][i].opcode, MDT[j][i].operand);
}

int opcode(char* s)
{
    if($(ADD) || $(SUB) || $(MULT) || $(MOVER) || $(MOVEM) || $(DIV) || $(READ) || $(PRINT) || $(MEND))
        return 1;

    if($(LCL))
        return 2;

    if($(SET))
        return 3;

    if($(AIF) || $(AGO))
        return 4;

    return 0;
}

int inPNTAB(char* s, int n)
{
    for(int i = 1; i < PNTAB_ptr[n]; i++)
        if($1(PNTAB[n][i].name))
            return i;

    return 0;
}

int inEVNTAB(char* s, int n)
{
    for(int i = 1; i < EVTAB_ptr[n]; i++)
        if($1(EVNTAB[n][i].name))
            return i;

    return 0;
}

int inSSNTAB(char* s, int n)
{
    for(int i = 1; i < SSNTAB_ptr[n]; i++)
        if($1(SSNTAB[n][i].name))
            return i;

    return 0;
}

void expandMacro(int j, int call_ptr)
{
    if(call_ptr > -1)
    {
        char** s;
        s = (char**)malloc(40);

        int i = 0;
        s[0] = strtok(MDT[j - 1][call_ptr].operand, " \t,()");

        while(s[i] != NULL)
            s[++i] = strtok(NULL, " \t,()");

        for(int k = 0; k < i; k++)
        {
            if(!strcmp(s[k], "P"))
                strcpy(APTAB[j][APTAB_ptr[j]++].value, APTAB[j - 1][atoi(s[++k])].value);
            else if(!strcmp(s[k], "E"))
                strcpy(EVNTAB[j][EVTAB_ptr[j]++].name, EVNTAB[j - 1][atoi(s[++k])].name);
            else if(!strcmp(s[k], "S"))
                strcpy(SSNTAB[j][SSNTAB_ptr[j]++].name, SSNTAB[j - 1][atoi(s[++k])].name);
            else if(strchr(s[k], '=') != NULL)
            {
                char* t;

                t = strtok(s[k], " =");
                t = strtok(NULL, "");

                strcpy(APTAB[j][APTAB_ptr[j]++].value, t);
            }
        }

        int temp = MNT[j].KPDTP;

        for(int k = APTAB_ptr[j]; k < MNT[j].PP + MNT[j].KP + 1; k++)
            strcpy(APTAB[j][APTAB_ptr[j]++].value, KPDTAB[j][temp++].value);
    }

    for(int i = MNT[j].MDTP; i < MDT_ptr[j]; i++)
    {
        if(!opcode(MDT[j][i].opcode))
            expandMacro(j + 1, i);
        else
        {
            printf("+ %s\t%s\t", MDT[j][i].label, MDT[j][i].opcode);

            char** s;
            s = (char**)malloc(40);

            int t = 0;
            s[0] = strtok(MDT[j][i].operand, " \t,()");

            while(s[t] != NULL)
                s[++t] = strtok(NULL, " \t,()");

            for(int k = 0; k < t; k++)
            {
                if(!strcmp(s[k], "P"))
                    printf("%s", APTAB[j][atoi(s[++k])].value);
                else if(!strcmp(s[k], "E"))
                    printf("%s", EVNTAB[j][atoi(s[++k])].name);
                else if(!strcmp(s[k], "S"))
                    printf("%s", SSNTAB[j][atoi(s[++k])].name);
                else
                    printf("%s", s[k]);

                if(k < t - 1)
                    printf(",");
            }

            printf("\n");
        }
    }
}
