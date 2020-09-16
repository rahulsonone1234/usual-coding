#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){return (a>b)?a:b;}

int knapsack(int wt[], int val[], int n, int W)
{
    if(n==0 || W==0)
    return 0;
    
    if(wt[n]>W)
        return knapsack(wt, val, n-1, W);
    else
        return max(val[n]+knapsack(wt, val, n-1, W-wt[n]), knapsack(wt, val, n-1, W));
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
