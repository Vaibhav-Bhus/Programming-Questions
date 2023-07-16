#include <iostream>
#define Max 50
using namespace std;


class Sort
{
public:
    int A[Max], n;
    void ReadMatrix()
    {
        cout<<"Enter Total Number Of Element : ";
        cin>>n;
        cout<<"\nEnter Elements Of An Array : ";
        for(int i=0; i<n; i++)
            cin>>A[i];

    }
    void DisplayMatrix()
    {
        for (int i=0; i<n; i++)
            cout<<A[i]<<" ";
    }
    void SortMatrix()
    {
        for (int i=0; i<n-1; i++)
            for (int j=0; j<n-i-1; j++)
                if (A[j] > A[j+1])
                    Swap(&A[j], &A[j+1]);

    }
    void Swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
};
int main()
{
    Sort s;
    s.ReadMatrix();
    s.SortMatrix();
    s.DisplayMatrix();
}
