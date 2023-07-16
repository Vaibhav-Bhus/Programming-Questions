#include <stdio.h>
#define MAX 10

struct stack
{
    int stack[MAX];
    int top;
}s;


void push()
{
    int num;
    if (s.top == (MAX - 1))
    {
        printf ("Stack Overflow\n");
        return;
    }
    else
    {
        printf ("Enter the element to be pushed : \n");
        scanf ("%d", &num);
        s.top = s.top + 1;
        s.stack[s.top] = num;
    }
    return;
}

int pop()
{
    int num;
    if (s.top == - 1)
    {
        printf ("Stack Underflow\n");
        return (s.top);
    }
    else
    {
        num = s.stack[s.top];
        printf ("Popped Element Is = %d\n", s.stack[s.top]);
        s.top--;
    }
    return(num);
}

void display ()
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.stack[i]);
        }
    }
    printf ("\n");
}

void main ()
{

    int ch;
    s.top = -1;

    while (ch != 4)
    {
        printf ("\n\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf ("Enter your choice...");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid Option.");
        }
    }
}
