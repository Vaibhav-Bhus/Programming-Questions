#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,ck=0,a,dk=0,k,ek=0,b,c;
 cin>>n;
 int arr[n];
 for(i=1; i<=n ; i++){
       cin>>arr[i];
 }
 for(i=1; i<=n; i++){
      if(arr[arr[arr[i]]]==i){
        ck++;
      }
 }
 if(ck){
        cout<<"YES"<<endl;
 }
 else{
        cout<<"NO"<<endl;
 }
}
