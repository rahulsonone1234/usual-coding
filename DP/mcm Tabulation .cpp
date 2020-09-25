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
    int res[n][n];
    
    for(int i=1;i<n;i++)
    res[i][i]=0;
    
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            res[j][j+i]=min(res[j+1][j+i]+a[j-1]*a[j]*a[j+i], res[j][j+i-1]+a[j-1]*a[j+i-1]*a[j+i]);
        }
    }
    cout<<res[1][n-1]<<endl;
    return 0;
}
