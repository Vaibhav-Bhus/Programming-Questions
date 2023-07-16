#include<iostream>
using namespace std;

class factorial
{
public:
    int x;
    factorial()
    {
        cout<<"Enter Positive Number : ";
        cin>>x;

    }
    factorial(int a)
    {
        x = a;
    }
    factorial(factorial &a)
    {
        x = a.x;
    }
    int fact(int x)
    {
        if(x>=1)
            return x*fact(x-1);
        else
            return 1;

    }
    void display()
    {

        cout<<"Factorial of "<<x<<" = "<<fact(x)<<"\n";
    }

};
int main()
{
    factorial f1;
    f1.display();
    factorial f2(6);
    f2.display();
    factorial f3 = f2;
    f3.display();

}
