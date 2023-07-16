#include <stdio.h>
#include <string.h>
struct Employee
{

};
int main()
{
    FILE *fptr;
    fptr=fopen("demo.txt","w");
    if(fptr == NULL)
        printf("\nError:File cannot be opened");
    else
    {
        int n;
        printf("Enter total number of records to add:");
        scanf("%d",&n);
        struct Employee e[n];
        for(int i=0; i<n; i++)
        {

        }
        for(int i=0; i<n; i++)
        {
            fwrite(&e[i],sizeof(e[i]),1,fptr);
            fprintf(fptr,"\n");
        }
        int id;
        printf("Enter Employee ID : ");
        scanf("%d",&id);
        for(int i=0; i<n; i++)
        {
            fread(&e[i],sizeof(e[i]),1,fptr);
            if(e[i].em_id == id)
            {
                printf("_____Employee Details____\n");
                printf("Id : %d\n",e[i].em_id);
                printf("Name : %s\n",e[i].name);
                printf("Salary : %.2f\n",e[i].sal);
                fclose(fptr);
                return 0;
            }
        }
        printf("%d ID not found",id);
    }
    fclose(fptr);
    return 0;
}
