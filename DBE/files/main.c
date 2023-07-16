#include<stdio.h>
struct student
{
    int rollno,phn,mark;
    char name[30],add[30];
} stud;

void Insert()
{
    FILE *fp;
    fp = fopen("student.txt", "a");
    printf("Enter the Roll no : ");
    scanf("%d", &stud.rollno);
    printf("Enter the Name : ");
    scanf("%s", &stud.name);
    printf("Enter phone no : ");
    scanf("%d", &stud.phn);
    printf("Enter the Address : ");
    scanf("%s", &stud.add);
    printf("Enter the mark : ");
    scanf("%d", &stud.mark);
    fwrite(&stud, sizeof(stud), 1, fp);
    fclose(fp);
}

void Display()
{
    FILE *fp1;
    fp1 = fopen("student.txt", "r");
    printf("\nRoll_No\tName\tPhone_no\tAddress\tMark\n");
    while (fread(&stud, sizeof(stud), 1, fp1))
        printf("%d\t%s\t%d\t\t%s\t%d\n", stud.rollno, stud.name, stud.phn, stud.add, stud.mark);
    fclose(fp1);
}

void DeleteRec()
{
    FILE *fpo;
    FILE *fpt;
    int r, s;
    printf("Enter the Roll no to be deleted :");
    scanf("%d", &r);
    if (avlrollno(r) == 0)
        printf("Roll no %d is not available in the file\n\n", r);
    else
    {
        fpo = fopen("student.txt", "r");
        fpt = fopen("student2.txt", "w");
        while (fread(&stud, sizeof(stud), 1, fpo))
        {
            s = stud.rollno;
            if (s != r)
                fwrite(&stud, sizeof(stud), 1, fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("student.txt", "w");
        fpt = fopen("student2.txt", "r");
        while (fread(&stud, sizeof(stud), 1, fpt))
            fwrite(&stud, sizeof(stud), 1, fpo);
        printf("\nDetails Deleted.\n\n");
        fclose(fpo);
        fclose(fpt);
    }

}

void Update()
{
    int avl;
    FILE *fpt;
    FILE *fpo;
    int s, r, ch;
    printf("Enter roll number to update:");
    scanf("%d", &r);
    avl = avlrollno(r);
    if (avl == 0)
        printf("\nRoll number %d is not Available in the file\n\n", r);
    else
    {
        fpo = fopen("student.txt", "r");
        fpt = fopen("student2.txt", "w");
        while (fread(&stud, sizeof(stud), 1, fpo))
        {
            s = stud.rollno;
            if (s != r)
                fwrite(&stud, sizeof(stud), 1, fpt);
            else
            {
                printf("\n\t1. Update Name");
                printf("\n\t2. Update Mark");
                printf("\n\t3. Update phone no");
                printf("\n\t4. Update Address");
                printf("\nEnter your choice : ");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                    printf("Enter Name :");
                    scanf("%s", &stud.name);
                    break;
                case 2:
                    printf("Enter Mark : ");
                    scanf("%d", &stud.mark);
                    break;
                case 3:
                    printf("Enter Phone no : ");
                    scanf("%d", &stud.phn);
                    break;
                case 4:
                    printf("Enter Address : ");
                    scanf("%s", &stud.add);
                    break;
                default:
                    printf("Invalid Option.");
                    break;
                }
                fwrite(&stud, sizeof(stud), 1, fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("student.txt", "w");
        fpt = fopen("student2.txt", "r");
        while (fread(&stud, sizeof(stud), 1, fpt))
            fwrite(&stud, sizeof(stud), 1, fpo);
        fclose(fpo);
        fclose(fpt);
        printf("\nRecord Updated\n\n");
    }
}

int avlrollno(int rno)
{
    FILE *fp;
    int c = 0;
    fp = fopen("student.txt", "r");
    while (!feof(fp))
    {
        fread(&stud, sizeof(stud), 1, fp);

        if (rno == stud.rollno)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int empty()
{
    int c = 0;
    FILE *fp;
    fp = fopen("student.txt", "r");
    while (fread(&stud, sizeof(stud), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}

void main()
{
    int c, emp;
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Update\n4. Display\n5. Exit\nEnter Your Choice : ");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
        case 1:
            Insert();
            break;
        case 2:
            DeleteRec();
            break;

        case 3:
            Update();
            break;
        case 4:
            emp = empty();
            if (emp == 0)
                printf("\nThe file is Empty\n\n");
            else
                Display();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("\nInvalid Option.\n\n");
            break;

        }
    }
}
