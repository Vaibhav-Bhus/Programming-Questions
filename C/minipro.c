#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define max 100
void delemp();
void bill();
void sale();
void purchase();
void modify_pro();
void employee_menu();
void menu();
void admin_menu();

int n=1,empch,empflag=0,i=0,emp_delch,ak=1;
int emp_menu_ch;
int modcode,modch,empcode,empmch;
int q=0,dcount=4;
int ad_flag=0,admin_ch,delete_ch,delete_count=0;
char ad_ch;
int i,flag=1,del_count=0,chdel;
char ch;
char nullStr[20]="    ";
struct b_pch
{
    int p_code,qty;
    float amt,rate;
    char name[20];
}pc[max];

struct employee
{
    char    name[max];
    int     empId;
    long int ph_no;
    float   salary;
} emp[max];

struct pro_info
{
    char name[max];
    int code,quantity;
    float price;

} p[max];

int main()
{

    printf("\t\t*********************************\n\n");
    printf("\t\t  SUPERMARKET MANAGEMENT SYSTEM  \n\n");
    printf("\t\t*********************************\n\n");
    menu();
}


void menu()
{
    int ch;
    char ch1;
mmenu:
    printf("\n\n\n    MAIN MENU   \n");
    printf("\n  1. Billing  \n");
    printf("\n  2. Administration \n");
    printf("\n  3. Employees\n");
    printf("\n  4. Exit \n");
    printf("\nPlease enter your choice :... ");
    fflush(stdin);
    scanf("%d",&ch);
    fflush(stdin);
    switch(ch)
    {
    case 1:
        system("cls");
        bill();
        menu();
        break;

    case 2:
        system("cls");
        admin_menu();
        break;

    case 3:
        system("cls");
        employee_menu();
        break;

    case 4:
        system("cls");
        printf("\n Do you really want to exit \n [Y: Yes / N: NO]\nEnter your choice :...");
        fflush(stdin);
        scanf("%c",&ch1);
        fflush(stdin);
        if(ch1=='Y'||ch1=='y')
        {
            exit(0);
        }
        else if(ch1=='N'||ch1=='n')
        {
            goto mmenu;
        }
        else
        {
            printf("\n Invalid Choice\n");
        }
        break;

    default:
        printf("\n Invalid Choice\n\n Please enter your choice (1-3)\n");
        system("cls");
        goto mmenu;
    }

}



