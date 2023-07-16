#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 50

FILE *fp;
int key = 0, op = 0, comma = 1, var = 0, special_symbol = 0;
char str[max];
char c;

void IsKeyword()
{
    if (!strcmp(str, "auto") || !strcmp(str, "double") || !strcmp(str, "int") || !strcmp(str, "struct") || !strcmp(str, "break") || !strcmp(str, "else") || !strcmp(str, "long") || !strcmp(str, "switch") || !strcmp(str, "case") || !strcmp(str, "enum") || !strcmp(str, "register") || !strcmp(str, "typedef") || !strcmp(str, "char") || !strcmp(str, "extern") || !strcmp(str, "return") || !strcmp(str, "union") || !strcmp(str, "continue") || !strcmp(str, "for") || !strcmp(str, "signed") || !strcmp(str, "do") || !strcmp(str, "if") || !strcmp(str, "static") || !strcmp(str, "while") || !strcmp(str, "default") || !strcmp(str, "goto") || !strcmp(str, "sizedof") || !strcmp(str, "volatile") || !strcmp(str, "const")|| !strcmp(str, "float") || !strcmp(str, "short") || !strcmp(str, "unsigned"))
        key++;
}

void IsOperator()
{
    if(c == '+'|| c == '-' || c == '%' ||c == '*' || c == '/')
        op++;
}

void IsSpecialSymbol()
{
    if(c == '`' || c == '~' || c == '!' || c == '@' || c == '#' || c == '$' || c == '^' || c == '&' || c == ')' || c == '(' || c == '_' || c == '=' || c == '}' || c == '{' || c == '[' || c == ']' || c == ':' || c == ';' || c == '"' || c == '>' || c == '<' || c == ',' || c == '.' || c == '?' || c =='|')
        special_symbol++;
}

void CountVariable()
{
    char ch;
    if(!strcmp(str, "int")||!strcmp(str, "float")||!strcmp(str, "double")||!strcmp(str, "char")||!strcmp(str, "long")||!strcmp(str, "short")||!strcmp(str, "FILE"))
    {
        comma = 1;
        while(1)
        {
            ch = fgetc(fp);
            if(ch == ',')
                comma++;
            else if(ch ==';')
            {
                var = var + comma;
                return;
            }
        }
    }
}

int main()

{
    fp = fopen("sample.c", "r");
    while (fscanf(fp, "%s",str) != EOF)
    {
        IsKeyword(str);
        CountVariable(str);
    }
    fclose(fp);

    fp = fopen("sample.c", "r");
    while ((c = fgetc(fp)) != EOF)
    {
        IsOperator(c);
        IsSpecialSymbol(c);
    }
    fclose(fp);
    printf("No. Of Keywords = %d", key);
    printf("\nNo. Of Operators = %d", op);
    printf("\nNo. Of Special Symbols = %d", special_symbol);
    printf("\nNo. Of Variables = %d", var);
    return (0);
}


