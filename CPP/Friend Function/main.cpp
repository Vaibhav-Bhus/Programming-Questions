#include <iostream>
using namespace std;
class XYZ;

class ABC{
public:
    int A;
    void getNumber1(int a)
    {
        A = a;
    }
    void display()
    {
        cout<<"A = "<<A<<"\n";
    }
    friend void sum(ABC &, XYZ &);
};

class XYZ{
public:
    int X;
    void getNumber2(int b)
    {
        X = b;
    }
    void display()
    {
        cout<<"X = "<<X<<"\n";
    }
    friend void sum(ABC&, XYZ&);
};
void sum(ABC & x, XYZ & y)
{
    int z = x.A + y.X;
    cout<<"Sum of Two Numbers : "<< z<<"\n";
}
int main()
{
        XYZ x;
        ABC a;
        int num1,num2;
        cout<<"Enter A Number For Class ABC And Class XYZ : ";
        cin>>num1>>num2;
        a.getNumber1(num1);
        x.getNumber2(num2);
        a.display();
        x.display();
        sum(a, x);

}
