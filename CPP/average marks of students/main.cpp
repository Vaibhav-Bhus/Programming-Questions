#include<iostream>
#include<conio.h>

using namespace std;

//copy
class CopyConstructor
{
    int var, fact;

public:
    CopyConstructor(int temp)
    {
        var = temp;
    }


    int fact_fun()
    {
        fact = 1;
        for (int i = 1; i <= var; i++)
        {
            fact = fact * i;
        }
        return fact;

    }
};

//para
class ParameterizeConstrutor
{
public:
    long int fact=1;
    int num;
    int input();
    void fact_function();
    void display();
    ParameterizeConstrutor(int);
};

ParameterizeConstrutor::ParameterizeConstrutor(int a)
{
    num=a;
}

void ParameterizeConstrutor::fact_function()
{

    for(int i=1; i<=num; i++)
    {
        fact=fact*i;

    }
}

void ParameterizeConstrutor::display()
{
    cout<<" Factorial of " << num <<" is: "<<fact<< " using Parameterize Constructor"<<endl;
}



int main()
{
    int n;

    cout << "\nEnter the Number : ";
    cin>>n;

    CopyConstructor obj(n);

    CopyConstructor cpy = obj;

    cout << " Factorial of " << n << " is: " << obj.fact_fun()<< " using Default Constructor"<<endl;
    cout << " Factorial of " << n << " is: " << cpy.fact_fun()<< " using Copy Constructor"<<endl;

    ParameterizeConstrutor object(n);

    object.fact_function();
    object.display();

    return 0;
}
