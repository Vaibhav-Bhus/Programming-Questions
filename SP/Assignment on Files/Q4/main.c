#include <stdio.h>
#define max 100
int main()
{
    char name[max];
    int marks, n, rn;
    printf("Enter number of students:\n");
    scanf("%d", &n);
    FILE *fp;
    fp = (fopen("sample.txt","a"));

    if(fp == NULL)
    {
        printf("Error!");
        exit(1);
    }

    for (int i=1; i<=n; ++i)
    {
        printf("\nEnter Roll no: ");
        scanf("%d", &rn);
        printf("For student%d\nEnter name: ", i);
        scanf("%s", name);
        printf("Enter marks: ");
        scanf("%d", &marks);

        fprintf(fp, "\nRoll no.: %d \nName: %s \nMarks = %d \n", rn, name, marks);
        printf("\nRoll no.: %d\nName: %s \nMarks = %d \n", rn, name, marks);
    }
    fclose(fp);
    return 0;
}