void admin_menu()
{
    system("cls");
admin_menu:
    printf("\n\t ADMIN MENU  \n");
    printf("\n 1. Create Product \n\n 2. Display all Product \n\n 3. Modify Product \n\n 4. Delete Product \n\n 5. Back to MAIN MENU \n\n Enter your choice : ");
    scanf("%d",&admin_ch);
    switch(admin_ch)
    {
    case 1:
        system("cls");
        i=q;
        do
        {
            printf("Do you want to ADD more Products\n\n [Y : YES / N : NO] : ");
            fflush(stdin);
            scanf("%c",&ch);
            fflush(stdin);
            if(ch=='Y'||ch=='y')
            {
                ad_flag++;
                printf("\n\tEnter product Name     : ");
                fflush(stdin);
                scanf("%s",p[i].name);
                fflush(stdin);
                printf("\n\tEnter product code     : ");
                scanf("%d",&p[i].code);
                printf("\n\tEnter product Quantity : ");
                scanf("%d",&p[i].quantity);
                printf("\n\tEnter product price    : ");
                scanf("%f",&p[i].price);


                flag++;
            }
            else if(ch=='N'||ch=='n')
            {
                system("cls");
                menu();
                break;

            }
            else
            {
                printf("\n Invalid Choice\n");
            }
            i++;
        }
        while(i<=flag);
        q=i;
        system("cls");
        menu();
        break;


    case 2:// Display
        system("cls");
        printf("\n Product Name\t Product code\t Quantity\t Price");
        if(del_count==0)
        {
            for(int j=0; j<ad_flag; j++)
            {
                printf("\n %s\t\t %d\t\t %d\t\t %f",p[j].name,p[j].code,p[j].quantity,p[j].price);
            }
        }
        else
        {
            for(int j=0; j<ad_flag-1; j++)
            {
                printf("\n %s\t\t %d\t\t %d\t\t %f",p[j].name,p[j].code,p[j].quantity,p[j].price);
            }
        }
        printf("\n\n");
        menu();
        break;

    case 3:
        //modify

        system("cls");
mod1:
        printf("Enter product code to be modified :");
        scanf("%d",&modcode);
        for(int h=0; h<ad_flag; h++)
        {
            if(modcode==p[h].code)
            {
                printf("Enter product name     :");
                fflush(stdin);
                gets(p[h].name);
                fflush(stdin);
                printf("Enter product Price    :");
                scanf("%f",&p[h].price);
                printf("Enter product quantity :");
                scanf("%d",&p[h].quantity);
            }
            else
            {
                printf("\nProduct not listed\n");
                goto mod1;
                break;
            }
        }
        printf("Do you want to continue :\n1.YES\n2.NO\nEnter your choice:...");
        scanf("%d",&modch);
        if(modch==1)
        {
            goto mod1;
            break;
        }
        else
        {
            menu();
        }
        break;

    case 4://delete
        system("cls");
dele:
        printf("Enter product code to be deleted : ");
        scanf("%d",&delete_ch);
        for(int k=0; k<flag; k++)
        {
            if(p[k].code==delete_ch)
            {
                del_count++;

                int temp1;
                temp1=p[k].code;
                p[k].code=p[k+1].code;
                p[k+1].code=temp1;

                strcpy(p[k].name, p[k+1].name);

                int temp2;
                temp2=p[k].quantity;
                p[k].quantity=p[k+1].quantity;
                p[k+1].quantity=temp2;

                float t;
                t=p[k].price;
                p[k].price=p[k+1].price;
                p[k+1].price=t;
            }
        }
        printf("Do you want to continue :\n1.YES\n2.NO\nEnter your choice:...");
        scanf("%d",&chdel);
        if(chdel==1)
        {
            goto dele;
        }
        else
        {
            admin_menu();
        }
        system("cls");
        menu();

        break;

    case 5:
        system("cls");
        menu();
        break;

    default:
        printf("\nInvalid choice\n");
        goto admin_menu;
    }

}
void delemp()
{

    printf("Enter employee ID to be deleted : ");
    scanf("%d",&emp_delch);
    for(int k=0; k<ak; k++)
    {
        if(emp_delch==emp[k].empId)
        {
            ak++;
            int tempemp1;
            tempemp1=emp[k].empId;
            emp[k].empId=emp[k+1].empId;
            emp[k+1].empId=tempemp1;

            strcpy(emp[k].name, emp[k+1].name);

            int tempemp2;
            tempemp2=emp[k].ph_no;
            emp[k].ph_no=emp[k+1].ph_no;
            emp[k+1].ph_no=tempemp2;

            float empq;
            empq=emp[k].salary;
            emp[k].salary=emp[k+1].salary;
            emp[k+1].salary=empq;
        }
        else
            printf("\nEmployee ID not Found\n");
    }
}
void employee_menu()
{
empmenu:
    printf("\n\t EMPLOYEES MENU\n\n1.Add Employee\n\n2.Delete Employee\n\n3.Edit Employee\n\n4.Display all Employees\n\n5.Main Menu\n\nEnter your choice :....");
    scanf("%d",&emp_menu_ch);
    switch(emp_menu_ch)
    {
    case 1://ADD
empcnd:
        system("cls");
        do
        {
            printf("\nDo you want to ADD more employee info \n\t1.YES\n\t2.NO\n\tEnter your choice :...");
            scanf("%d",&empch);
            if(empch==1)
            {
                n++;
                empflag++;

                printf("\nName        : ");
                fflush(stdin);
                gets(emp[i].name);
                printf("\nID : ");
                scanf("%d",&emp[i].empId);
                printf("\nContact No. : ");
                scanf("%ld",&emp[i].ph_no);
                printf("\nSalary      : ");
                scanf("%f",&emp[i].salary);

            }
            else if(empch==2)
            {
                system("cls");
                goto empmenu;

            }
            else
            {
                printf("Invalid choice");
                goto empcnd;
            }
            i++;
        }
        while(i<=n);

    case 2://DELETE
        system("cls");
        delemp();

    case 3://modify

        system("cls");
emp1:
        printf("Enter Employee ID to be modified :");
        scanf("%d",&empcode);

        for(int h=0; h<empflag; h++)
        {
            if(empcode==emp[h].empId)
            {
                printf("Enter Employee name    :");
                fflush(stdin);
                gets(p[h].name);
                printf("Enter Employee Contact :");
                scanf("%ld",&emp[h].ph_no);
                printf("Enter Employee salary  :");
                scanf("%f",&emp[h].salary);
                break;
            }
            else
            {
                printf("\nEmployee not listed\n");
                goto emp1;
                break;
            }
        }
        printf("Do you want to continue :\n1.YES\n2.NO\nEnter your choice:...");
        scanf("%d",&empmch);
        if(empmch==1)
        {
            goto emp1;
            break;
        }
        else
        {
            system("cls");
            menu();
        }
        break;



    case 4://DISPLAY
        system("cls");
        printf("\nEmployee Details are :\n");
        for(int i=0; i<empflag; i++)
        {
            printf("\nName      : %s\n",emp[i].name);
            printf("Id          : %d\n",emp[i].empId);
            printf("Contact No. : %ld\n",emp[i].ph_no);
            printf("Salary      : %f\n",emp[i].salary);
        }
        printf("\n\n");
        goto empmenu;
        break;



    case 5:
        system("cls");
        menu();
        break;


    default :
        printf("\n****Invalid choice***\n\n");


    }
}
void bill()
{
    int b_ch;
    system("cls");
    printf("\n\t BILL MENU\n\n1.Sale\n\n2.Purchase\n\n3.Main Menu\n\nEnter your choice...");
    scanf("%d",&b_ch);
    switch(b_ch)
    {
    case 1:
        system("cls");
        sale();
        break;
    case 2:
        system("cls");
        purchase();
        break;
    case 3:
        system("cls");
        menu();
        break;
    default:
        system("cls");
        bill();
    }
}

