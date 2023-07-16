#include <iostream>
#define Max 50
using namespace std;

class Search
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
    void SearchElement()
    {
        int no;
        cout<<"\n\nEnter Which Number You Want To Search : ";
        cin>>no;
        for (int i=0; i<n; i++)
        {
            if (A[i] == no)
                cout<<no<<" Is Present At Index "<<i+1;
        }
    }

};
int main()
{
    Search s;
    s.ReadMatrix();
    s.DisplayMatrix();
    s.SearchElement();
}
