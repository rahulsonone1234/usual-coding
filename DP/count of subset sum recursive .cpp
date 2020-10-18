#include<bits/stdc++.h>
using namespace std;

int subsetsum(int a[], int n, int sum)
{
    if(sum==0)
    return 1;
    if(n==0)
    return 0;
    
    if(a[n]<=sum)
        return (subsetsum(a, n-1,sum-a[n])+subsetsum(a, n-1, sum));
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
    int sum;
    cin>>sum;
    
    int ans=subsetsum(a, n, sum);
    cout<<"Count of Subsets with given sum : "<<ans<<endl;
    return 0;
}
