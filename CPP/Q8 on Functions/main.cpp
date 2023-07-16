#include <iostream>
#include <cmath>
using namespace std;

double SquareRoot(long x)
{
    return(sqrt(x));
}
int main()
{
	long x;

	cout<<"Enter Number To Find Its Square Root : ";
	cin>>x;
	cout<<"Square root of "<<x<<" = "<<SquareRoot(x);

}
