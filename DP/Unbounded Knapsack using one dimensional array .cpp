#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int W;
    cin>>W;
    
    int res[W+1]={0};
    //memset(res, 0, sizeof res);
    for(int i=0;i<W+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(wt[j]<=i)
            res[i]=max(res[i], res[i-wt[j]] + val[j]);
        }
    }
    cout<<res[W]<<endl;
    
}
