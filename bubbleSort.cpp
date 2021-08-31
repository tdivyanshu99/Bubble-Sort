#include<iostream>
using namespace std;

int main(){
    int n,i,j;
    cin>>n;
    int ar[n];
    for(i=0;i<n;i++)
        cin>>ar[i];
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(ar[j]>ar[j+1])
                swap(ar[j],ar[j+1]);
        }
    }
    for(i=0;i<n;i++)
        cout<<ar[i]<<" ";
}