struct b_sale
{
    int s_code,qty;
    float amt,rate;
    char name[20];
}s[max];

void sale()
{
    system("cls");
    int s_ch,m,obb;
    char add[50],date[20],name[50];
    long int no;
    float di,amt2,tamt;
    m=0;
    system("cls");
    printf("Enter date:");
    scanf("%s",date);
    fflush(stdin);
    printf("Enter costumer name:");
    gets(name);
    printf("Enter costumer address:");
    gets(add);
    printf("Enter mobile number:");
    scanf("%ld",&no);
    billc:
        {
            printf("Enter product code");
            scanf("%d",&s[m].s_code);
            for(int t=0; t<max; t++)
            {
                if(s[m].s_code==p[t].code)
                {
                    strcpy(s[m].name, p[t].name);
                    s[m].rate=p[t].price;

                    printf("Enter quantity:");
                    scanf("%d",&s[m].qty);
                    p[t].quantity-=s[m].qty;
                    s[m].amt=s[m].rate*s[m].qty;
                    tamt=tamt+(s[m].rate*s[m].qty);



                }
            }
            billask:
            printf("\nDo you want to ADD more products\n\t1.YES\n\t2.NO\nEnter your choice:...");
            scanf("%d",&s_ch);
            if(s_ch==1)
            {
                m++;
                goto billc;
            }
            else if(s_ch==2)
            {
                printf("Enter discount on total amount:");
                scanf("%f",&di);
                printf("DO you want to print bill\n1.Yes\n2.no");
                scanf("%d",&obb);
                if(obb==1)
                    goto billout;
                else
                    goto billask;
            }
            else
            {
                printf("\n****Invalid choice****\n");
                goto billask;
            }



        }
        billout:
            printf("\n\n----------------------------------------------");
            printf("\n                     Sale invoice              ");
            printf("\n----------------------------------------------");
            printf("\nDate:");
            puts(date);
            printf("\n Costumer name:");
            puts(name);
            printf("\n costumer address:");
            puts(add);
            printf("\nMobile number:%ld",no);

            printf("\n product name\t product code\t quantity\t rate\t\t\t amount\n");

            for(int n=0;n<=m;n++)
            {

                puts(s[n].name);
                printf("\t\t%d\t\t%d\t\t%f\t   %f\n",s[n].s_code,s[n].qty,s[n].rate,s[n].amt);

            }
            printf("\n-------------------------------------------------------------------------------\n");
            printf("\n\n\t Amount              :%f\n",tamt);

           amt2=tamt-((tamt/100)*di);
           if(amt2>0)
            printf("\n\n\t Total Payable Amount:%f",amt2);
}

