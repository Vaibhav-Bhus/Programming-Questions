#include <iostream>
#define Max 50
using namespace std;

void ReadMatrix(int arr[Max][Max], int m, int n)
{
    cout<<"Enter Matrix Elements.\n";
    for(int i =0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

}
void DisplayMatrix(int arr[Max][Max], int m, int n)
{
    cout<<"You Have Entered Matrix Elements.\n";
    for(int i =0; i<m; i++)
    {
         for(int j=0; j<n; j++)
         {
             cout<<arr[i][j]<<"\t";
         }
         cout<<endl;
    }
}

int main()
{
    int m, n;
    cout<<"Enter Matrix Size : ";
    cin>>m>>n;
    int arr[Max][Max];
    ReadMatrix(arr, m, n);
    DisplayMatrix(arr, m, n);
}
