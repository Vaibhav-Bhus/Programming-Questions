#include <iostream>

using namespace std;

double area(double r,double pi=3.14)
{
    return pi*r*r;
}
int main()
{
    double r;
    cout<<"Enter radius:";
    cin>>r;
    cout<<"\nArea of circle:"<<area(r);
}
