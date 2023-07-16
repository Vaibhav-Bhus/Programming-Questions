#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define $(x) !strcmp(s, #x)
#define $1(x) !strcmp(s, x)

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

void printMNT();
void printPNTAB();
void printEVNTAB();
void printSSNTAB();
void printKPDTAB();
void printAPTAB();
void printEVTAB();
void printSSTAB();
void printMDT();
int opcode(char*);
int inPNTAB(char*);
int inEVNTAB(char*);
int inSSNTAB(char*);

Mnt MNT;
Pntab PNTAB[20];
Evntab EVNTAB[20];
Ssntab SSNTAB[20];
Kpdtab KPDTAB[20];
Aptab APTAB[20];
Evtab EVTAB[20];
Sstab SSTAB[20];
Mdt MDT[50];

int PNTAB_ptr = 1, SSNTAB_ptr = 1, APTAB_ptr = 1, EVTAB_ptr = 1;
int SSTAB_ptr = 5, KPDTAB_ptr = 10, MDT_ptr = 25;

int main()
{
    FILE* input = fopen("input.txt", "r");
    char** s, statement[100];

    if(input == NULL)
    {
        printf("\nError while opening the files !!\n");
        exit(0);
    }

    printf("\n-----INPUT-----\n");
    fscanf(input, "%[^\n]", statement);
    fgetc(input);
    puts(statement);

    s = (char**)malloc(40);
    s[0] = (char*)malloc(40);
    s[1] = (char*)malloc(40);
    s[2] = (char*)malloc(40);

    s[0] = strtok(statement, " \t");

    if(s[0] != NULL && !strcmp(s[0], "MACRO"))
    {
        s[1] = strtok(NULL, " ");
        char t[40];

        sprintf(t, "(AD,01) (C,%d)\n", atoi(s[1]));

        MNT.MDTP = MDT_ptr;
        MNT.KPDTP = KPDTAB_ptr;
        MNT.SSTP = SSTAB_ptr;
    }
    else
    {
        printf("\nFirst statement must be MACRO\n");
        exit(0);
    }

    int t = 0;

    while(!feof(input))
    {
        fscanf(input, "%[^\n]", statement);
        fgetc(input);
        puts(statement);

        int i = 0;

        s[0] = strtok(statement, " \t.&");

        while(s[i] != NULL)
            s[++i] = strtok(NULL, " \t,&+().");

        if(t == 0)
        {
            strcpy(MNT.name, s[0]);
            t++;

            for(int j = 1; j < i; j++)
            {
                if(strchr(s[j], '=') != NULL)
                {
                    char* t;

                    t = strtok(s[j], " =");

                    strcpy(PNTAB[PNTAB_ptr].name, t);
                    strcpy(KPDTAB[KPDTAB_ptr].name, t);

                    t = strtok(NULL, "");
                    strcpy(KPDTAB[KPDTAB_ptr].value, t);

                    MNT.KP++;
                    PNTAB_ptr++;
                    KPDTAB_ptr++;
                }
                else
                {
                    strcpy(PNTAB[PNTAB_ptr].name, s[j]);

                    MNT.PP++;
                    PNTAB_ptr++;
                }
            }
        }
        else
        {
            int k = 0;

            if(inPNTAB(s[k]))
            {
                sprintf(MDT[MDT_ptr].label, "%s", PNTAB[inPNTAB(s[k])].name);
                k++;
            }
            else if(inEVNTAB(s[k]))
            {
                sprintf(MDT[MDT_ptr].label, "(E,%d)", inEVNTAB(s[k]));
                k++;
            }
            else if(!opcode(s[k]))
            {
                strcpy(SSNTAB[SSNTAB_ptr].name, s[k]);
                SSNTAB_ptr++;

                SSTAB[SSTAB_ptr].MDT_entry = MDT_ptr;
                SSTAB_ptr++;
                k++;
            }

            strcpy(MDT[MDT_ptr].opcode, s[k++]);
            char t[30];

            switch(opcode(s[k - 1]))
            {
            case 1:
                for(int j = k; j < i; j++)
                {
                    if(inPNTAB(s[j]))
                        sprintf(t, "(P,%d)", inPNTAB(s[j]));
                    else if(inEVNTAB(s[j]))
                        sprintf(t, "(E,%d)", inEVNTAB(s[j]));
                    else
                        sprintf(t, s[j]);

                    strcat(MDT[MDT_ptr].operand, t);

                    if(j == k)
                        strcat(MDT[MDT_ptr].operand, ",");
                    else if(j < i - 1)
                        strcat(MDT[MDT_ptr].operand, "+");
                }
                break;
            case 2:
                MNT.EV++;
                for(int j = k; j < i; j++)
                {
                    sprintf(MDT[MDT_ptr].operand, "(E,%d)", EVTAB_ptr);

                    strcpy(EVNTAB[EVTAB_ptr].name, s[j]);
                    EVTAB_ptr++;
                }
                break;
            case 3:
                for(int j = k; j < i; j++)
                {
                    if(inPNTAB(s[j]))
                        sprintf(t, "(P,%d)", inPNTAB(s[j]));
                    else if(inEVNTAB(s[j]))
                        sprintf(t, "(E,%d)", inEVNTAB(s[j]));
                    else
                        sprintf(t, s[j]);

                    strcat(MDT[MDT_ptr].operand, t);
                    if(j < i - 1)
                        strcat(MDT[MDT_ptr].operand, "+");

                    if(inEVNTAB(s[0]) && strlen(EVTAB[inEVNTAB(s[0])].value) == 0)
                        strcpy(EVTAB[inEVNTAB(s[0])].value, s[j]);
                }

                break;
            case 4:
                strcat(MDT[MDT_ptr].operand, "(");

                for(int j = k; j < i; j++)
                {
                    if(inPNTAB(s[j]))
                        sprintf(t, "(P,%d)", inPNTAB(s[j]));
                    else if(inEVNTAB(s[j]))
                        sprintf(t, "(E,%d)", inEVNTAB(s[j]));
                    else
                        sprintf(t, s[j]);

                    if(j == i - 1)
                    {
                        strcat(MDT[MDT_ptr].operand, ")");
                        sprintf(t, "(S,%d)", inSSNTAB(s[j]));
                        strcat(MDT[MDT_ptr].operand, t);
                    }
                    else
                        strcat(MDT[MDT_ptr].operand, t);
                }
                break;
            }
            MDT_ptr++;
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

            strcpy(APTAB[APTAB_ptr].value, t);
            APTAB_ptr++;
        }
        else
        {
            strcpy(APTAB[APTAB_ptr].value, s[j]);
            APTAB_ptr++;
        }
    }
    t = MNT.KPDTP;
    for(int j = APTAB_ptr; j < MNT.PP + MNT.KP + 1; j++)
        strcpy(APTAB[APTAB_ptr++].value, KPDTAB[t++].value);
    printMNT();
    printPNTAB();
    printEVNTAB();
    printSSNTAB();
    printKPDTAB();
    printAPTAB();
    printEVTAB();
    printSSTAB();
    printMDT();
    return 0;
}

