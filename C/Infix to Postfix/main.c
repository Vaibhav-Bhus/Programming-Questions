#include<stdio.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if(top == -1)
    {
        printf("Stack Overflow.");
        return -1;
    }
    else
        return stack[top--];
}

int priority(char x)
{
    switch (x)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int main()
{
    char infix[100];
    char *e, x;

    printf("Enter Infix expression : ");
    scanf("%s", infix);

    e = infix;

    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c", *e);

        else if(*e == '(')
            push(*e);

        else if(*e == ')')
            while((x = pop()) != '(')
                printf("%c", x);

        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());

            push(*e);
        }
        e++;
    }

    while(top != -1)
        printf("%c", pop());

    return 0;
}
