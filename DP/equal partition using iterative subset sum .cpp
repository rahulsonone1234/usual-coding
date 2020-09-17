#include<bits/stdc++.h>
using namespace std;

int subsetsum(int a[], int n, int sum)
{
    int i,j;
    bool res[n+1][sum+1];
    
    for(i=0;i<n+1;i++)
        res[i][0]=true;
        
    for(j=0;j<sum+1;j++)
        res[0][j]=false;
        
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<sum+1;j++)
        {
            if(a[i]<=j)
                res[i][j]= (res[i-1][j-a[i-1]] || res[i-1][j]);
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
