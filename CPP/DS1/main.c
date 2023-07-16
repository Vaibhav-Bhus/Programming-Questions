#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#define MAX 100
char opstk[MAX];
char ch[MAX], postfix[MAX];
int i = 0, j = 0;
int top = -1;

int tEle()
{
    if (top == -1)
        exit(0);
    else
        return opstk[top];
}
int empty()
{
    if (top == -1)
        return -1;
    else
        return 1;
}
void push(char a)
{

    else
        opstk[++top] = a;
}
char pop()
{
    if (top == -1)
        exit(0);
    else
        return opstk[top--];
}
int priority(char f)
{
    switch (f)
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

    printf("Enter the infix expression");
    scanf("%s",ch);
    while (ch[i] != '\0')
    {
        char c = ch[i];
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '1' &&c <= '9')
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push('(');
        }
        else if (c == ')')
        {
            while (empty() && tEle() != '(')
            {
                postfix[j++] += tEle();
                pop();
            }
            pop();
        }
        else
        {
            while (empty() && priority(opstk[top]) >= priority(c))
                postfix[j++] = pop();
            if (!empty() || priority(opstk[top]) < priority(c))
            {
                push(c);
            }
        }
        i++;
    }
    while (empty())
    {
        postfix[j++] = tEle();
        pop();
    }
    postfix[j] = '\0';
    printf("%s",postfix);
    return 0;
}
