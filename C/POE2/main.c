#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head;
void insert_beg();
void delete_end()
void del_mid();
void count_node();
void update_node();
void display();

void main ()
{
    int choice =0;
    while(choice != 8)
    {
        printf("\n1.Insert at beg\n\n2.Delete from Middle\n3.Delete from end\n4.Count all nodes \n5.Update a node\n6.Display\n7.Exit\n");
        printf("\nEnter your choice : ");
        scanf("\n%d",&choice);

        switch(choice)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            delete_mid();
            break;
        case 3:
            delete_end();
            break;
        case 4:
            count_node();
            break;
        case 5:
            update_node();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("\nError : Invalid Choice");
        }
    }
}

void insert_beg()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Item value : ");
        scanf("%d",&item);

        if(head==NULL)
        {
            ptr->next = NULL;
            ptr->prev=NULL;
            ptr->data=item;
            head=ptr;
        }
        else
        {
            ptr->data=item;
            ptr->prev=NULL;
            ptr->next = head;
            head->prev=ptr;
            head=ptr;
        }
        printf("\nNode inserted\n");
    }

}

void delete_end()
{
    struct node *temp,*p;
    if(head==NULL)
    {
        printf("\nList is empty");
        return head;
    }
    if(head->next==NULL)
    {
        temp=head;
        head->next;
        printf("\n%d deleted",temp->data);
        free(temp);
        return head;
    }
    temp=head;
    while((temp->next)!=NULL) temp=temp->next;
    p=temp->prev;
    p->next=NULL;
    printf("\n%d node deleted\n",temp->data);
    free(temp);
    return head;
}


void delete_mid()
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the data after which the node is to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    while(ptr -> data != val)
        ptr = ptr -> next;
    if(ptr -> next == NULL)
    {
        printf("\nCan't delete\n");
    }
    else if(ptr -> next -> next == NULL)
    {
        ptr ->next = NULL;
    }
    else
    {
        temp = ptr -> next;
        ptr -> next = temp -> next;
        temp -> next -> prev = ptr;
        free(temp);
        printf("\n%d node deleted\n",temp->data);
    }
}
void display()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nList is Empty !!\n");
        return;
    }
    printf("\n Elements are :\n");
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void update_node()
{
    int New, old, pos;
    printf("Enter old element : ");
    scanf("%d", &old);
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp = head;

    if(head==NULL)
    {
        printf("Linked List not initialized");
        return;
    }

    while(temp != NULL)
    {
        if(temp -> data == old)
        {
            printf("\nEnter the new element : ");
            scanf("%d",&New);
            temp -> data = New;
            return ;
        }
        else
        {
            temp = temp ->next;
            pos++;
        }
    }

    printf("%d does not exist.\n", old);
}
void count_node()
{
    struct node* temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    printf("Total No of nodes is : %d\n", cnt);
}