void purchase()
{
    system("cls");
    int p_ch,m,obb;
    char add[50],date[20],name[50];
    long int no;
    float di,amt2,tamt;
    m=0;
    system("cls");
    printf("Enter date:");
    scanf("%s",date);
    fflush(stdin);
    printf("Enter party name:");
    gets(name);
    printf("Enter party address:");
    gets(add);
    printf("Enter mobile number:");
    scanf("%ld",&no);
    billc:
        {
            printf("Enter product code");
            scanf("%d",&pc[m].p_code);
            for(int t=0; t<max; t++)
            {
                if(pc[m].p_code==p[t].code)
                {
                    strcpy(pc[m].name, p[t].name);
                    pc[m].rate=p[t].price;

                    printf("Enter quantity:");
                    scanf("%d",&s[m].qty);
                    p[t].quantity+=pc[m].qty;
                    pc[m].amt=pc[m].rate*pc[m].qty;
                    tamt=tamt+(pc[m].rate*pc[m].qty);



                }
            }
            billask:
            printf("Do you want to ADD more products\n\t1.YES\n\t2.NO\nEnter your choice:...");
            scanf("%d",&p_ch);
            if(p_ch==1)
            {
                m++;
                goto billc;
            }
            else if(p_ch==2)
            {
                printf("Enter discount on total amount:");
                scanf("%f",&di);
                printf("DO you want to print bill\n1.Yes\n2.no");
                scanf("%d",&obb);
                if(obb==1)
                    goto billout;
                else
                    goto billask;
            }
            else
            {
                printf("\n****Invalid choice****\n");
                goto billask;
            }



        }
        billout:
            printf("\n\n----------------------------------------------");
            printf("\n                        Purchase invoice        ");
            printf("\n----------------------------------------------");
            printf("\nDate:");
            puts(date);
            printf("\n\n Party name:");
            puts(name);
            printf("\n\n party address:");
            puts(add);
            printf("\n\nMobile number:%ld:",no);

            printf("\n\n product name\t product code\t quantity\t rate\t\t\t amount");

            for(int n=0;n<=m;n++)
            {

                puts(pc[n].name);
                printf("\t\t%d\t\t%d\t\t%f\t   %f",pc[n].p_code,pc[n].qty,pc[n].rate,pc[n].amt);

            }
            printf("\n-------------------------------------------------------------------------------\n");
            printf("\n\n\t Amount              :%f",tamt);

           amt2=tamt-((tamt/100)*di);
           if(amt2>0)
            printf("\n\n\t Total Payable Amount:%f",amt2);
}
