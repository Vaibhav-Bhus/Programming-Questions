#include <iostream>

using namespace std;
class Time
{
public:
    int hr, Min;
    Time()
    {
        cout<<"Enter Time in Hours And Minutes : ";
        cin>>hr>>Min;
    }
    void puttime()
    {
        cout<<hr<<" Hours and "<<Min<<" Min"<<endl;
    }
    void Sum(Time, Time);

};

void Time::Sum(Time t1, Time t2)
{
    Min = t1.Min + t2.Min;
    hr = Min/60;
    Min = Min % 60;
    hr = hr + t1.hr + t2.hr;
}

int main()
{
    Time T1, T2;
    cout<<"T1 = ";
    T1.puttime();
    cout<<"T2 = ";
    T2.puttime();
    T2.Sum(T1, T2);
    cout<<"Sum of T1 And T2 = ";
    T2.puttime();
    return 0;
}
