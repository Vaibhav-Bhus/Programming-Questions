#include<iostream>
using namespace std;
bool isPrimeNum(int x)
{
    if(x==1||x==0)
        return false;
    for(int i=2; i<x; i++)
        if(x%i==0)
            return false;
    return true;
}
int main()
{
    int cnt,m,flag=1;
    cin>>m;
    while(m>1)
    {
        cnt=0;
        flag+=1;
        for(int i=1; i<=m; i++)
            if(isPrimeNum(i))
                cnt+=1;
        m=m-cnt;
    }
    cout<<flag;
}
