#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
int front = -1, rear = -1;
int queue[maxsize];

int isEmpty()
{
    if(rear==front)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if(rear==maxsize-1)
    {
        return 1;
    }
    return 0;
}

void enqueue()
{
    int item;
    printf("\nEnter the element");
    scanf("%d", &item);
    if(isFull())
    {
        printf("\nStack Overflow.");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
        rear = rear+1;
    queue[rear] = item;
    printf("\nValue inserted.");

}

void dequeue()
{
    int item;
    if (isEmpty())
    {
        printf("\nStack Underflow.");
        return;
    }
    else
    {
        item = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1 ;
        }
        else
            front = front + 1;
        printf("\nValue Deleted ");
    }


}

void display()
{
    int i;
    if(isEmpty())
        printf("\nEmpty queue\n");
    else
    {
        printf("\nElements in Queue");
        for(i=front; i<=rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
}


void main ()
{
    int ch;
    while(ch != 4)
    {

        printf("\n\n\n1.Insert An Element \n2.Delete An Element \n3.Display The Queue \n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter valid choice.\n");
        }
    }
}
