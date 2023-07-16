#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node* insertBeg(struct node *h, int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = h;
    h = temp;
    return h;
}

struct node* insertMid(struct node *h, int x, int k)
{
    struct node *temp,*p;
    p = h;
    while(p != NULL)
    {
        if((p->data) == k)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            temp->data = x;
            temp->next = p->next;
            p->next = temp;
            return h;
        }
        p = p->next;
    }
    printf("\n%d Does Not Exist", k);
    return h;
}
struct node* insertEnd(struct node *h, int x)
{
    struct node *temp, *p;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    p = h;
    if(p == NULL)
        h = temp;
    else
    {
        while((p->next) != NULL)
            p = p->next;
        p->next = temp;
    }
    return h;
}

struct node* deleteBeg(struct node *h)
{
    struct node *temp;
    temp = h;
    if(temp == NULL)
    {
        printf("\nList Is Empty");
        return h;
    }
    printf("\n%d Is Deleted", temp->data);
    h = h->next;
    free(temp);
    return h;
}

struct node* deleteEnd(struct node *h)
{
    struct node *temp, *ptemp;
    if(h == NULL)
    {
        printf("\nList Is Empty");
        return h;
    }
    if((h->next) == NULL)
    {
        temp = h;
        printf("\n%d Is Deleted", temp->data);
        h = h->next;
        free(temp);
        return h;
    }
    temp = h;
    while((temp->next) != NULL)
    {
        ptemp = temp;
        temp = temp->next;
    }
    printf("\n%d Is Deleted", temp->data);
    ptemp->next = NULL;
    free(temp);
    return h;
}

struct node* deleteMid(struct node *h, int x)
{
    struct node *temp,*p;
    if(h == NULL)
    {
        printf("\nList Is Empty");
        return h;
    }
    if((h->data) == x)
    {
        temp = h;
        h = h->next;
        free(temp);
        return h;
    }
    p = h;
    while((p->next) != NULL)
    {
        if((p->next)->data == x)
        {
            temp = p->next;
            p->next = temp->next;
            free(temp);
            return h;
        }
        p = p->next;
    }

    printf("\n%d Not Found", x);
    return h;
}

void display(struct node *h)
{
    struct node *temp;
    if(h == NULL)
    {
        printf("\nList Is Empty");
        return;
    }
    temp = h;
    printf("\nElements In List : \n");
    while(temp!=NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

void main()
{
    struct node *head = NULL;
    int ch, item, k;
    while(ch!=5)
    {
        printf("1.Insert Beginning \n2.Insert Middle \n3.Insert End\n4.Delete Beginning\n5.Delete Middle\n6.Delete End\n7.Display\n8.Exit\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter Element : ");
            scanf("%d", &item);
            head = insertBeg(head, item);
            break;
        case 2:
            printf("\nEnter Element : ");
            scanf("%d", &item);
            printf("After Which You Want To Insert : ");
            scanf("%d", &k);
            head = insertMid(head, item, k);
            break;
        case 3:
            printf("\nEnter Element : ");
            scanf("%d", &item);
            head = insertEnd(head, item);
            break;
        case 4:
            deleteBeg(head);
            break;
        case 5:
            printf("\nEnter Element You Want To Delete: ");
            scanf("%d", &item);
            deleteMid(head, item);
            break;
        case 6:
            deleteEnd(head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            exit(1);
        default:
            printf("\nInvalid Choice.");
        }
        printf("\n");
    }
}



