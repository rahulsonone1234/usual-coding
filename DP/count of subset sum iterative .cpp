#include<bits/stdc++.h>
using namespace std;

int subsetsum(int a[], int n, int sum)
{
    int i,j;
    int res[n+1][sum+1];

    for(i=0;i<n+1;i++)
        res[i][0]=1;
        
    for(j=0;j<sum+1;j++)
        res[0][j]=0;
   
        
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<sum+1;j++)
        {
            if(a[i-1]<=j)
                res[i][j]= (res[i-1][j-a[i-1]] + res[i-1][j]);
            else
                res[i][j]=res[i-1][j];
        }
    }
    return res[n][sum];
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
    cout<<"Number of Subsets Present : "<<ans<<endl;
    return 0;
}
