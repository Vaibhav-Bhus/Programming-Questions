#include <iostream>
using namespace std;

int main()
{
    int n, m;
    double factorial = 1.0;

    cout<<"Enter a number : ";
    cin>>n;

    while(n > 0)
    {
        m = n % 10;
        factorial = factorial * m;
        n = n - 1;
    }

    cout<<"Factorial"<<" = "<<factorial;

}
