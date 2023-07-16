#include <stdio.h>
#include<math.h>
#include<ctype.h>
#define MAX 100

int stack[MAX];
int top =- 1;
int ch;
void push(int ele)
{
    if(top == MAX-1)
        printf("\n Stack Overflow. ");
    else
    {
        top++;
        stack[top] = ele;
    }
}

int pop()
{
    if(top == -1)
        printf("\n Stack Underflow. ");
    else
    {
        ch = stack[top];
        top--;
    }
    return ch;
}

void main()
{
    char postfix[MAX], ele;

    printf("Enter Postfix Expression:");
    scanf("%s", postfix);

    int i=0, a, b, val;

    while(postfix[i] != '\0')
    {
        ele = postfix[i];
        if(isdigit(ele))
        {
            push(ele - '0');
        }
        else
        {
            a = pop();
            b = pop();

            switch(ele)
            {
            case '^':
                val = pow(b, a);
                break;
            case '/':
                val = b/a;
                break;
            case '*':
                val = b*a;
                break;
            case '+':
                val = b+a;
                break;
            case '-':
                val = b-a;
                break;

            }
            push(val);
        }
        i++;
    }
    printf("\nResult = %d\n\n", pop());
}
