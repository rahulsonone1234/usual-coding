#include<bits/stdc++.h>
using namespace std;

int subsetsum(int a[], int n, int sum)
{
    if(sum==0)
    return true;
    if(n==0)
    return false;
    
    if(a[n-1]<=sum)
        return (subsetsum(a, n-1,sum-a[n-1])||subsetsum(a, n-1, sum));
    else
        return subsetsum(a, n-1, sum);
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
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    
    if(sum%2==1)
    {
        cout<<"Not Possible"<<endl;
        return 0;
    }
    else
    {
        if(subsetsum(a, n, sum/2))
        {
            cout<<"Possible"<<endl;
            return 0;
        }
        else
        {
            cout<<"Not Possible"<<endl;
            return 0;
        }
    }
    return 0;
}
