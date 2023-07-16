#include <iostream>
using namespace std;

class Student
{
public:
    int Srollno, Smarks[5];
    char Sname[20];
    float Avg;
    readdata()
    {
        cout<<"Enter Student Name : ";
        cin>>Sname;
        cout<<"Enter Student Roll No. : ";
        cin>>Srollno;
        cout<<"Enter 5 Subject Marks :\n";
        for (int i =0; i < 5; i++)
            cin>>Smarks[i];
    }
    calculateavg()
    {
        int mSum = 0;
        for(int i = 0; i < 5; i++)
            mSum += Smarks[i];
        Avg = mSum / 5;
    }
    displaydata()
    {
        cout<<"\n\nStudent Details:\n";
        cout<<"Student Name : "<< Sname << "\n";
        cout<<"Student Roll No. : "<< Srollno << "\n";
        for (int i =0; i < 5; i++)
            cout<<"Subject 1 Marks = "<<Smarks[i]<<"\n";
        cout<<"Average OF Marks = "<<Avg<<"%";
    }
};
int main()
{
    Student S1;
    S1.readdata();
    S1.calculateavg();
    S1.displaydata();
    return 0;
}
