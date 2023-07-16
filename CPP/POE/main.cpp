#include<iostream>
using namespace std;
#define Max 100

template <class S>
class Small
{
public:
    S Smallest(S arr[], int n)
    {
        S small = arr[0];
        for (int i = 0; i < n; i++)
            if (arr[i] < small)
                small = arr[i];
        return small;
    }
};
int main()
{
    float arr[Max], n;
    Small<float> s;
    cout << "Enter size of the array : ";
    cin >> n;
    cout << "Enter array Elements : \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<<"Smallest Number of present in array is : "<< s.Smallest(arr, n);
    return 0;
}
