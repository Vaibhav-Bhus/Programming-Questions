#include<iostream>
#include<cmath>
using namespace std;

double power(double m,int n=2)
{
    double t;
    t=pow(m,n);
    return t;
}
int main()
{
    double num, ans;
    int p;
    cout<<"Enter the number : ";
    cin>>num;
    cout<<"enter the power : ";
    cin>>p;
    if(p==0)
        ans=power(num);
    else
        ans=power(num,p);
    cout<<"Power of "<<num<<" = "<<ans<<endl;
}
