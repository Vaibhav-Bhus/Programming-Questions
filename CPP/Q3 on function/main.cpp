#include <iostream>

using namespace std;

float volume(float r, float pi = 3.14)
{
    float vol;
    vol = 4.00/3.00 * pi * r * r * r;
    return vol;

}


int main()
{
    float radius;
    cout<<"Enter  Radius Of a Circle : ";
    cin>>radius;

    cout << "Volume Of Sphere : " << volume(radius);

}
