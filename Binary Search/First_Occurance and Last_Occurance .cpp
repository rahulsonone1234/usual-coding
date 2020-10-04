#include<bits/stdc++.h>
using namespace std;

int first_occurance(int a[], int n, int s)
{
    int l=0;
    int r=n-1;
    int res=-1;
    while(l<=r)
    {
        int mid=(l+(r-l)/2);
        if(a[mid]==s)
        {
            res=mid;
            r=mid-1;
        }
        else if(a[mid]>s)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return res;
}
int last_occurance(int a[], int n, int s)
{
    int l=0;
    int r=n-1;
    int res=-1;
    while(l<=r)
    {
        int mid=(l+(r-l)/2);
        if(a[mid]==s)
        {
            res=mid;
            l=mid+1;
        }
        else if(a[mid]>s)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return res;
}

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
    cout<<first_occurance(a, n, s)<<endl;
    cout<<last_occurance(a, n, s)<<endl;
    return 0;
}
