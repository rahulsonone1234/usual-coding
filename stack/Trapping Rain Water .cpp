#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int maxl[n];
    maxl[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        maxl[i]=max(maxl[i-1], arr[i]);
    }
    
    int maxr[n];
    maxr[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        maxr[i]=max(maxr[i+1], arr[i]);
    }
    
    int water[n];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        water[i]=(min(maxr[i], maxl[i]) - arr[i]);
        ans+=water[i];
    }
    cout<<ans<<endl;
    return 0;
}
