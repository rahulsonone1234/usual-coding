#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){return (a>b)?a:b;}
int knapsack(int wt[], int val[], int n, int W)
{
    int i,j;
    int res[n+1][W+1];
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0||j==0)
            res[i][j]=0;
            else if(wt[i-1]<=j)
            res[i][j]=max(val[i-1]+res[i-1][j-wt[i-1]], res[i-1][j]);
            else
            res[i][j]=res[i-1][j];
        }
    }
    return res[n][W];
}
int main()
{
    int n;
    cin>>n;
    int wt[n];
    int val[n];
    int W;
    for(int i=0;i<n;i++){cin>>wt[i];}
    for(int i=0;i<n;i++){cin>>val[i];}
    cin>>W;
    cout<<"Max Profit :"<<knapsack(wt, val, n, W)<<endl;
    return 0;
}
