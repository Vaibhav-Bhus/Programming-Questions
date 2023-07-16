#include<iostream>
using namespace std;

int area(int s)
{
    return(s*s);
}
int area(int l,int b)
{
    return(l*b);
}
float area(float r)
{
    return(3.14*r*r);
}
float area(float base,float height)
{
    return((base*height)/2);
}
int main()
{
    int s, l, b, ch;
    float r, base, height;
    do
    {
    cout<<"1.Area of Circle\n2.Area Of Rectangle\n3.Square\n4.Triangle\n5.Exit\nEnter Your Choice  : ";
    cin>>ch;
    switch (ch)
    {
    case 1:
        cout<<"Enter radius of circle : ";
        cin>>r;
        cout<<"Area of circle = "<<area(r)<<"\n\n";
        break;
    case 2:
        cout<<"Enter length and breadth of rectangle : ";
        cin>>l>>b;
        cout<<"Area of rectangle = "<<area(l, b)<<"\n\n";
        break;
    case 3:
        cout<<"Enter side of a square : ";
        cin>>s;
        cout<<"Area of square = "<<area(s)<<"\n\n";
        break;
    case 4:
        cout<<"Enter base and height of triangle : ";
        cin>>base>>height;
        cout<<"Area of triangle = "<<area(base, height)<<"\n\n";
        break;
    case 5:
        exit(1);
    default:
        cout<<"Invalid Choice\n\n";
    }
    }while(ch!=5);
}

