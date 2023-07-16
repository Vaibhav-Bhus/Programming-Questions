#include <iostream>
using namespace std;

int main()
{
    int a, b, temp;
    cout<<"Enter Two Numbers : \n";
    cin>>a>>b;

    cout<<"Before swapping."<<endl;
    cout<<"a = "<<a<< ", b = "<<b ;

    temp = a;
    a = b;
    b = temp;

    cout<<"\nAfter swapping."<<endl;
    cout<<"a = "<<a<<", b = "<<b ;
}
