#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int s;
    cin>>s;
    int l=0;
    int r=n-1;
    while(l<r)
    {
        int mid=(l+(r-l)/2);
        if(a[mid]==s)
        {
            cout<<mid<<endl;
            break;
        }
        else if(a[mid]<s)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if(l>r)
    cout<<"-1"<<endl;
    
return 0;
}
