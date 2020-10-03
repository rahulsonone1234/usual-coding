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


/////////////////////////////////////////////////////////////////////
//uisng two pointers
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int left_max=0;
    int right_max=0;
    
    int l=0;
    int r=n-1;
    
    int res=0;
    
    while(l<=r)
    {
        if(a[l]<a[r])
        {
            if(a[l]>left_max)
            left_max=a[l];
            else
            res+=left_max-a[l];
            
            l++;
        }
        else
        {
            if(a[r]>right_max)
            right_max=a[r];
            else
            res+=right_max-a[r];
            
            r--;
        }
    }
    cout<<res<<endl;
    return 0;
}
