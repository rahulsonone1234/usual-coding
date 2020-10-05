#include<bits/stdc++.h>
using namespace std;
int peak_element(int a[], int low, int high, int n)
{
    int mid=low+(high-low)/2;
    if((mid==0||a[mid-1]<=a[mid]) && (mid==n-1||a[mid+1]<a[mid]))
    return a[mid];
    
    else if(mid>0 && a[mid-1]> a[mid])
    return peak_element(a, low, mid-1, n);
    
    else
    return peak_element(a, mid+1, high, n);
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
    cout<<peak_element(a, 0, n-1, n)<<endl;
    return 0;
}