void printMNT()
{
    printf("\nMNT:\n");
    printf("Name\t\t|#PP\t|#KP\t|#EV\t|MDTP\t|KPDTP\t|SSTP\n");
    printf("--------------------------------------------------------------\n");
    printf("%-16s|%d\t|%d\t|%d\t|%d\t|%d\t|%d\n", MNT.name, MNT.PP, MNT.KP, MNT.EV, MNT.MDTP, MNT.KPDTP, MNT.SSTP);
}

void printPNTAB()
{
    printf("\nPNTAB:\n");
    printf("Pointer\t|Parameter Name\n");
    printf("-----------------------\n");

    for(int i = 1; i < PNTAB_ptr; i++)
        printf("%d\t|%s\n", i, PNTAB[i].name);
}

void printEVNTAB()
{
    printf("\nEVNTAB:\n");
    printf("Pointer\t|EV Name\n");
    printf("----------------\n");

    for(int i = 1; i < EVTAB_ptr; i++)
        printf("%d\t|%s\n", i, EVNTAB[i].name);
}

void printSSNTAB()
{
    printf("\nSSNTAB:\n");
    printf("Pointer\t|SS Name\n");
    printf("----------------\n");

    for(int i = 1; i < SSNTAB_ptr; i++)
        printf("%d\t|%s\n", i, SSNTAB[i].name);
}

void printKPDTAB()
{
    printf("\nKPDTAB:\n");
    printf("Pointer\t|Parameter Name\t|Default Value\n");
    printf("---------------------------------------\n");

    for(int i = MNT.KPDTP; i < KPDTAB_ptr; i++)
        printf("%d\t|%s\t\t|%s\n", i, KPDTAB[i].name, KPDTAB[i].value);
}

void printAPTAB()
{
    printf("\nAPTAB:\n");
    printf("Pointer\t|Value\n");
    printf("----------------\n");

    for(int i = 1; i < APTAB_ptr; i++)
        printf("%d\t|%s\n", i, APTAB[i].value);
}

void printEVTAB()
{
    printf("\nEVTAB:\n");
    printf("Pointer\t|Value\n");
    printf("----------------\n");

    for(int i = 1; i < EVTAB_ptr; i++)
        printf("%d\t|%s\n", i, EVTAB[i].value);
}

void printSSTAB()
{
    printf("\nSSTAB:\n");
    printf("Pointer\t|MDT Entry\n");
    printf("----------------\n");

    for(int i = MNT.SSTP; i < SSTAB_ptr; i++)
        printf("%d\t|%d\n", i, SSTAB[i].MDT_entry);
}

void printMDT()
{
    printf("\nMDT:\n");
    printf("Pointer\t|Label\t|Opcode\t|Operand\n");
    printf("---------------------------------\n");

    for(int i = MNT.MDTP; i < MDT_ptr; i++)
        printf("%d\t|%s\t|%s\t|%s\n", i, MDT[i].label, MDT[i].opcode, MDT[i].operand);
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

int inPNTAB(char* s)
{
    for(int i = 1; i < PNTAB_ptr; i++)
        if($1(PNTAB[i].name))
            return i;

    return 0;
}

int inEVNTAB(char* s)
{
    for(int i = 1; i < EVTAB_ptr; i++)
        if($1(EVNTAB[i].name))
            return i;

    return 0;
}

int inSSNTAB(char* s)
{
    for(int i = 1; i < SSNTAB_ptr; i++)
        if($1(SSNTAB[i].name))
            return i;

    return 0;
}

