#include<iostream>
using namespace std;
int main()
{

    float num1,num2;
    int ch;

    cout<<"1. Addition \n" ;
    cout<<"2. Subtraction\n";
    cout<<"3. Multiplication\n";
    cout<<"4. Division\n";
    cout<<"Enter Your Choice.... ";
    cin>>ch;

    cout<<"\n Enter Two Numbers : \n";
    cin>>num1>>num2;

    switch (ch)

    {
    case 1:
        cout<<"The Addition result is: "<<num1+num2;
        break;

    case 2:
        cout<<"The Subtraction result is: "<<num1-num2;
        break;

    case 3:
        cout<<"The Multiplication result is: "<<num1*num2;
        break;

    case 4:
        cout<<"The Division result is: "<<num1/num2;
        break;
    }

}
