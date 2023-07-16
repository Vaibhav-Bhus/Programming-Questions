#include<iostream>
#include<cstring>

using namespace std;
class Bank
{
    int acno;
    char nm[100], acctype[100];
    float bal;

public:
    void initial(int acc_no, char *name, char *acc_type, float balance)
    {
        acno = acc_no;
        strcpy(nm, name);
        strcpy(acctype, acc_type);
        bal = balance;
    }
    void deposit()
    {
        int damt1;
        cout<<"\nEnter Deposit Amount = ";
        cin>>damt1;
        bal+=damt1;
    }
    void withdraw()
    {
        int wamt1;
        cout<<"\nEnter Withdraw Amount = ";
        cin>>wamt1;
        if(wamt1>bal)
            cout<<"\nCannot Withdraw Amount Insufficient Balance.";
        else if(wamt1 <= bal)
        {
            bal-=wamt1;
            cout<<"\nRemaining Balance:"<<bal;
        }

    }
    void display()
    {
        cout<<"\n\n";
        cout<<"\nAccount No. : "<<acno;
        cout<<"\nName : "<<nm;
        cout<<"\nAccount Type : "<<acctype;
        cout<<"\nBalance : "<<bal;
    }
};


int main()
{
    int acc_no, ch;
    char name[100], acc_type[100];
    float balance;

    cout<<"Enter Customer Account No.:  ";
    cin>>acc_no;
    cout<<"Enter Customer Name : ";
    cin>>name;
    cout<<"Enter Customer Account Type : ";
    cin>>acc_type;
    cout<<"Enter Customer Opening Balance : ";
    cin>>balance;

    Bank bank;
    bank.initial(acc_no, name, acc_type, balance);
    do
    {
        cout<<"\n------------BANK DETAILS-------------- "<< endl;
        cout<<"\n1.Deposit an Amount\n2. Withdraw an Amount \n3. To Display Account Details\n4. Exit\nEnter Your Choice : ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            bank.deposit();
            break;
        case 2:
            bank.withdraw();
            break;
        case 3:
            bank.display();
            break;
        case 4:
            exit (1);
            break;
        default :
            cout << "\nINVALID CHOICE !!";
            break;
        }
    }
    while(ch!=4);
}
