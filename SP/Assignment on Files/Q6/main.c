#include <stdio.h>
#include <stdlib.h>
struct emplyee
{
    char name[20];
    int age;
    float salary;
} s;
void main()
{
    FILE *fp;
    int n, i;
    printf("Enter number of Employees: \n");
    scanf("%d",&n);
    fp = fopen("emp.txt", "w");
    if (fptr == NULL)
        printf("File does not exist.\n");
    for(i=0; i<n; ++i)
    {
        printf("Enter name: ");
        scanf("%s", &s.name);
        fprintf(fp, "Name = %s\n", s.name);
        printf("Enter the age:");
        scanf("%d", &s.age);
        fprintf(fptr, "Age = %d\n", s.age);
        printf("Enter the salary:");
        scanf("%f", &s.salary);
        fprintf(fptr, "Salary = %.2f\n", s.salary);
    }
    fclose(fptr);
}
