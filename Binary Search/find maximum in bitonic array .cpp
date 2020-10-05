#include<bits/stdc++.h>
using namespace std;
int fin_max_bitonic(int a[], int low, int high)
{
    if(low==high)
    return a[low];
    
    if((low==high+1)&&a[low]>=a[high])
    return a[low];
    
    if((low==high+1)&&a[low]<a[high])
    return a[high];
    
    int mid=(low+high)/2;
    
    if(a[mid]>a[mid+1] && a[mid]>a[mid-1])
    return a[mid];
    
    if(a[mid]>a[mid+1] && a[mid]<a[mid-1])
    return fin_max_bitonic(a, low, mid-1);
    else
    return fin_max_bitonic(a,mid+1,high);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<fin_max_bitonic(a, 0, n-1)<<endl;
    return 0;
}
