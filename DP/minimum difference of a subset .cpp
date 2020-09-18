#include<bits/stdc++.h>
using namespace std;

int subsetsum(int a[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    bool res[n+1][sum+1];
    
    for(int i=0;i<n+1;i++)
    res[i][0]=true;
    
    for(int j=1;j<sum+1;j++)
    res[0][j]=false;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            res[i][j]=res[i-1][j];
            if(a[i-1]<=j)
                res[i][j]|=res[i-1][j-a[i-1]];
        }
    }
    
    int diff=INT_MAX;
    
    for(int j=sum/2;j>=0;j--)
    {
        if(res[n][j]==true)
        {
            diff=sum-2*j;
            break;
        }
    }
    return diff;
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
    int ans=subsetsum(a, n);
    cout<<"Minimum subset sum : "<<ans<<endl;
    return 0;
}
